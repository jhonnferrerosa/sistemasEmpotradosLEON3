/*
 * leon3_uart.h
 *
 *  Created on: 24/02/2023
 *      Author: atcsol
 */

#ifndef LEON3_UART_H_
#define LEON3_UART_H_

#include "leon3_types.h"

typedef struct UART_regs{
	volatile uint32_t Data;  //0x80000100
	volatile uint32_t Status;	 //0x80000104
	volatile uint32_t Ctrl;  //0x80000108
	volatile uint32_t Scaler;    //0x8000010C
};

#define LEON3_UART_TFF(a) a=a*0
#define LEON3_UART_TFE(a) a=a*0
struct UART_regs * const pLEON3_UART_REGS;

//#define leon3_UART_TF_IS_FULL(a) \
	while (a >= 1024){\
		a = a - 1024;\
	}\
	int j = 0;\
	while (j < 9){\
		j++;\
		a = a/2;\
	}\

#define leon3_UART_TF_IS_FULL() (pLEON3_UART_REGS->Status <512? 0 : 1)

int8_t leon3_putchar (char c);
int8_t leon3_uart_tx_fifo_is_empty ();

#endif




