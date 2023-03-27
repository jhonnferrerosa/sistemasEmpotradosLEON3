
#include "../include/leon3_uart.h"
#include "../include/leon3_bprint.h"
#include "../include/leon3_ev_handling.h"
#include "../include/leon3_hw_irqs.h"

uint8_t irq_counter = 0;
char RxChars[8];

//esta funcion se utilizara como manejador de la interrupcion que genera la recepcion
//de un dato por el puerto serie. La funcion almacena en RXChars los 8 primeros
//caracteres que se reciven, reenviando, ademas el sucesor por el mismo canal TX.

void uart_rx_irq_handler (void ){
	char aux;
	aux = leon3_getchar ();
	if (irq_counter < 8){
		RxChars[irq_counter] = aux;
		aux++;
		leon3_putchar (aux);
	}
	irq_counter++;
}

int main (){
	uint8_t i;

	//instalar como manejador del trap 0x83, la rutina que habilita las interrupciones.
	leon3_set_trap_handler (0x83, leon3_trap_handler_enable_irqs);

	//instalar el majejador del trap 0x84, la rutina que sehabilita las interrupciones.
	leon3_set_trap_handler (0x84, leon3_trap_handler_disable_irqs);

	//llamada al sistema que deshabilita las interrupiones.
	leon3_sys_call_disable_irqs ();

	//COMPLETAR instalando como manejador de la interrpocion de nivel 2, la rutina
	//uart_rx_irq_handler, siguiendo el mismo patron que la prac3.
	uint32_t miReturn = 777;
	miReturn = leon3_install_user_hw_irq_handler (2,uart_rx_irq_handler);

	//FIN COMPLETAR.

	//habilito loop-back.
	leon3_uart_ctrl_config_rxtx_loop (1);

	//habilito interrupcion de recepcion por la UART.
	leon3_uart_ctrl_rx_irq_enable ();

	//habililto la recepcion por la UART.
	leon3_uart_ctrl_rx_enable ();

	//COMPLETAR. habilito las interrupciones y desenmascaro la interrupcion de nivel 2.
	leon3_sys_call_enable_irqs ();
	leon3_unmask_irq (2);
	//FIN COMPLETAR.
	leon3_putchar ('A');

	//sondeo si los 8 caracteres, se han recibido.
	while (irq_counter < 8);

	//tras recibir los 8 caracteres, configuro la UART, sin loop-back.
	leon3_uart_ctrl_config_rxtx_loop (0);

	//envio los 8 caracteres que se recibieron, pero sin loop-back. para que aparezcan
	//por pantalla.

	for (i = 0; i < 8; i++){
		leon3_putchar (RxChars[i]);
	}
	leon3_putchar ('\n');

	//espero a que todos los caracteres, se hayan enviado.
	while (!leon3_uart_tx_fifo_is_empty());


	return 0;
}
