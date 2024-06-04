/* Tests timer_sleep(-100).  Only requirement is that it not crash. */

#include <stdio.h>
#include "./tests.h"
#include "../threads/thread.h"

void
test_alarm_negative (void) 
{
  //timer_sleep (-100);
  //pass ();
  msg("Hello world alarm-negative!!\n");
}
