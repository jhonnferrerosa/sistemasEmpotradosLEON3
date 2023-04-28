#include "../include/leon3_types.h"
#include "../include/leon3_uart.h"
/** \brief structure for controlling Timer Registers */
struct Timer_regs_t{

	/** \brief Timer Counter Value Register */
	volatile uint32_t CounterValue;

	/** \brief Timer Reload Value Register */
	volatile uint32_t ReloadValue;

	/** \brief Timer Control Register */
	volatile uint32_t Ctrl;

	volatile uint32_t reserved;

};

//  Número de Timers integrados en la Timer Unit
//! LEON3 Timers integrated in the Timer Unit
#define LEON3_TIMER_UNIT_TIMERS 					2

//***************************************************************************************
//! LEON3 Timer Unit Masks
#define LEON3_TIMER_UNIT_DISABLE_FREEZE (0x200)
#define LEON3_TIMER_UNIT_SEPARATE_IRQS (0x100)

//***************************************************************************************
//! LEON3 Timer Ctrl Masks
#define LEON3_TIMER_CHAIN_WITH_PREC_TIMER 	(0x020)
#define LEON3_TIMER_CLEAR_IRQ 				(0x010)
#define LEON3_TIMER_ENABLE_IRQ 				(0x008)
#define LEON3_TIMER_LOAD_TIMER 				(0x004)
#define LEON3_TIMER_RESTART 				(0x002)
#define LEON3_TIMER_ENABLE 					(0x001)


//***************************************************************************************

/** \brief structure for controlling Timer Unit Registers */

struct TimerUnit_regs_t
{

	/** \brief Timer Unit Scaler Register */
	volatile uint32_t ScalerValue;			/* 0x80000300 */
	/** \brief Timer Unit Scaler Reload Value Register */
	volatile uint32_t ScalerReloadValue; 	/* 0x80000304 */
	/** \brief Timer Unit Configuration Register */
	volatile uint32_t ConfigReg; 			/* 0x80000308 */

	uint32_t 		 reserved; 				/* 0x8000030A */

	/** \brief Registers of the Timers*/		//Valor que define cuantos timers hay
	volatile struct Timer_regs_t			Timer[LEON3_TIMER_UNIT_TIMERS];

};


//***************************************************************************************
//! LEON3 Timing Unit
struct TimerUnit_regs_t *pLEON3_TimerUnit_REGS = (struct TimerUnit_regs_t *)0x80000300;



//***************************************************************************************

void leon3_timerunit_set_configuration( uint32_t scalerValue
									, bool_t timer_freeze_during_debug
									, bool_t separate_interrupts ){

	//Configura el campo  disable_timer_freeze del registro ConfigReg de la Timer Unit
	//Configure the field disable_timer_freeze of Timer Unit ConfigReg
	if(timer_freeze_during_debug)
		pLEON3_TimerUnit_REGS->ConfigReg&=(~LEON3_TIMER_UNIT_DISABLE_FREEZE);
	else
		pLEON3_TimerUnit_REGS->ConfigReg|=LEON3_TIMER_UNIT_DISABLE_FREEZE;

     //Configura el campo  separate_interrupts del registro ConfigReg de la Timer Unit
	//Configure the field separate_interrupts of Timer Unit ConfigReg
	if(separate_interrupts)
		pLEON3_TimerUnit_REGS->ConfigReg|=LEON3_TIMER_UNIT_SEPARATE_IRQS;
	else
		pLEON3_TimerUnit_REGS->ConfigReg&=(~LEON3_TIMER_UNIT_SEPARATE_IRQS);
	//Configura el valor de Scaler Reload
	pLEON3_TimerUnit_REGS->ScalerReloadValue=scalerValue;
	//Configura el valor del Scaler
	pLEON3_TimerUnit_REGS->ScalerValue=scalerValue;

}


//***************************************************************************************

