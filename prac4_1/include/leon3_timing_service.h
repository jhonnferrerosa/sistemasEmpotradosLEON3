#include "leon3_types.h"

#ifndef LEON3_TIMING_SERVICE_H_
#define LEON3_TIMING_SERVICE_H_


//TIMING SERVICE CONFIGURATION PARAMETERS

//TODO: definir macro
#define TIMING_SERVICE_TICKS_PER_SECOND 10



	/** \brief Init Timing Service
	 *
	 *  \param currentTime_in_Y2K set current time in Y2K
	 *
	 */
void init_timing_service(uint32_t currentTime_in_Y2K);
#endif /* LEON3_TIMING_SERVICE_CONFIG_H_ */
