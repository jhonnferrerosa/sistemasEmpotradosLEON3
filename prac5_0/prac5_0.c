
//#include "../include/leon3_types.h"

#include </opt/rtems-4.6/sparc-rtems/leon3/lib/include/rtems.h>
#include <stdio.h>
#include <stdlib.h>

/* functions */

//System Init
rtems_task Init(
  rtems_task_argument argument
);

//User Task declarations
rtems_task Test_task(
  rtems_task_argument argument
);



/* global variables */

#define MAX_TASK_NUMBER 10

/*
 *  Keep the names and IDs in global variables so another task can use them.
 */

extern rtems_id   Task_id[ MAX_TASK_NUMBER ];         /* array of task ids */
extern rtems_name Task_name[ MAX_TASK_NUMBER ];       /* array of task names */


/* configuration information */

#include </opt/rtems-4.6/sparc-rtems/leon3/lib/include/bsp.h> /* for device driver prototypes */

#define CONFIGURE_INIT
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

#define CONFIGURE_MAXIMUM_TASKS             MAX_TASK_NUMBER

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_EXTRA_TASK_STACKS         (MAX_TASK_NUMBER * RTEMS_MINIMUM_STACK_SIZE)

#include </opt/rtems-4.6/sparc-rtems/leon3/lib/include/confdefs.h>

/*
 *  Handy macros and static inline functions
 */

/*
 *  Macro to hide the ugliness of printing the time.
 */

#define print_time(_s1, _tb, _s2) \
  do { \
    printf( "%s%02d:%02d:%02d   %02d/%02d/%04d%s", \
       _s1, (_tb)->hour, (_tb)->minute, (_tb)->second, \
       (_tb)->month, (_tb)->day, (_tb)->year, _s2 ); \
    fflush(stdout); \
  } while ( 0 )

/*
 *  Macro to print an task name that is composed of ASCII characters.
 *
 */

#define put_name( _name, _crlf ) \
  do { \
    uint32_t c0, c1, c2, c3; \
    \
    c0 = ((_name) >> 24) & 0xff; \
    c1 = ((_name) >> 16) & 0xff; \
    c2 = ((_name) >> 8) & 0xff; \
    c3 = (_name) & 0xff; \
    putchar( (char)c0 ); \
    if ( c1 ) putchar( (char)c1 ); \
    if ( c2 ) putchar( (char)c2 ); \
    if ( c3 ) putchar( (char)c3 ); \
    if ( (_crlf) ) \
      putchar( '\n' ); \
  } while (0)

/*
 *  static inline routine to make obtaining ticks per second easier.
 */

static inline uint32_t get_ticks_per_second( void )
{
  rtems_interval ticks_per_second;
  //TODO retornar los ticks por segundo
  rtems_clock_get (RTEMS_CLOCK_GET_TICKS_PER_SECOND, &ticks_per_second);
  return ticks_per_second;

}

static inline uint32_t get_ticks_since_boot( void )
{
  rtems_interval ticks_since_boot;
  //TODO retornar los ticks desde el inicio del sistema
  rtems_clock_get (RTEMS_CLOCK_GET_TICKS_SINCE_BOOT, &ticks_since_boot);
  return ticks_since_boot;

}


/*
 *  This allows us to view the "Test_task" instantiations as a set
 *  of numbered tasks by eliminating the number of application
 *  tasks created.
 *
 *  In reality, this is too complex for the purposes of this
 *  example.  It would have been easier to pass a task argument. :)
 *  But it shows how rtems_id's can sometimes be used.
 */

#define task_number( tid ) \
  ( rtems_object_id_get_index( tid ) - \
     rtems_configuration_get_rtems_api_configuration()->number_of_initialization_tasks )



/*
 *  Keep the names and IDs in global variables so another task can use them.
 */

rtems_id   Task_id[ MAX_TASK_NUMBER ];         /* array of task ids */
rtems_name Task_name[ MAX_TASK_NUMBER ];       /* array of task names */



rtems_task Init(rtems_task_argument argument)
{
  rtems_status_code status;
  rtems_time_of_day time;

  printf ("\n miValorPrueba:  %i", RTEMS_CLOCK_GET_TICKS_PER_SECOND);
  puts( "\n\n+++---+++*** CLOCK TICK TEST ***" );

  //TODO fijar el time of day a 22/04/2022 utilizando rtems_clock_set


  time.year   = 2023;
  time.month  = 04;
  time.day    = 22;
  time.hour   = 0;
  time.minute = 0;
  time.second = 0;
  time.ticks  = 0;

  status = rtems_clock_set (&time);



  Task_name[ 1 ] = rtems_build_name( 'T', 'A', '1', ' ' );
  Task_name[ 2 ] = rtems_build_name( 'T', 'A', '2', ' ' );
  Task_name[ 3 ] = rtems_build_name( 'T', 'A', '3', ' ' );

  status = rtems_task_create(
    Task_name[ 1 ], 1, RTEMS_MINIMUM_STACK_SIZE * 2, RTEMS_DEFAULT_MODES,
    RTEMS_DEFAULT_ATTRIBUTES, &Task_id[ 1 ]
  );
  status = rtems_task_create(
    Task_name[ 2 ], 1, RTEMS_MINIMUM_STACK_SIZE * 2, RTEMS_DEFAULT_MODES,
    RTEMS_DEFAULT_ATTRIBUTES, &Task_id[ 2 ]
  );
  status = rtems_task_create(
    Task_name[ 3 ], 1, RTEMS_MINIMUM_STACK_SIZE * 2, RTEMS_DEFAULT_MODES,
    RTEMS_DEFAULT_ATTRIBUTES, &Task_id[ 3 ]
  );

  status = rtems_task_start( Task_id[ 1 ], Test_task, 1 );
  status = rtems_task_start( Task_id[ 2 ], Test_task, 2 );
  status = rtems_task_start( Task_id[ 3 ], Test_task, 3 );

  status = rtems_task_delete( RTEMS_SELF );
}


rtems_task Test_task(
  rtems_task_argument unused
)
{
  rtems_id          tid;
  rtems_time_of_day time;
  uint32_t  task_index;
  rtems_status_code status;

  status = rtems_task_ident( RTEMS_SELF, RTEMS_SEARCH_ALL_NODES, &tid );

  task_index = rtems_get_index(tid)-1;
  for ( ; ; ) {
    status = rtems_clock_get( RTEMS_CLOCK_GET_TOD, &time );
    if ( time.second >= 3335 ) {
      puts( "*** END OF CLOCK TICK TEST ***" );
      exit( 0 );
    }

    put_name( Task_name[ task_index ], FALSE );
    print_time( " - rtems_clock_get - ", &time, "\n" );

    printf(" - rtems_ticks_since_boot - %i\n", get_ticks_since_boot());

    status = rtems_task_wake_after( task_index * 5 * get_ticks_per_second() );
  }
}
