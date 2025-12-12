/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/uart.h>

#define UART_NODE DT_CHOSEN(zephyr_console)

const struct device *const uart_dev = DEVICE_DT_GET(UART_NODE);

#define SLEEP_TIME_MS 3000

int main(void)
{
	const char *message = "Message from lpUART\n";
	
	if (!device_is_ready(uart_dev)) {
		return 0;
	}

	while(1) {
		/* Send each character of the message */
		for (int i = 0; message[i] != '\0'; i++) {
			uart_poll_out(uart_dev, message[i]);
		}
		
		/* Wait a bit */
		k_msleep(SLEEP_TIME_MS);
	}
	
	return 0;
}
