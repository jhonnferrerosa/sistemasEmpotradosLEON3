//-+-+-+-+-+-+-+TEORIA-++-+-+-+-+-+-+-+-+-+-+-+-+-+
//1-


//-+-+-+-+-+-+-+TEORIA-++-+-+-+-+-+-+-+-+-+-+-+-+-+



#include "../include/leon3_uart.h"
#include "../include/leon3_bprint.h"
#include "../include/leon3_ev_handling.h"
#include "../include/leon3_hw_irqs.h"

#include <stdio.h>

void device_hw_irq_level_1_handler (){
	leon3_print_string ("+ Device HW IRQ user handler \n");
}

int main (){
	//device_hw_irq_level_1_handler ();

	//instalar como manejador del trap 0x83 la rutina que habilita las interrupciones.
	//jhon: lo que hace la funcion por parametro que se le pasa,que es un codido asm,
	//es que fija el PIL a 0. Priority Interrupt level.
	leon3_set_trap_handler (0x83, leon3_trap_handler_enable_irqs);

	//instalar el manejador del trap que 0x84 la rutina que deshabilita las interrupciones.
	leon3_set_trap_handler (0x84, leon3_trap_handler_disable_irqs);

	//llamada al sistema para deshabilitar las interupciones.
	leon3_sys_call_disable_irqs ();

	//completar...
	//enmascarar todas las interrpuciones.
	leon3_mask_all_irqs();

	//instalar la funcion device_hw_irq_level_1_handler como manejador de usuario de la  interrupcion de nivel 1.
	uint32_t miReturn = 777;
	miReturn = leon3_install_user_hw_irq_handler (1, device_hw_irq_level_1_handler);

	//desenmascarar la interrupcion de nivel 1.
	uint8_t miReturnLeon3_unmask_irq = 7;
	miReturnLeon3_unmask_irq = leon3_unmask_irq (1);

	// llamada al sistema para habilitar las interrupciones.
	//jhon: esto es el codigo de usuario, para llamar las rutinas que se ejecutan en modo supervisor.
	leon3_sys_call_enable_irqs();

//
// También dice que primero hay que forzar sin enmascarar	
//
	
	//jhon: enunciado dice: enmascarar antes de forzar la interrupcion, para ver que no sale nada.
	uint8_t miReturnLeon3_mask_irq = 7;
	//miReturnLeon3_mask_irq = leon3_mask_irq (1);

	//fuerza la interrupcion.
	leon3_force_irq (1);

	//fin del completar.
	return 0;
}

