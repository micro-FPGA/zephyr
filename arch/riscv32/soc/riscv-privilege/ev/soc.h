#ifndef __RISCV32_EV_SOC_H_
#define __RISCV32_EV_SOC_H_

#include <soc_common.h>

/* UART Configuration */
#define RISCV_EV_UART_BASE           0xC000


/* Timer configuration */
#define RISCV_MTIME_BASE             0xE000
#define RISCV_MTIMECMP_BASE          0xD000

/* lib-c hooks required RAM defined variables */
#define RISCV_RAM_BASE               CONFIG_RISCV_RAM_BASE_ADDR
#define RISCV_RAM_SIZE               CONFIG_RISCV_RAM_SIZE

#endif /* __RISCV32_EV_SOC_H_ */
