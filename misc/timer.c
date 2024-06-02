#include "./timer.h"
#include "../lib/debug.h"
#include <inttypes.h>
#include <stdio.h>
/*#include "devices/pit.h"
#include "threads/interrupt.h"
#include "threads/synch.h"*/
#include "../threads/thread.h"
#include "pico/stdlib.h" // PARA IMPLEMENTAR TICKS CON TIMER_INTERRUPT.
  




static bool yield_on_return;    /* Should we yield on interrupt return? */



//static intr_handler_func timer_interrupt;
static bool timer_interrupt(struct repeating_timer *t);
static void real_time_sleep (int64_t num, int32_t denom);




/* Timer interrupt handler. */
/*bool timer_interrupt (struct repeating_timer *t)
{
  ticks++;
  thread_tick ();
}*/

/* Sets up the timer to interrupt TIMER_FREQ times per second,
   and registers the corresponding interrupt. */
/*void
timer_init () 
{
    struct repeating_timer timer;

    printf("se creó timer\n");

    add_repeating_timer_ms(500, timer_interrupt, NULL, &timer);
    //TIMER, usando hardware/timer.h
    //struct repeating_timer timer;

    //add_repeating_timer_us(timer_freq_us, timer_interrupt, NULL, &timer);
    //pit_configure_channel (0, 2, TIMER_FREQ);
    //intr_register_ext (0x20, timer_interrupt, "8254 Timer");
}*/


/* Returns the number of timer ticks since the OS booted. */
int
timer_ticks (void) 
{
  //enum intr_level old_level = intr_disable ();
  int t = ticks;
  //intr_set_level (old_level);
  return t;
}

/* Returns the number of timer ticks elapsed since THEN, which
   should be a value once returned by timer_ticks(). */
int
timer_elapsed (int then) 
{
  return timer_ticks () - then;
}


/* Prints timer statistics. */
void
timer_print_stats (void) 
{
  printf ("Timer: %"PRId64" ticks\n", timer_ticks ());
}


/* Sleeps for approximately TICKS timer ticks.  Interrupts must
   be turned on. */
void
timer_sleep (int ticks) 
{
  int start = timer_ticks ();

  //ASSERT (intr_get_level () == INTR_ON);
  while (timer_elapsed (start) < ticks) 
    thread_yield ();
}




/* During processing of an external interrupt, directs the
   interrupt handler to yield to a new process just before
   returning from the interrupt.  May not be called at any other
   time. */
void
intr_yield_on_return (void) 
{
  //ASSERT (intr_context ());
  yield_on_return = true;
}

