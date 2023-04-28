#include "../include/leon3_types.h"
#include "../include/leon3_uart.h"

int8_t leon3_print_string (char * str){
	int8_t error = 0;
	while (*str != NULL){
		error = leon3_putchar (* str);
		str = str + 1;
	}
	//error = leon3_putchar ('\n');
	while (!leon3_uart_tx_fifo_is_empty);
	return error;
}
int8_t leon3_print_uint8 (uint8_t i){
	int8_t error = 0;
	int8_t first_digit = 1; //evita ceros a la izquierda.
	uint8_t aux = 100; //numero auxiiar para extraer digitos

	if (i == 0){  //si el numero es 0, transmitir un único digito
		error = leon3_putchar ('0');
	}else{  // si no es un 0, transmitir digito a digito.
		while (aux && (error != 1)){
				uint8_t digit;
				digit = i / aux;  // extrae el digito mas significativo
				i = i - aux*digit; // numero con el resto de digitos
				aux = aux / 10; //centenas->decenas->unidades.

				//si ya hs transmitido el primer digito o
				// el figito extraido es != 0
				// transmitir el caracter digito
				if ( (0 == first_digit) || digit ){
					error = leon3_putchar ('0'+digit);
					first_digit = 0;  //ya se imprime
				}
		}
	}
	//espera a que la cola fifo de transmision se vacie
	while (!leon3_uart_tx_fifo_is_empty);
	return error;
}
int8_t leon3_print_uint16 (uint16_t i){
	int8_t error = 0;
	int8_t first_digit = 1;
	uint16_t aux = 10000;

	if (i == 0){
		error = leon3_putchar ('0');
	}else{
		while (aux && (error != 1)){
			uint8_t digit;
			digit = i /aux;
			i = i - aux*digit;
			aux = aux / 10;

			if ( (first_digit == 0) || (digit) ){
				error = leon3_putchar ('0'+digit);
				first_digit = 0;
			}
		}
	}
	while (!leon3_uart_tx_fifo_is_empty);
	return error;
}

int8_t leon3_print_uint32 (uint32_t i){
	int8_t error = 0;
	int8_t first_digit = 1;
	uint32_t aux = 1000000000;
	if (i == 0){
		error = leon3_putchar ('0');
	}else{
		while (aux && (error != 1)){
			uint8_t digit;
			digit = i /aux;
			i = i - aux*digit;
			aux = aux / 10;
			if ((first_digit == 0) || (digit)){
				error = leon3_putchar ('0'+digit);
				first_digit = 0;
			}
		}
	}
	while (!leon3_uart_tx_fifo_is_empty);
	return error;
}

