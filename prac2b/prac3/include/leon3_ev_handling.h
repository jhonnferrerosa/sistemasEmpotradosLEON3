/*
 * leon3_ev_handling.h
 *
 *  Created on: 24/03/2023
 *      Author: atcsol
 */


#ifndef TRAPS_H_
#define TRAPS_H_

#define VERBOSE_TRAP_HANDLER

#include "leon3_types.h"


// Public functions

//Rutina que instala un manejador de usuario una interrupción hardware
int32_t leon3_install_user_hw_irq_handler(uint32_t hw_irq_number, void (* handl_routine) (void));

//Rutina que instala un manejador de un evento fijando
int32_t leon3_set_trap_handler(uint32_t hw_irq_number, void (* handl_routine) (void));

//Rutina de atención al trap que habilita las interrupciones.
void leon3_trap_handler_enable_irqs(void);

//Rutina de atención al trap que deshabilita las interrupciones.
void leon3_trap_handler_disable_irqs(void);

//Llamada al sistema para habilitar interrupciones.
void leon3_sys_call_enable_irqs(void);

//Llamada al sistema para deshabilitar interrupciones.
void leon3_sys_call_disable_irqs(void);

//Rutina de sistema que gestiona las interrupciones.
void leon3_sparc_isr(void);


// Error list

#define LEON3_ERR_SUCCESS             0
#define LEON3_ERR_TRAP_HANDLER       -1
#define LEON3_ERR_INIT               -2
#define LEON3_ERR_HW_IRQ_HANDLER	 -3


#define LEON3_SPARC_DIV_0_TRAPVECTOR   	 	0x82
#define LEON3_SPARC_ENABLE_IRQ_TRAPVECTOR   0x83
#define LEON3_SPARC_DISABLE_IRQ_TRAPVECTOR  0x84



#endif /* TRAPS_H_ */

