
#include "../include/leon3_timing_service.h"
#include "../include/leon3_timer_unit_drv.h"
#include "../include/leon3_types.h"
#include "../include/leon3_bprint.h"


//*******************************************************************
/** \brief Universal Time Reference in seconds from 1/1/2000 */
static uint32_t UniversalTimeRefY2K;
/** \brief Reference of the monotonic clock in seconds*/
static uint32_t MonotonicClockSecondsRef;
/** \brief Monotonic clock in seconds*/
static uint32_t MonotonicClockSeconds;

/** \brief TickCounter*/
static uint32_t TickCounter;






//*******************************************************************
void irq_handler_update_monotonic_clock(void){

	TickCounter++;
	if(TickCounter>=TIMING_SERVICE_TICKS_PER_SECOND){
		MonotonicClockSeconds++;
		TickCounter=0;
	}

}

//*******************************************************************
void init_monotonic_clock(uint32_t Y2KTimeRef){

	UniversalTimeRefY2K=Y2KTimeRef;
	MonotonicClockSecondsRef=0;
	MonotonicClockSeconds=0;
	TickCounter=0;

}

//*******************************************************************

void update_universal_time_Y2K(uint32_t Y2KTimeRef){

	MonotonicClockSecondsRef=MonotonicClockSeconds;
	UniversalTimeRefY2K=Y2KTimeRef;

}

//*******************************************************************

uint32_t get_universal_time_Y2K(){

	uint32_t offset;
	offset=MonotonicClockSeconds-MonotonicClockSecondsRef;
	return (UniversalTimeRefY2K+offset);

}

#define DAYS_TO_1_FEBRUARY					31
#define DAYS_TO_1_MARCH_NO_LEAP_YEAR		(DAYS_TO_1_FEBRUARY + 28)
#define DAYS_TO_1_APRIL_NO_LEAP_YEAR		(DAYS_TO_1_MARCH_NO_LEAP_YEAR +31)
#define DAYS_TO_1_MAY_NO_LEAP_YEAR			(DAYS_TO_1_APRIL_NO_LEAP_YEAR +30)
#define DAYS_TO_1_JUNE_NO_LEAP_YEAR			(DAYS_TO_1_MAY_NO_LEAP_YEAR +31)
#define DAYS_TO_1_JULY_NO_LEAP_YEAR			(DAYS_TO_1_JUNE_NO_LEAP_YEAR +30)
#define DAYS_TO_1_AUGUST_NO_LEAP_YEAR		(DAYS_TO_1_JULY_NO_LEAP_YEAR +31)
#define DAYS_TO_1_SEPTEMBER_NO_LEAP_YEAR	(DAYS_TO_1_AUGUST_NO_LEAP_YEAR +31)
#define DAYS_TO_1_OCTOBER_NO_LEAP_YEAR		(DAYS_TO_1_SEPTEMBER_NO_LEAP_YEAR +30)
#define DAYS_TO_1_NOVEMBER_NO_LEAP_YEAR  	(DAYS_TO_1_OCTOBER_NO_LEAP_YEAR +31)
#define DAYS_TO_1_DECEMBER_NO_LEAP_YEAR  	(DAYS_TO_1_NOVEMBER_NO_LEAP_YEAR +30)

//*******************************************************************

