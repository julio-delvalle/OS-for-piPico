#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

#include <stdint.h>

/* Number of timer interrupts per second. */
#define TIMER_FREQ 100

extern int ticks; 

int timer_ticks (void);
int timer_elapsed (int then);

/* Sleep and yield the CPU to other threads. */
void timer_sleep (int ticks);
void timer_msleep (int64_t milliseconds);
void timer_usleep (int64_t microseconds);
void timer_nsleep (int64_t nanoseconds);

/* Busy waits. */
void timer_mdelay (int64_t milliseconds);
void timer_udelay (int64_t microseconds);
void timer_ndelay (int64_t nanoseconds);

void timer_print_stats (void);

//Scheduling:
void intr_yield_on_return (void);

#endif /* devices/timer.h */