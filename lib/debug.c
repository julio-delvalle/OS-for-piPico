#include "./debug.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define ASSERT(CONDITION)                                       \
if (CONDITION) { } else {                               \
        PANIC ("assertion `%s' failed.", #CONDITION);   \
}

#define PANIC(...) debug_panic (__FILE__, __LINE__, __func__, __VA_ARGS__)

/* Prints the call stack, that is, a list of addresses, one in
   each of the functions we are nested within.  gdb or addr2line
   may be applied to kernel.o to translate these into file names,
   line numbers, and function names.  */
void
debug_backtrace (void) 
{
  static bool explained;
  void **frame;
  
  printf ("Call stack: %p", __builtin_return_address (0));
  for (frame = __builtin_frame_address (1);
       (uintptr_t) frame >= 0x1000 && frame[0] != NULL;
       frame = frame[0]) 
    printf (" %p", frame[1]);
  printf (".\n");

  if (!explained) 
    {
      explained = true;
      printf ("The `backtrace' program can make call stacks useful.\n"
              "Read \"Backtraces\" in the \"Debugging Tools\" chapter\n"
              "of the Pintos documentation for more information.\n");
    }
}


/* Aborts the user program, printing the source file name, line
   number, and function name, plus a user-specific message. */
void
debug_panic (const char *file, int line, const char *function,
             const char *message, ...)
{
  va_list args;

  printf ("User process ABORT at %s:%d in %s(): \n", file, line, function);
  //printf ("User process ABORT at %s:%d", file, line);

  va_start (args, message);
  vprintf (message, args);
  printf ("\n");
  va_end (args);

  //debug_backtrace ();
  
  exit (1);
}