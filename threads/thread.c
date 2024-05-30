#include "./thread.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

static void init_thread (struct thread *, const char *name);
static struct thread *running_thread (void);
static tid_t allocate_tid (void);



#define PGSHIFT 0                          /* Index of first offset bit. */
#define PGBITS  12                         /* Number of offset bits. */
#define PGSIZE  (1 << PGBITS)              /* Bytes in a page. */
#define PGMASK  BITMASK(PGSHIFT, PGBITS)   /* Page offset bits (0:12). */

/* List of processes in SLEEP state, that is, processes/threads
that are waiting to finish their sleep time. */
static struct list lista_espera;


/* List of processes in THREAD_READY state, that is, processes
   that are ready to run but not actually running. */
static struct list ready_list;

/* List of all processes.  Processes are added to this list
   when they are first scheduled and removed when they exit. */
static struct list all_list;


/* Initial thread, the thread running init.c:main(). */
static struct thread *initial_thread;


//Solo se llama una vez, que inicia el sistema de threads.
void
thread_init (void)
{
    list_init (&ready_list);
    list_init (&all_list);
    list_init (&lista_espera);

    /* Set up a thread structure for the running thread. */
    initial_thread = running_thread ();
    init_thread (initial_thread, "main");
    initial_thread->status = THREAD_RUNNING;
    initial_thread->tid = allocate_tid ();

    printf("Se termino de configurar el thread inicial. info: name %s , status %d, tid %d\n",&initial_thread->name, &initial_thread->status, &initial_thread->tid);
}

/* Does basic initialization of T as a blocked thread named
   NAME. */
static void
init_thread (struct thread *t, const char *name)
{
  //ASSERT (t != NULL);
  //ASSERT (name != NULL);

  memset (t, 0, sizeof *t);
  t->status = THREAD_BLOCKED;
  strlcpy (t->name, name, sizeof t->name);
  t->stack = (uint8_t *) t + PGSIZE;
  //list_init(&t->locks_owned_list);
  //list_init(&t->waiting_for_locks_list);
  //list_init(&t->donations_received_list);

  list_push_back (&all_list, &t->allelem);

  printf("Se creó el thread (%s)\n",name);
}



tid_t
thread_create (const char *name, 
               thread_func *function, void *aux)
{

  tid_t tid = allocate_tid();
  printf("Thread create con tid %d.\n",tid);
}





struct thread *
running_thread (void)
{
  uint32_t *esp;

  /* Copy the CPU's stack pointer into `esp', and then round that
     down to the start of a page.  Because `struct thread' is
     always at the beginning of a page and the stack pointer is
     somewhere in the middle, this locates the curent thread. */
  //asm ("mov %%esp, %0" : "=g" (esp));
  //return pg_round_down (esp);
  printf("SE OBTIENE esp: %x", esp);
  return (struct thread *)(esp);
}

/* Returns a tid to use for a new thread. */
tid_t
allocate_tid (void)
{
  //printf("entrando a allocate_tid\n");
  static tid_t next_tid = 1;
  tid_t tid;

  //lock_acquire (&tid_lock);
  tid = next_tid++;
  //lock_release (&tid_lock);

  //printf("Se acaba de llamar allocate_tid, next %d, tid %d \n",next_tid,tid);
  return tid;
}