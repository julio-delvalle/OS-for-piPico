#include "./tests.h"
#include "../lib/debug.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>


const struct test tests[] = 
  {
    {"hello-world", test_hello_world},
    {"fifo-simple", test_fifo_simple},
    {"round-robin-simple", test_round_robin_simple},
    {"round-robin-1tick", test_round_robin_1tick},
    {"fifo-random-duration", test_fifo_random_duration},
    {"round-robin-random-duration", test_round_robin_random_duration},
    {"round-robin-delayed-create", test_round_robin_delayed_create},
    {"sleep-single", test_sleep_single},
    {"sleep-multiple-fifo", test_sleep_multiple_fifo},
    {"sleep-multiple-rr", test_sleep_multiple_rr},
    {"temp-test", test_temp_test},
  };


static const char *test_name;

void print_test_names(void){
  for(int i = 0; i < (sizeof(tests)/sizeof(tests[0])); i++){
        printf("Test %d: %s\n",i+1,tests[i].name);
    }
}

int getNumberOfTests(void){
  return sizeof(tests)/sizeof(tests[0]);
}

char* getTestName(int testN){
  return tests[testN].name;
}

/* Runs the test named NAME. */
void
run_test (const char *name) 
{
  const struct test *t;

  for (t = tests; t < tests + sizeof tests / sizeof *tests; t++)
    if (!strcmp (name, t->name))
      {
        test_name = name;
        msg ("INICIANDO TEST %s",name);
        t->function ();
        return;
      }
  PANIC ("no test named \"%s\"", name);
}

/* Prints FORMAT as if with printf(),
   prefixing the output by the name of the test
   and following it with a new-line character. */
void
msg (const char *format, ...) 
{
  va_list args;
  
  printf ("(%s) ", test_name);
  va_start (args, format);
  vprintf (format, args);
  va_end (args);
  putchar ('\n');
}

/* Prints failure message FORMAT as if with printf(),
   prefixing the output by the name of the test and FAIL:
   and following it with a new-line character,
   and then panics the kernel. */
void
fail (const char *format, ...) 
{
  va_list args;
  
  printf ("(%s) FAIL: ", test_name);
  va_start (args, format);
  vprintf (format, args);
  va_end (args);
  putchar ('\n');

  PANIC ("test failed");
}

/* Prints a message indicating the current test passed. */
void
pass (void) 
{
  printf ("(%s) PASS\n", test_name);
}

