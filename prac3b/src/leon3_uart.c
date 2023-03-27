
#include "../include/leon3_types.h"
typedef struct UART_regs{
	volatile uint32_t Data;  //0x80000100
	volatile uint32_t Status;	 //0x80000104
	volatile uint32_t Ctrl;  //0x80000108     0x10B = 3 (0000 0011)
	volatile uint32_t Scaler;    //0x8000010C
};
// TFF es el bit indice 9. Va a ctuar de máscara para este bit 9.
//Enascarar es que NO sea visible, se puede hacer una AND con esa posicion de memoria.
#define LEON3_UART_TFF 0x200
//TFE es el bit indice 2
#define LEON3_UART_TFE 0x004
struct UART_regs * const pLEON3_UART_REGS = (struct UART_regs *) 0x80000100;
#define leon3_UART_TF_IS_FULL() (LEON3_UART_TFF & pLEON3_UART_REGS->Status)
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
	uint8_t miStatus = 0;
	miStatus = LEON3_UART_TFE & pLEON3_UART_REGS->Status;
	return miStatus;
}

char leon3_getchar(){
	char miCaracter = pLEON3_UART_REGS->Data;
	return miCaracter;
}
void leon3_uart_ctrl_rx_enable (){
	pLEON3_UART_REGS->Ctrl = pLEON3_UART_REGS->Ctrl | 0x01;
}
void leon3_uart_ctrl_rx_irq_enable (){
	pLEON3_UART_REGS->Ctrl = pLEON3_UART_REGS->Ctrl | 0x04;
}
void leon3_uart_ctrl_config_rxtx_loop (uint8_t set_rxtxloop){ //es el bit indice 7, (7).
	if (set_rxtxloop == 1){
		pLEON3_UART_REGS->Ctrl = pLEON3_UART_REGS->Ctrl | 0x80;
	}else{
		if ( (pLEON3_UART_REGS->Ctrl & 0x80) == 0){
			//en caso de que el bit loopBack ya este a 0, no se hace nada.
			uint8_t noSeUsaVariable = 0;
		}else{
			pLEON3_UART_REGS->Ctrl = pLEON3_UART_REGS->Ctrl ^ 0x80;
		}
	}
}



