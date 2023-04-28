

#ifndef IRQS_H_
#define IRQS_H_

#include "leon3_types.h"

//Rutina que enmascara la interrupción externa cuyo nivel se pasa por parámetro.
uint8_t leon3_mask_irq (uint8_t irq_level);

//Rutina que desenmascara una interrupción externa cuyo nivel se pasa por parámetro.
uint8_t leon3_unmask_irq (uint8_t irq_level);

//Rutina que enmascara todas las interrupciones externas
void leon3_mask_all_irqs();

//Rutina que enmascara todas las interrupciones externas
void leon3_unmask_all_irqs();


//Rutina que fuerza una interrupción externa cuyo nivel se pasa por parámetro.
uint8_t leon3_force_irq (uint8_t irq_level);

//Rutina que borra una interrupción externa pendiente cuyo nivel se pasa por parámetro.
uint8_t leon3_clear_irq (uint8_t irq_level);


#endif
