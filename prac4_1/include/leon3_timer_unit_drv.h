


#ifndef LEON3_TIMER_UNIT_DRV_H_
#define LEON3_TIMER_UNIT_DRV_H_

#include "leon3_types.h"

/** \brief Set Timer Unit configuration.
 *
 *	\param scalerValue value for the scaler
 *
 *	\param timer_freeze_during_debug Configure with true if Timer Unit is freeze during debug
 *
 *	\param separate_interrupts Configure with true if Timer Unit generates separate interrupts
 *	for each timer
 *
 */
void leon3_timerunit_set_configuration(uint32_t scalerValue
									, bool_t freeze_during_debug
									, bool_t separate_interrupts );


/** \brief Configure Timer
 *
 *	\param timerId timer identifier, it can be 0 or 1.
 *
 *	\param timerValue value of the timer
 *
 *	\param chain_with_prec_timer configure to true if timer input comes from the precedent timer
 *
 *	\param restart_timer configure to true if time is restarted after underflow
 *
 */

void leon3_timer_config(uint8_t timerId
					, uint32_t timerValue
					, bool_t chain_with_prec_timer
					, bool_t restart_timer);


/** \brief Enable the IRQ associated to a Timer underflow
 *
 *	\param timerId timer identifier, it can be 0 or 1.
 *
 */

uint8_t leon3_timer_enable_irq(uint8_t timerId);

/** \brief Disable the IRQ associated to a Timer underflow
 *
 *	\param timerId timer identifier, it can be 0 or 1.
 *
 */
uint8_t leon3_timer_disable_irq(uint8_t timerId);


/** \brief Enable a Timer
 *
 *	\param timerId timer identifier, it can be 0 or 1.
 *
 */
uint8_t leon3_timer_enable(uint8_t timerId);

/** \brief Enable a Timer
 *
 *	\param timerId timer identifier, it can be 0 or 1.
 *
 */
uint8_t leon3_timer_disable(uint8_t timerId);

/** \brief Enable a Timer
 *
 *	\param timerId timer identifier, it can be 0 or 1.
 *
 */

uint8_t leon3_timer_clear_irq(uint8_t timerId);





#endif /* LEON3_TIMER_UNIT_DRV_H_ */

