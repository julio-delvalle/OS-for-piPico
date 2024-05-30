#ifndef THREAD_H
#define THREAD_H

#include <stdint.h>
#include "../misc/list.h"

typedef int tid_t;
#define TID_ERROR ((tid_t) -1)          /* Error value for tid_t. */




/* Thread priorities. NO SE USAN. FIFO O ROUNDROBIN NO NECESITA PRIORIDADES.*/
//#define PRI_MIN 0                       /* Lowest priority. */
//#define PRI_DEFAULT 31                  /* Default priority. */
//#define PRI_MAX 63                      /* Highest priority. */



enum thread_status
  {
    THREAD_RUNNING,     /* Running thread. */
    THREAD_READY,       /* Not running but ready to run. */
    THREAD_BLOCKED,     /* Waiting for an event to trigger. */
    THREAD_DYING        /* About to be destroyed. */
  };


struct thread
  {
    tid_t tid;                          /* Thread identifier. */
    enum thread_status status;          /* Thread state. */
    char name[16];                      /* Name (for debugging purposes). */
    uint8_t *stack;                     /* Saved stack pointer. */
    int priority;                       /* Priority. */
    int true_priority; /*Guarda priority con que se inició, para cuando cambie priority por donations*/

    struct list_elem allelem;           /* List element for all threads list. */

    /* Shared between thread.c and synch.c. */
    struct list_elem elem;              /* List element. */

    uint64_t sleep_time;                /*Tiempo que debe dormir*/

    struct list donations_received_list;
    //struct list locks_owned_list; /* locks que el thread tiene actualmente (es holder actualmente) */
    //struct lock *waiting_lock; /* Lock al que el thread está esperando a que se libere*/
    //struct list waiting_for_locks_list; /* Lista de los locks que está esperando/a los que les donó. */

    /* Owned by thread.c. */
    unsigned magic;                     /* Detects stack overflow. */
  };



void thread_init (void);
void thread_start (void);

typedef void thread_func (void *aux);//puntero a función que va a ejecutar el thread.
tid_t thread_create (const char *name, thread_func *, void *);


#endif /* THREAD_H */