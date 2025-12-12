/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>

int main(void)
{
	/* Use both printk and printf for testing */
	printk("=== PRINTK: Board starting ===\n");
	printf("=== PRINTF: Board starting ===\n");
	fflush(stdout);
	
	/* Wait for USB enumeration and console to be ready */
	k_sleep(K_MSEC(3000));

	printk("Hello from USB CDC-ACM (PRINTK)!\n");
	printf("Hello from USB CDC-ACM (PRINTF)!\n");
	fflush(stdout);
	
	k_sleep(K_MSEC(500));
	
	int counter = 0;
	while (1) {
		k_sleep(K_SECONDS(2));
		printk("Loop %d (printk)\n", counter);
		printf("Loop %d (printf)\n", counter);
		fflush(stdout);
		counter++;
	}

	return 0;
}
