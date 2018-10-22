/*
 * Copyright (c) 2018 MicroFPGA UG
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <arch/cpu.h>
#include <uart.h>
#include <sys_io.h>
#include <board.h>

#define DEV_CFG(dev)					\
	((const struct uart_device_config * const)	\
	 (dev)->config->config_info)

static unsigned char uart_ev_poll_out(struct device *dev,
					      unsigned char c)
{
	sys_write8(c, DEV_CFG(dev)->regs);
	return c;
}

static int uart_ev_poll_in(struct device *dev, unsigned char *c)
{
	*c = sys_read8(DEV_CFG(dev)->regs);	
	return 0;
}

static int uart_ev_init(struct device *dev)
{
	/* Nothing to do */

	return 0;
}


static const struct uart_driver_api uart_ev_driver_api = {
	.poll_in = uart_ev_poll_in,
	.poll_out = uart_ev_poll_out,
	.err_check = NULL,
};

static const struct uart_device_config uart_ev_dev_cfg_0 = {
	.regs = RISCV_EV_UART_BASE,
};

DEVICE_AND_API_INIT(uart_ev_0, "uart0",
//DEVICE_AND_API_INIT(uart_ev_0, "CONFIG_UART_EV_PORT_0_NAME",
		    uart_ev_init, NULL,
		    &uart_ev_dev_cfg_0,
		    PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
		    (void *)&uart_ev_driver_api);

//DEVICE_AND_API_INIT(uart_miv_0, CONFIG_UART_MIV_PORT_0_NAME,
//		    uart_miv_init, &uart_miv_data_0, 
//                  &uart_miv_dev_cfg_0,
//		    PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
//		    (void *)&uart_miv_driver_api);


