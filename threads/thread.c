#include "./thread.h"
#include "../lib/debug.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../misc/timer.h"

static void init_thread (struct thread *, const char *name);
static struct thread *running_thread (void);
static tid_t allocate_tid (void);

//THREADS IMPORTANTES
struct thread *current_thread;
static struct thread *idle_thread;



//PARA MANEJO DE STACK Y DIRECCIONES:
#define BITMASK(SHIFT, CNT) (((1ul << (CNT)) - 1) << (SHIFT))
#define PGSHIFT 0                          /* Index of first offset bit. */
#define PGBITS  12                         /* Number of offset bits. */
#define PGSIZE  (1 << PGBITS)              /* Bytes in a page. */
#define PGMASK  BITMASK(PGSHIFT, PGBITS)   /* Page offset bits (0:12). */
/* Round down to nearest page boundary. */
static inline void *pg_round_down (const void *va) {
  return (void *) ((uintptr_t) va & ~PGMASK);
}






/* Random value for struct thread's `magic' member.
   Used to detect stack overflow.  See the big comment at the top
   of thread.h for details. */
#define THREAD_MAGIC 0xcd6abf4b





// =============== LISTAS DE THREADS UTILES ============
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








// ============== SCHEUDLING ===========
/* Statistics. */
static long long idle_ticks;    /* # of timer ticks spent idle. */
static long long kernel_ticks;  /* # of timer ticks in kernel threads. */
static long long user_ticks;    /* # of timer ticks in user programs. */

#define TIME_SLICE 4            /* # of timer ticks to give each thread. */
static unsigned thread_ticks;   /* # of timer ticks since last yield. */



// ======== FUNCIONES SIMPLES PARA VALIDACIONES ============


/* Returns true if T appears to point to a valid thread. */
static bool
is_thread (struct thread *t)
{
  return t != NULL && t->magic == THREAD_MAGIC;
}










// =================== THREADS BÁSICOS: IDLE Y KERNEL ================
/* Idle thread.  Executes when no other thread is ready to run.

   The idle thread is initially put on the ready list by
   thread_start().  It will be scheduled once initially, at which
   point it initializes idle_thread, "up"s the semaphore passed
   to it to enable thread_start() to continue, and immediately
   blocks.  After that, the idle thread never appears in the
   ready list.  It is returned by next_thread_to_run() as a
   special case when the ready list is empty. */
static void idle (void *aux UNUSED);


static void
idle (void *idle_started_ UNUSED)
{
  struct semaphore *idle_started = idle_started_;
  idle_thread = thread_current ();
  //sema_up (idle_started);

  for (;;)
    {
      /* Let someone else run. */
      //intr_disable ();
      thread_block ();

      /* Re-enable interrupts and wait for the next one.

         The `sti' instruction disables interrupts until the
         completion of the next instruction, so these two
         instructions are executed atomically.  This atomicity is
         important; otherwise, an interrupt could be handled
         between re-enabling interrupts and waiting for the next
         one to occur, wasting as much as one clock tick worth of
         time.

         See [IA32-v2a] "HLT", [IA32-v2b] "STI", and [IA32-v3a]
         7.11.1 "HLT Instruction". */
      //asm volatile ("sti; hlt" : : : "memory");
    }
}

static void kernel_thread (thread_func *, void *aux);
/* Function used as the basis for a kernel thread. */
static void
kernel_thread (thread_func *function, void *aux)
{
  ASSERT (function != NULL);

  //intr_enable ();       /* The scheduler runs with interrupts off. */
  function (aux);       /* Execute the thread function. */
  //thread_exit ();       /* If function() returns, kill the thread. */
}








// =============== MANEJO DE MEMORIA ===================== 
/* Stack frame for kernel_thread(). */
struct kernel_thread_frame
  {
    void *eip;                  /* Return address. */
    thread_func *function;      /* Function to call. */
    void *aux;                  /* Auxiliary data for function. */
  };
/* Stack frame for switch_entry(). */
struct switch_entry_frame
  {
    void (*eip) (void);
  };

/* switch_thread()'s stack frame. */
struct switch_threads_frame 
  {
    uint32_t edi;               /*  0: Saved %edi. */
    uint32_t esi;               /*  4: Saved %esi. */
    uint32_t ebp;               /*  8: Saved %ebp. */
    uint32_t ebx;               /* 12: Saved %ebx. */
    void (*eip) (void);         /* 16: Return address. */
    struct thread *cur;         /* 20: switch_threads()'s CUR argument. */
    struct thread *next;        /* 24: switch_threads()'s NEXT argument. */
  };


static void *
alloc_frame (struct thread *t, size_t size)
{
  /* Stack data is always allocated in word-size units. */
  ASSERT (is_thread (t));
  ASSERT (size % sizeof (uint32_t) == 0);

  t->stack -= size;
  return t->stack;
}











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

    printf("Se termino de configurar el thread inicial. info: name %s , status %d, tid %d\n",&initial_thread->name, initial_thread->status, initial_thread->tid);
}

/* Does basic initialization of T as a blocked thread named
   NAME. */
static void
init_thread (struct thread *t, const char *name)
{
  ASSERT (t != NULL);
  ASSERT (name != NULL);

  memset (t, 0, sizeof *t);
  t->status = THREAD_BLOCKED;
  strlcpy (t->name, name, sizeof t->name);
  t->stack = (uint8_t *) t + PGSIZE;
  t->magic = THREAD_MAGIC;
  //list_init(&t->locks_owned_list);
  //list_init(&t->waiting_for_locks_list);
  //list_init(&t->donations_received_list);

  list_push_back (&all_list, &t->allelem);

  printf("Se creó el thread (%s)\n",name);
}
/* Starts preemptive thread scheduling by enabling interrupts.
   Also creates the idle thread. */
