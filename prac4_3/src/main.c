
#include "../include/leon3_ev_handling.h"
#include "../include/leon3_hw_irqs.h"
#include "../include/leon3_uart.h"
#include "../include/leon3_bprint.h"

#include "../include/leon3_monotonic_clock.h"
#include "../include/leon3_timer_unit_drv.h"
#include "../include/leon3_timing_service.h"


// Código de la tarea T1
void TAvoidObstacle(void){
 leon3_print_string(" Start Avoid Obstacles\n");
 emu_execution_time(2000);
 leon3_putchar('\n');
 leon3_print_string(" End Avoid Obstacles\n");
}

// Código de la tarea T2
void TPathTracking(void){
	leon3_print_string(" Start Path Tracking\n");
	emu_execution_time(3000);
	leon3_putchar('\n');
	leon3_print_string(" End Path Tracking\n");
}

// Código de la tarea T3
void TSensorFusion(void){
	leon3_print_string(" Start Sensor Fusion\n");
	emu_execution_time(5000);
	leon3_putchar('\n');
	leon3_print_string(" End Sensor Fusion\n");
}
//codigo de la tarea T4.
void TCalculatePath(void){
	leon3_print_string(" Start Calculate Path\n");
	emu_execution_time(6000);
	leon3_putchar('\n');
	leon3_print_string(" End Calculate Path\n");
}


// Definición de las macros de configuración
#define CYClIC_EXECUTIVE_PERIOD_IN_TICKS 100//20  //duracion del pediodo en Ticks. Cada tick son 100ms.
#define CYClIC_EXECUTIVE_HYPER_PERIOD 3  //numero de periodos basicos del hiper periodo.
#define CYClIC_EXECUTIVE_TASKS_NUMBER 4 //numero total tareas del ejecutivo ciclico.

//array bidimensional para definir la secuencia de tareas del ejecutivo ciclico.
void (*cyclic_executive [CYClIC_EXECUTIVE_HYPER_PERIOD]
                         [CYClIC_EXECUTIVE_TASKS_NUMBER+1])(void)={
                        		 {TAvoidObstacle,TPathTracking,TSensorFusion,NULL},
                        		 {TAvoidObstacle,TCalculatePath,NULL,NULL},
                        		 {TAvoidObstacle,TPathTracking,NULL,NULL},
};

int main (){
	//Install handlers for enable and disable irqs
	 leon3_set_trap_handler(0x83, leon3_trap_handler_enable_irqs);
	 leon3_set_trap_handler(0x84 , leon3_trap_handler_disable_irqs);

	 //Declaración de variables de control del ejecutivo cíclico
	 uint8_t current_period=0; //determina el periodo basico actual que se esta ejecutando.
	 int task_index=0; //posicion de la tarea actual a ejecutar, dentro de la secuencia de tareas de cada periodo basico.
	 uint64_t next_period_in_ticks_from_reset;  //numero de ticks desde el reset del sistema en el que debe empezar el siguente periodo basico.

	 //Inicialización del servicio de temporización y toma de referencia absoluta
	  //del número de ticks desde el reset del sistema
	 init_timing_service( date_time_to_Y2K(18, 3, 22, 0, 0, 0 ));

	 //Get Absolute Time reference
	 next_period_in_ticks_from_reset=get_tick_counter_from_reset();

	 while (1){
		 task_index=0; //poner a 0 al inicio de cada periodo básico
		 leon3_print_string("\nStart period\n");
		 print_date_time_from_Y2K(get_universal_time_Y2K());
		 // Control de la ejecución de las tareas de cada período básico
		 while(cyclic_executive[current_period][task_index]){
			 cyclic_executive[current_period][task_index]();
			 task_index++;
		 }
		 //Sincronización con el inicio del siguiente período básico
		 next_period_in_ticks_from_reset+=CYClIC_EXECUTIVE_PERIOD_IN_TICKS;
		 wait_until(next_period_in_ticks_from_reset);
		 //Next basic period
		 current_period++;
		 if(current_period==CYClIC_EXECUTIVE_HYPER_PERIOD){
			 current_period=0;
			 leon3_print_string("\n****************\n");
			 leon3_print_string("\nNext hyperperiod\n");
			 leon3_print_string("\n****************\n");
		 }
	 }
	return 0;
}
