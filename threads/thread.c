#include "./thread.h"
#include "../lib/debug.h"
#include "../lib/switch.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../misc/timer.h"
#include "hardware/sync.h"

static void init_thread (struct thread *, const char *name);
static struct thread *running_thread (void);
static struct thread *running_thread_init (void);
static tid_t allocate_tid (void);



//THREADS IMPORTANTES
struct thread *thread_running_var;
//struct thread *current_thread;
static struct thread *idle_thread;




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

//Para scheduling 
unsigned thread_ticks;   /* # of timer ticks since last yield. */


static struct thread *next_thread_to_run (void);
static void schedule (void);
void thread_schedule_tail (struct thread *prev);




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
  printf("Ejecutando función IDLE!\n");
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
    initial_thread = running_thread_init ();
    init_thread (initial_thread, "main");
    initial_thread->status = THREAD_RUNNING;
    initial_thread->tid = allocate_tid ();

    thread_running_var = initial_thread;

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
  t->duration_ticks = 9999999;
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
  thread_create ("idle", idle, NULL, 999);

  /* Start preemptive thread scheduling. */
  //intr_enable ();

  /* Wait for the idle thread to initialize idle_thread. */
  //sema_down (&idle_started);
}

tid_t
thread_create (const char *name,
               thread_func *function, void *aux, int duration)
{
  struct thread *t;
  struct kernel_thread_frame *kf;
  struct switch_entry_frame *ef;
  struct switch_threads_frame *sf;
  tid_t tid;

  //ASSERT (function != NULL); // NO IMPORTA QUE SEA NULL, NO SE ESTÁ MANDANDO A LLAMAR AHORITA.

  /* Allocate thread. */
  //t = palloc_get_page (PAL_ZERO);
  t = calloc(1, sizeof(struct thread));


  if (t == NULL)
    return TID_ERROR;

  /* Initialize thread. */
  init_thread (t, name);
  tid = t->tid = allocate_tid ();
  t->duration_ticks = duration;

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

  if(name == "idle" && tid == 2){
    idle_thread = t;
  }

  block_if_idle_thread();
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

  
   int32_t old_level = save_and_disable_interrupts();

  thread_current ()->status = THREAD_BLOCKED;
  schedule ();

  restore_interrupts(old_level);
}

/* Yields the CPU.  The current thread is not put to sleep and
   may be scheduled again immediately at the scheduler's whim. */
void
thread_yield (void)
{
  struct thread *cur = thread_current ();
  //enum intr_level old_level;

  //ASSERT (!intr_context ());

  //old_level = intr_disable ();
  if(!list_empty(&ready_list)){
      if (cur != idle_thread && cur != initial_thread){
        printf("--YIELD! thread_ticks: %d ; duration left %d\n\n",thread_ticks, thread_current()->duration_ticks);
        list_push_back (&ready_list, &cur->elem);
      }
    cur->status = THREAD_READY; 
    schedule ();
  }
  

  //intr_set_level (old_level);
}

/* Schedules a new process.  At entry, interrupts must be off and
   the running process's state must have been changed from
   running to some other state.  This function finds another
   thread to run and switches to it.

   It's not safe to call printf() until thread_schedule_tail()
   has completed. */
static void
schedule (void)
{
  struct thread *cur = running_thread ();
  struct thread *next = next_thread_to_run ();
  struct thread *prev = NULL;

  //ASSERT (intr_get_level () == INTR_OFF);
  ASSERT (cur->status != THREAD_RUNNING);
  ASSERT (is_thread (next));

  if (cur != next)
    prev = switch_threads_c (cur, next);
  //printf("retornó %x\n",*prev);
  thread_schedule_tail (prev);
}



void
thread_exit (void)
{
  //ASSERT (!intr_context ());


  /* Remove thread from all threads list, set our status to dying,
     and schedule another process.  That process will destroy us
     when it calls thread_schedule_tail(). */
  //intr_disable ();
  if(thread_current() != initial_thread && thread_current() != idle_thread){
    list_remove (&thread_current()->allelem);
    printf("\n===EXIT thread %s\n\n",thread_current()->name);
    thread_current ()->status = THREAD_DYING;
    schedule();
  }else{
    thread_yield ();
  }

  //NOT_REACHED ();
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


  thread_ticks++;
  t->duration_ticks--;
  
}

void block_if_idle_thread(void){
  if(thread_current() == idle_thread){
    thread_block();
  }
}

/* Chooses and returns the next thread to be scheduled.  Should
   return a thread from the run queue, unless the run queue is
   empty.  (If the running thread can continue running, then it
   will be in the run queue.)  If the run queue is empty, return
   idle_thread. */
static struct thread *
next_thread_to_run (void)
{
  if (list_empty (&ready_list))
    return idle_thread;
  else
    return list_entry (list_pop_front (&ready_list), struct thread, elem);
}
/* Completes a thread switch by activating the new thread's page
   tables, and, if the previous thread is dying, destroying it.

   At this function's invocation, we just switched from thread
   PREV, the new thread is already running, and interrupts are
   still disabled.  This function is normally invoked by
   thread_schedule() as its final action before returning, but
   the first time a thread is scheduled it is called by
   switch_entry() (see switch.S).

   It's not safe to call printf() until the thread switch is
   complete.  In practice that means that printf()s should be
   added at the end of the function.

   After this function and its caller returns, the thread switch
   is complete. */
