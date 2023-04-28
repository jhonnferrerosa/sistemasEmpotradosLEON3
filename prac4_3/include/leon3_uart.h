#ifndef LEON3_UART_H_
#define LEON3_UART_H_
#include "leon3_types.h"

#define LEON3_UART_TFF 0x200
#define LEON3_UART_TFE 0x004
struct UART_regs * const pLEON3_UART_REGS;
#define leon3_UART_TF_IS_FULL() (pLEON3_UART_REGS->Status <512? 0 : 1)
int8_t leon3_putchar (char c);
int8_t leon3_uart_tx_fifo_is_empty ();
char leon3_getchar ();

void leon3_uart_ctrl_rx_enable ();
void leon3_uart_ctrl_rx_irq_enable ();
void leon3_uart_ctrl_config_rxtx_loop (uint8_t set_rxtxloop);
#endif


