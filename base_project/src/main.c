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
	printk("=== Starting Tracker ===\n");
	
	/* Wait for USB enumeration and console to be ready */
	k_sleep(K_MSEC(3000));


	return 0;
}
