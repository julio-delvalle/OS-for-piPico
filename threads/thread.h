#ifndef THREAD_H
#define THREAD_H

#include <stdint.h>
#include "../misc/list.h"

typedef int tid_t;
#define TID_ERROR ((tid_t) -1)          /* Error value for tid_t. */



//PARA MANEJO DE STACK Y DIRECCIONES:
#define BITMASK(SHIFT, CNT) (((1ul << (CNT)) - 1) << (SHIFT))
#define PGSHIFT 0                          /* Index of first offset bit. */
#define PGBITS  12                         /* Number of offset bits. */
#define PGSIZE  (1 << PGBITS)              /* Bytes in a page. */
#define PGMASK  BITMASK(PGSHIFT, PGBITS)   /* Page offset bits (0:12). */

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


struct thread_register_save 
  {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
    uint32_t r12;
    uint32_t sp;
    uint32_t lr;
    uint32_t pc;
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


    struct thread_register_save register_save;

    int duration_ticks; // Cuántos ticks debe vivir

    /* Owned by thread.c. */
    unsigned magic;                     /* Detects stack overflow. */
  };


typedef void thread_func (void *aux);
struct thread *thread_current (void);
void thread_init (void);
void thread_start (void);
void thread_block (void);
void thread_unblock (struct thread *);
void thread_yield (void);
void thread_exit (void);

//Scheduling:
void thread_tick(void);
void block_if_idle_thread(void);
void set_thread_running(struct thread *);
void insertar_en_lista_espera(int ticks);
void remover_thread_durmiente(int ticks);


typedef void thread_func (void *aux);//puntero a función que va a ejecutar el thread.
tid_t thread_create (const char *name, thread_func *, void *, int duration);


//PRINTING PARA DEBUG:
void print_thread_list(struct list *list);
void print_all_list();
void print_ready_list();
void print_blocked_list();


#endif /* THREAD_H */