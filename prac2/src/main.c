
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

int main (){
	//leon3_putchar('p');
	//leon3_putchar('2');
	//leon3_putchar('\n');
	int i = 0;
	char aux = '0';
	for (i = 0; i < 10; i++){
		leon3_putchar (aux); leon3_putchar ('\n');
		aux++;
	}

	while (leon3_uart_tx_fifo_is_empty == 0);

	printf ("\n fin del porgrama \n");
	return 0;
}
