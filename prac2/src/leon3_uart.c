#include <stdio.h>
#include "../include/leon3_types.h"

typedef struct UART_regs{
	volatile uint32_t Data;  //0x80000100
	volatile uint32_t Status;	 //0x80000104
	volatile uint32_t Ctrl;  //0x80000108     0x10B = 3 (0000 0011)
	volatile uint32_t Scaler;    //0x8000010C
};

// TFF es el bit indice 9. Va a ctuar de máscara para este bit 9.
//Enascarar es que NO sea visible, se puede hacer una AND con esa posicion de memoria.
#define LEON3_UART_TFF(a) a=a*0

//TFE es el bit indice 2
#define LEON3_UART_TFE(a) a=a*0

struct UART_regs * const pLEON3_UART_REGS = (struct UART_regs *) 0x80000100;

#define leon3_UART_TF_IS_FULL() (pLEON3_UART_REGS->Status <512? 0 : 1)

int8_t leon3_putchar (char c){
	uint32_t write_timeout = 0;
	while (leon3_UART_TF_IS_FULL() && (write_timeout < 0xAAAAA)){
		write_timeout++;
	} //espera mientras la cola de trasmision esta llena.
	if (write_timeout < 0xAAAAA){
		pLEON3_UART_REGS->Data = c;
	}
	return write_timeout == 0xAAAAA;
}
int8_t leon3_uart_tx_fifo_is_empty (){
	uint8_t variable = 0;
	uint8_t miStatus = 0;
	miStatus = pLEON3_UART_REGS-> Status;
	while (miStatus >= 8){
		miStatus = miStatus - 8;
	}
	int j = 0;
	while (j < 2){
		j++;
		miStatus = miStatus / 2;
	}
	return variable;
}