void
thread_schedule_tail (struct thread *prev)
{
  struct thread *cur = running_thread ();

  //ASSERT (intr_get_level () == INTR_OFF);

  /* Mark us as running. */
  cur->status = THREAD_RUNNING;  //YA LO HACE EL SWITCH_THREAD.

  /* Start new time slice. */
  thread_ticks = 0;

  /* If the thread we switched from is dying, destroy its struct
     thread.  This must happen late so that thread_exit() doesn't
     pull out the rug under itself.  (We don't free
     initial_thread because its memory was not obtained via
     palloc().) */
  if (prev != NULL && prev->status == THREAD_DYING && prev != initial_thread)
    {
      ASSERT (prev != cur);
      free (prev); // MATAR AL THREAD< THREAD_EXIT().
    }
}
void insertar_en_lista_espera(int ticks){

  //Deshabilitar interrupciones
  //enum intr_level old_level;
  int32_t old_level = save_and_disable_interrupts();

  //Quitar del ready_list e insertar a lista_espera. Cambiar a THREAD_BLOCKED y definir tiempo:
  struct thread *thread_actual = thread_current();

  thread_actual->sleep_time = timer_ticks() + ticks;
  //Sleep_time se definió en la estructura antes.

  list_push_back(&lista_espera, &thread_actual->elem);
  thread_block();

  //Volver a activar interrupciones
  restore_interrupts(old_level);
}

void thread_sleep (int ticks)
{
  int start = timer_ticks ();

  //ASSERT (intr_get_level () == INTR_ON);
  /*while (timer_elapsed (start) < ticks)
    thread_yield ();*/

  if(ticks > 0){
    printf("SLEEP thread %s - %d ticks.\n",thread_current()->name, ticks);
    //Si es negativo, no lo pone en espera. Esto por test alarm-negative
    insertar_en_lista_espera(ticks);
  }
}

void remover_thread_durmiente(int ticks){

  //Llamada deste timer_interrupt () en timer.c
  //cada timer interrupt verificar si ya se puede regresar el thread a ready_list:

  //Iterando sobre lista_espera:
  struct list_elem *iter = list_begin(&lista_espera);
  while(iter != list_end(&lista_espera)){
    struct thread *thread_lista_espera = list_entry(iter, struct thread, elem);

    //Si el tiempo actual es mayor al tiempo que el thread debe estar dormido, entonces debe salir:
    if(ticks >= thread_lista_espera->sleep_time){
      //quitar de lista espera y agregar a ready_list:
      printf("--Wake Up! Thread %s\n",thread_lista_espera->name);
      iter = list_remove(iter);
      thread_unblock(thread_lista_espera);
    }else{
      //que siga iterando
      iter = list_next(iter);
    }
  }
}





void set_thread_running(struct thread *t){
  t->status = THREAD_RUNNING;
  thread_running_var = t;

}


//LAMADA PARA INICIAR MAIN:
struct thread * 
running_thread_init (void)
{
  uint32_t *esp;

  /* Copy the CPU's stack pointer into `esp', and then round that
     down to the start of a page.  Because `struct thread' is
     always at the beginning of a page and the stack pointer is
     somewhere in the middle, this locates the curent thread. */
  //asm ("mov %%esp, %0" : "=g" (esp));
  asm ("mov %0, sp\n\t" : "=g" (esp));
  return pg_round_down (esp);
}

struct thread *
running_thread (void)
{
  uint32_t *esp;

  /* Copy the CPU's stack pointer into `esp', and then round that
     down to the start of a page.  Because `struct thread' is
     always at the beginning of a page and the stack pointer is
     somewhere in the middle, this locates the curent thread. */
  //asm ("mov %0, sp\n\t" : "=g" (esp));
  //asm ("mov %%esp, %0" : "=g" (esp));
  //printf("SE OBTIENE esp en running_thread: %x \n", esp);
  //return pg_round_down (esp);
  //ASSERT(thread_running_var->status == THREAD_RUNNING);
  return thread_running_var;
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
        printf("[%s] -> ",&current->name);
    }
    printf("\n");
}

void print_all_list(){
  struct list_elem *e;

    ASSERT (&all_list != NULL);

    for (e = list_begin (&all_list); e != list_end (&all_list); e = list_next (e)){
        struct thread *current = list_entry(e, struct thread, allelem);
        printf("[%s] -> ",&current->name);
    }
    printf("\n");
}
void print_ready_list(){
  print_thread_list(&ready_list);
}
void print_blocked_list(){
  print_thread_list(&lista_espera);
}
void print_lists(){
  printf("\n");
  printf("READY: ");
  print_ready_list();
  printf("BLOCKED: ");
  print_blocked_list();
  printf("\n");
}