uint8_t leon3_timer_config(uint8_t timerId   // esta funcion,no usa timerValue?? .
					, uint32_t timerValue
					, bool_t chain_with_prec_timer
					, bool_t restart_timer){
	uint8_t error=0;
	//Timer[0] -> Select Timer 1
	//Timer[1] -> Select Timer 2
	if(timerId < LEON3_TIMER_UNIT_TIMERS ){
		pLEON3_TimerUnit_REGS->Timer[timerId].ReloadValue = timerValue;
		//TODO
		//Configurar el campo chain_with_prec_timer del timerId (sin cambiar el resto de campos de Ctrl) que fija el encadenamiento  con el timer anterior
		//Usa las máscaras definidas en LEON3 Timer Ctrl Masks
		if (chain_with_prec_timer){
			pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl = pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl | LEON3_TIMER_CHAIN_WITH_PREC_TIMER;
		}else{
			pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl = pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl & (~LEON3_TIMER_CHAIN_WITH_PREC_TIMER);
		}
		//TODO
		//Configura el campo Restart del timerId (sin cambiar el resto de campos de Ctrl) que determina si debe reiniciarse el timer tras el underflow
		//Usa las máscaras definidas en LEON3 Timer Ctrl Masks
		if (restart_timer){
			pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl = pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl | LEON3_TIMER_RESTART;
		}else{
			pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl = pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl & (~LEON3_TIMER_RESTART);
		}
		// Fuerza la carga en CounterValue del timerId con el valor escrito en el registro ReloadValue
		pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl|=LEON3_TIMER_LOAD_TIMER;

	}else
		error=1;

	return error;

}

//***************************************************************************************
uint8_t leon3_timer_enable_irq(uint8_t timerId){
	uint8_t error=0;
	if(timerId < LEON3_TIMER_UNIT_TIMERS ){
		//TODO
		//Habilitar las interrupciones del timerId sin cambiar el resto de campos de Ctrl
		//Usa las máscaras definidas en LEON3 Timer Ctrl Masks
		pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl = pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl | LEON3_TIMER_ENABLE_IRQ;
	}else
		error=1;

	return error;
}
//***************************************************************************************

uint8_t leon3_timer_disable_irq(uint8_t timerId){
	uint8_t error=0;
	if(timerId < LEON3_TIMER_UNIT_TIMERS ){
		//TODO
		//Deshabilitar las interrupciones el timerId sin cambiar el resto de campos de Ctrl
		//Usa las máscaras definidas en LEON3 Timer Ctrl Masks
		pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl = pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl & (~LEON3_TIMER_ENABLE_IRQ);
	}else
		error=1;
	return error;
}
//***************************************************************************************
uint8_t leon3_timer_enable(uint8_t timerId){
	uint8_t error=0;
	if(timerId < LEON3_TIMER_UNIT_TIMERS ){
		//TODO
		//Habilitar el timerId sin cambiar el resto de campos de Ctrl
		//Usa las máscaras definidas en LEON3 Timer Ctrl Masks
		pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl = pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl | LEON3_TIMER_ENABLE;
	}else
		error=1;
	return error;
}
//***************************************************************************************
uint8_t leon3_timer_disable(uint8_t timerId){
	uint8_t error=0;
	if(timerId < LEON3_TIMER_UNIT_TIMERS ){
		//TODO
		//Deshabilitar el timerId sin cambiar el resto de campos de Ctrl
		//Usa las máscaras definidas en LEON3 Timer Ctrl Masks
		pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl = pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl & (~LEON3_TIMER_ENABLE);
	}else
		error=1;
	return error;
}
//***************************************************************************************
uint8_t leon3_timer_clear_irq(uint8_t timerId){
	uint8_t error=0;
	if(timerId < LEON3_TIMER_UNIT_TIMERS ){
		//TODO
		//Escribir un 0 en el campo Interrupt Pending del timerId sin cambiar el resto de campos de Ctrl
		//Usa las máscaras definidas en LEON3 Timer Ctrl Masks
		pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl = pLEON3_TimerUnit_REGS->Timer[timerId].Ctrl & (~LEON3_TIMER_CLEAR_IRQ);
	}else
		error=1;
	return error;
}
