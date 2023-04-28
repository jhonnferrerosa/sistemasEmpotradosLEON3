
#include "../include/leon3_ev_handling.h"
#include "../include/leon3_hw_irqs.h"
#include "../include/leon3_uart.h"
#include "../include/leon3_bprint.h"

#include "../include/leon3_monotonic_clock.h"
#include "../include/leon3_timer_unit_drv.h"
#include "../include/leon3_timing_service.h"

///dudas1:  MonotonicClockSeconds, me fijo que nunca avanza de cero.

int main (){
	 uint32_t aux1,aux2;
	 //Instalar manejadores de traps para habilitar
	 //y deshabilitar las interrupciones
	 leon3_set_trap_handler(0x83, leon3_trap_handler_enable_irqs);
	 leon3_set_trap_handler(0x84 , leon3_trap_handler_disable_irqs);

	 //Inicializar servicio de temporización con el tiempo
	 //universal actual
	  //Init Timing Service with current universal time
	  init_timing_service(date_time_to_Y2K(18, 3, 22, 0, 0, 0 ));

	  while(1){
		  //Mostrar tiempo con un intervalo de 10 segundos.
		  //Print time with an interval of 10 seconds
		  aux1=get_universal_time_Y2K();
		  if (((aux1%10)==0) && aux1!=aux2){
			  print_date_time_from_Y2K(aux1);
			  aux2=aux1;
		  }
	   }
	return 0;
}