void print_date_time_from_Y2K(uint32_t seconds_from_y2K){

	uint32_t 	aux;

	uint8_t 	second;
	uint8_t 	minute;
	uint8_t 	hour;
    uint16_t 	day;
    uint8_t 	month;

    uint32_t 	year;
    bool_t 		leap_year=false;

    aux=seconds_from_y2K;

    second=aux%60;

    aux=(aux-second)/60; //minutes
    minute=aux%60;

    aux=(aux-minute)/60; //hours
    hour=aux%24;

    aux=(aux-hour)/24; //days

    //Year

    year=aux/365;

    if (year>0){
    	day=aux-year*365;

	    if (day >= ((year-1)/4 +1))
               day=day-((year-1)/4 +1);
        else{
               year--;
               day=day+365-((year-1)/4 +1);
        }

	    if(((year-1)%4)==0)
	    	leap_year=true;

    }else {
    	day=aux;
    	leap_year=true;
    }

    day++; //first day is 0

    if(day >= (DAYS_TO_1_DECEMBER_NO_LEAP_YEAR + 1*leap_year)){
    	month=12; day=day-(DAYS_TO_1_DECEMBER_NO_LEAP_YEAR + 1*leap_year);
	}else if(day >= (DAYS_TO_1_NOVEMBER_NO_LEAP_YEAR + 1*leap_year)){
		month=11; day=day-(DAYS_TO_1_NOVEMBER_NO_LEAP_YEAR + 1*leap_year);
	}else if(day >= (DAYS_TO_1_OCTOBER_NO_LEAP_YEAR + 1*leap_year)){
		month=10; day=day-(DAYS_TO_1_OCTOBER_NO_LEAP_YEAR + 1*leap_year);
	}else if(day >= (DAYS_TO_1_SEPTEMBER_NO_LEAP_YEAR + 1*leap_year)){
		month=9; day=day-(DAYS_TO_1_SEPTEMBER_NO_LEAP_YEAR + 1*leap_year);
	}else if(day >= (DAYS_TO_1_AUGUST_NO_LEAP_YEAR + 1*leap_year)){
		month=8; day=day-(aux-(DAYS_TO_1_AUGUST_NO_LEAP_YEAR + 1*leap_year));
	}else if(day >= (DAYS_TO_1_JULY_NO_LEAP_YEAR + 1*leap_year)){
		month=7; day=day-(aux-(DAYS_TO_1_JULY_NO_LEAP_YEAR + 1*leap_year));
	}else if(day >= (DAYS_TO_1_JUNE_NO_LEAP_YEAR + 1*leap_year)){
		month=6; day=day-(DAYS_TO_1_JUNE_NO_LEAP_YEAR + 1*leap_year);
	}else if(day >= (DAYS_TO_1_MAY_NO_LEAP_YEAR + 1*leap_year)){
		month=5; day=day-(DAYS_TO_1_MAY_NO_LEAP_YEAR + 1*leap_year);
	}else if(day >= (DAYS_TO_1_APRIL_NO_LEAP_YEAR + 1*leap_year)){
		month=4; day=day-(DAYS_TO_1_APRIL_NO_LEAP_YEAR + 1*leap_year);
	}else if(day >= (DAYS_TO_1_MARCH_NO_LEAP_YEAR + 1*leap_year)){
		month=3; day=day-(DAYS_TO_1_MARCH_NO_LEAP_YEAR + 1*leap_year);
	}else if(day >= (DAYS_TO_1_FEBRUARY )){
		month=2; day=day-(DAYS_TO_1_FEBRUARY);
	}else month=1;

    leon3_print_string("Fecha ");
    leon3_print_uint8(day);
    leon3_print_string("|");
    leon3_print_uint8(month);
    leon3_print_string("|");
    leon3_print_uint32(year+2000);

    leon3_print_string(" Hora ");
    leon3_print_uint8(hour);
    leon3_print_string(":");
    leon3_print_uint8(minute);
    leon3_print_string(":");
    leon3_print_uint8(second);
    leon3_print_string("\n");
}

//*******************************************************************

uint32_t date_time_to_Y2K(uint8_t day, uint8_t month, uint8_t year
					, uint8_t hour, uint8_t minutes, uint8_t seconds ){

	bool_t leap_year;

	uint32_t total_days;
	uint32_t y2K;

	total_days=year*365;

	if(year){
		total_days+=(year-1)/4 + 1;
		leap_year= ((year-1)%4==0);
	}else
		leap_year=true;

	switch(month){
		   case(2):
				total_days+=DAYS_TO_1_FEBRUARY;break;
	   	   case(3):
				total_days+=DAYS_TO_1_MARCH_NO_LEAP_YEAR+1*leap_year;break;
	   	   case(4):
				total_days+=DAYS_TO_1_APRIL_NO_LEAP_YEAR+1*leap_year;break;
	   	   case(5):
				total_days+=DAYS_TO_1_MAY_NO_LEAP_YEAR+1*leap_year;break;
	   	   case(6):
				total_days+=DAYS_TO_1_JUNE_NO_LEAP_YEAR+1*leap_year;break;
	   	   case(7):
				total_days+=DAYS_TO_1_JULY_NO_LEAP_YEAR+1*leap_year;break;
	   	   case(8):
				total_days+=DAYS_TO_1_AUGUST_NO_LEAP_YEAR+1*leap_year;break;
	   	   case(9):
				total_days+=DAYS_TO_1_SEPTEMBER_NO_LEAP_YEAR+1*leap_year;break;
	   	   case(10):
				total_days+=DAYS_TO_1_OCTOBER_NO_LEAP_YEAR+1*leap_year;break;
	   	   case(11):
				total_days+=DAYS_TO_1_NOVEMBER_NO_LEAP_YEAR+1*leap_year;break;
	   	   case(12):
				total_days+=DAYS_TO_1_DECEMBER_NO_LEAP_YEAR+1*leap_year;break;
	 }

	 total_days+= (day-1);

	 y2K=((total_days*24 + hour)*60 + minutes)*60 + seconds;

	 return y2K;
}

//***************************************************************************************

void emu_execution_time(uint64_t exectime_in_ms){

	int i,j;
	for(i=0; i < exectime_in_ms; i++){
			for(j=0; j < 10; j++){

				leon3_putchar('|');
				leon3_putchar(8);
				while(!leon3_uart_tx_fifo_is_empty())
					;

			}
			for(j=0; j < 10; j++){
				leon3_putchar('/');
				leon3_putchar(8);
				while(!leon3_uart_tx_fifo_is_empty())
					;

			}

			for(j=0; j < 10; j++){
				leon3_putchar('-');
				leon3_putchar(8);
				while(!leon3_uart_tx_fifo_is_empty())
					;

			}
			for(j=0; j < 10; j++){
				leon3_putchar('\\');
				leon3_putchar(8);
				while(!leon3_uart_tx_fifo_is_empty())
					;

			}

		}


}
