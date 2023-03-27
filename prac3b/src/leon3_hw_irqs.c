/*
 * leon3_hw_irqs.c
 *
 *  Created on: 24/03/2023
 *      Author: atcsol
 */

#include "../include/leon3_types.h"

//Utilizad estos punteros para acceder a los registros
uint32_t * LEON3_IFORCE =  (uint32_t *) (0x80000000 + 0x208); //jhon: forzar interrupciones.
uint32_t * LEON3_ICLEAR =  (uint32_t *) (0x80000000 + 0x20C); //jhon: borrar interrupciones pendientes.
uint32_t * LEON3_IMASK =  (uint32_t *) (0x80000000 + 0x240); //jhon: enmascarar interrupciones pendientes.

/** Pone a uno el bit correspondiente al irq level para hacer el clear de la pending irq .*/
/** Set bit of the irq level to clear the pending irq .*/
//jhon: Rutina que borra una interrupción externa pendiente cuyo nivel se pasa por parámetro.
uint8_t leon3_clear_irq (uint8_t irq_level) {
	uint8_t error=0;
	if((irq_level >0) && (irq_level <16)){
		uint32_t bit = (1 << irq_level); // Mask irq level to clear
		*LEON3_ICLEAR = bit;	//Sets that bit to 1
	}else
		error=1;
	return error;
}

/** Pone a 1 el bit del irq_level correspondiente al registro IFORCE
 * forzando la interrupción del irq_level indicado.*/
//jhon: //Rutina que fuerza una interrupción externa cuyo nivel se pasa por parámetro.
uint8_t leon3_force_irq (uint8_t irq_level) {
	uint8_t error=0;
	if((irq_level >0) && (irq_level <16)){
		// COMPLETADhecho. Poniendo a 1 SOLO el bit de LEON3_IFORCE correspondiente al irq_level
		uint32_t bit = (1 << irq_level);
		*LEON3_IFORCE = bit;
	}else
		error=1;
	return error;
}

/** Pone a 1 el bit del irq_level indicado en el registro de mascara,
 * desenmascarando dicha interrupcion. irq_level(0-15).*/
//jhon: Rutina que desenmascara una interrupción externa cuyo nivel se pasa por parámetro.
uint8_t leon3_unmask_irq (uint8_t irq_level){
	uint8_t error=0;
	if((irq_level >0) && (irq_level <16)){
		// clear any pending irq of that level
		leon3_clear_irq(irq_level);
		// COMPLETADhecho Poniendo a 1 SOLO el bit de LEON3_IMASK correspondiente al irq_level
		*LEON3_IMASK = 0;
		uint32_t bit = (1 << irq_level);
		*LEON3_IMASK = bit;
	}else
		error=1;
	return error;
}

/** Pone a 0 el bit del irq_level indicado en el registro de mascara,
 * enmascarando dicha interrupción. irq_level(1-15)*/
//jhon: Rutina que enmascara la interrupción externa cuyo nivel se pasa por parámetro.
uint8_t leon3_mask_irq (uint8_t irq_level) {
	uint8_t error=0;
	if(irq_level >0 && irq_level <16){
		// COMPLETADhecho  Poniendo a 0 SOLO el bit de LEON3_IMASK correspondiente al irq_level
		*LEON3_IMASK  = 0xFFFE;
		uint32_t bit = (1 << irq_level);
		bit = bit ^ 0xffff;
		*LEON3_IMASK = bit;
	}else
		error=1;
	return error;
}

/** Pone a 1 todos los bits del registro de mascara, desenmascarando todas las interrupciones externas*/
//jhon: Rutina que enmascara todas las interrupciones externas
void leon3_unmask_all_irqs(){
	*LEON3_IMASK=0xFFFE;
}

/** Pone a 0 todos los bits del registro de mascara, enmascarando todas las interrupciones externas*/
//jhon: Rutina que enmascara todas las interrupciones externas
void leon3_mask_all_irqs(){

	*LEON3_IMASK=0;
}

