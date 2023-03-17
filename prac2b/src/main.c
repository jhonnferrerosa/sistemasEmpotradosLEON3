
//   -+-+-+-+-+-+-+ preguntas del PDF.  --+-+-+-+-+-+-+-+-+-+-
// ¿debe acceder el dispisitivo en modo bloque o modo caracter? Respuesta: modo caracter.
// ¿debe el driver poder utiizarse por mas de un hilo/proceso?
// ¿las operaciones sobre el dispositivo implican espera aciva o se emplean buffers controlados por interrpuciones para evitar este blqueo? Respuesta: emplea espera activa.


//	volatile uint8_t valor = 69;    --EJEMPLO DE COMO SE LE ASIGNA UN VALOR A UN PUNTERO.
//	volatile uint8_t *pValor = &valor;
//LEON3_UART_TFF(*pValor);  --ejemplo de uso de macro, que enmascara.
//	*pValor = 255;

//   -+-+-+-+-+-+-+ preguntas del PDF.  --+-+-+-+-+-+-+-+-+-+-

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/leon3_uart.h"
#include "../include/leon3_bprint.h"

int main (){

	//leon3_putchar ('p');
	//leon3_print_uint8(103);
	//leon3_putchar ('\n');
	//leon3_print_uint16(12345);
	char * pChar = "cadena\n";
	leon3_print_string (pChar);
	leon3_putchar ('\n');

	// si no se queda pillado en este while, significa que el bit
	// indice 2 (2), esta a uno, en algun momento.
	//while (!leon3_uart_tx_fifo_is_empty);

	printf ("\n fin del porgrama \n");
	return 0;
}