void
thread_start (void)
{
  /* Create the idle thread. */
  //struct semaphore idle_started;
  //sema_init (&idle_started, 0);
  thread_create ("idle", idle, NULL);

  /* Start preemptive thread scheduling. */
  //intr_enable ();

  /* Wait for the idle thread to initialize idle_thread. */
  //sema_down (&idle_started);
}



/*tid_t
thread_create (const char *name, 
               thread_func *function, void *aux)
{

  tid_t tid = allocate_tid();
  printf("Thread create con tid %d.\n",tid);
}*/

tid_t
thread_create (const char *name,
               thread_func *function, void *aux)
{
  struct thread *t;
  struct kernel_thread_frame *kf;
  struct switch_entry_frame *ef;
  struct switch_threads_frame *sf;
  tid_t tid;

  ASSERT (function != NULL);

  /* Allocate thread. */
  //t = palloc_get_page (PAL_ZERO);
  t = calloc(1, sizeof(struct thread));


  if (t == NULL)
    return TID_ERROR;

  /* Initialize thread. */
  init_thread (t, name);
  tid = t->tid = allocate_tid ();

  /* Stack frame for kernel_thread(). */
  kf = alloc_frame (t, sizeof *kf);
  kf->eip = NULL;
  kf->function = function;
  kf->aux = aux;

  /* Stack frame for switch_entry(). */
  
  //========= ESTO PARECE SER PARA CONTEXT SWITCH ====== COMENTADO POR AHORA =========
  //ef = alloc_frame (t, sizeof *ef);
  //ef->eip = (void (*) (void)) kernel_thread;
  /* Stack frame for switch_threads(). */
  //sf = alloc_frame (t, sizeof *sf);
  //sf->eip = switch_entry;
  //sf->ebp = 0;

  /* Add to run queue. */
  thread_unblock (t);

  //printf("Thread create con tid %d.\n",tid);
  return tid;
}

void
thread_unblock (struct thread *t)
{
  //enum intr_level old_level;

  ASSERT (is_thread (t));

  //old_level = intr_disable ();
  ASSERT (t->status == THREAD_BLOCKED);
  list_push_back (&ready_list, &t->elem);
  t->status = THREAD_READY;
  //intr_set_level (old_level);
}

void
thread_block (void)
{
  //ASSERT (!intr_context ());
  //ASSERT (intr_get_level () == INTR_OFF);

  thread_current ()->status = THREAD_BLOCKED;
  //schedule ();
}

/* Yields the CPU.  The current thread is not put to sleep and
   may be scheduled again immediately at the scheduler's whim. */
void
thread_yield (void)
{
  printf("THREAD YIELD!\n");
  /*struct thread *cur = thread_current ();
  //enum intr_level old_level;

  ASSERT (!intr_context ());

  //old_level = intr_disable ();
  if (cur != idle_thread)
    list_push_back (&ready_list, &cur->elem);
  cur->status = THREAD_READY;
  schedule ();*/
  //intr_set_level (old_level);
}

void
thread_exit (void)
{
  //ASSERT (!intr_context ());


  /* Remove thread from all threads list, set our status to dying,
     and schedule another process.  That process will destroy us
     when it calls thread_schedule_tail(). */
  //intr_disable ();
  list_remove (&thread_current()->allelem);
  thread_current ()->status = THREAD_DYING;
  //schedule ();
  NOT_REACHED ();
}






// ================ SCHEDULING ====================

/* Called by the timer interrupt handler at each timer tick.
   Thus, this function runs in an external interrupt context. */
void
thread_tick (void)
{
  struct thread *t = thread_current ();

  /* Update statistics. */
  if (t == idle_thread)
    idle_ticks++;
  else
    kernel_ticks++;

  /* Enforce preemption. */
  if (++thread_ticks >= TIME_SLICE)
    intr_yield_on_return ();
}







struct thread *
running_thread (void)
{
  uint32_t *esp;

  /* Copy the CPU's stack pointer into `esp', and then round that
     down to the start of a page.  Because `struct thread' is
     always at the beginning of a page and the stack pointer is
     somewhere in the middle, this locates the curent thread. */
  asm ("mov %0, sp\n\t" : "=g" (esp));
  //asm ("mov %%esp, %0" : "=g" (esp));
  //printf("SE OBTIENE esp en running_thread: %x \n", esp);
  return pg_round_down (esp);
}

/* Returns the running thread.
   This is running_thread() plus a couple of sanity checks.
   See the big comment at the top of thread.h for details. */
struct thread *
thread_current (void)
{
  struct thread *t = running_thread ();

  /* Make sure T is really a thread.
     If either of these assertions fire, then your thread may
     have overflowed its stack.  Each thread has less than 4 kB
     of stack, so a few big automatic arrays or moderate
     recursion can cause stack overflow. */
  ASSERT (is_thread (t));
  ASSERT (t->status == THREAD_RUNNING);

  return t;
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



void print_thread_list(struct list *list){
    struct list_elem *e;

    ASSERT (list != NULL);

    printf("LISTA: ");
    for (e = list_begin (list); e != list_end (list); e = list_next (e)){
        struct thread *current = list_entry(e, struct thread, elem);
        printf("[%s (%d)] -> ",&current->name, current->tid);
    }
    printf("\n");
}

void print_all_list(){
  struct list_elem *e;

    ASSERT (&all_list != NULL);

    printf("LISTA: ");
    for (e = list_begin (&all_list); e != list_end (&all_list); e = list_next (e)){
        struct thread *current = list_entry(e, struct thread, allelem);
        printf("[%s (%d)] -> ",&current->name, current->tid);
    }
    printf("\n");
}
void print_ready_list(){
  print_thread_list(&ready_list);
}