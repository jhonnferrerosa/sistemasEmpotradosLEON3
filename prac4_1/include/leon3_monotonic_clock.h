
#ifndef LEON3_MONOTONIC_CLK_H_
#define LEON3_MONOTONIC_CLK_H_




/** \brief Init Monotonic Clock
 *
 *	\param Y2KTimeRef Seconds from 1/1/2000 as Universal Time Reference
 *
 */
void init_monotonic_clock(uint32_t Y2KTimeRef);



/** \brief IRQ Handler that updates the Monotonic Clock,
 * It uses the UpdateMonotonicClock and clears the pending interrupt
 * with the routine leon3_TimerUnit_ClearIRQ(0)
 */

void irq_handler_update_monotonic_clock(void);


/** \brief Update Universal Time Reference
 *
 *	\param Y2KTimeRef Seconds from 1/1/2000 as Universal Time Reference
 *
 */
void update_universal_time_Y2K(uint32_t Y2KTimeRef);


/** \brief Get Universal Time
 *
 *	\return Universal Time Reference as Seconds from 1/1/2000
 *
 */
uint32_t get_universal_time_Y2K();


/** \brief print date time  Y2K codification
 *
 *
 */
void print_date_time_from_Y2K(uint32_t seconds_from_y2K);

/** \brief  date time to Y2K codification, overflow is not checked.
 *
 *	\return Universal Time as Seconds from 1/1/2000
 *
 */
uint32_t date_time_to_Y2K(uint8_t day, uint8_t month, uint8_t year
					, uint8_t hour, uint8_t minutes, uint8_t seconds );


/** \brief Execution time emulation in ms
	 *
	 *	\param exectime_in_ms execution time emulated in ms
	 *
	 *
	 */
void emu_execution_time(uint64_t exectime_in_ms);

#endif /* LEON3_TIMING_H_ */
