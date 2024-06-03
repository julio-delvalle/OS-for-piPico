#include "./switch.h"
#include "../threads/thread.h"


/* Offset of `stack' member within `struct thread'.
   Used by switch.S, which can't figure it out on its own. */
uint32_t thread_stack_ofs = offsetof (struct thread, stack);


// Se intenta hacer lo que se tiene en switch.S usando asm();
struct thread* switch_threads_c (struct thread *cur, struct thread *next){
    
    //struct thread * new = cur;
    
    // LR y PC no se cambian !!!!!


    //Guarda los 12 registros básicos del actual
    //asm ("mov %0, r0\n\t" : "=g" (cur->register_save.r0)); // R0 NO LO REGRESA PORQUE ES EL QUE TRAE A *CUR !!!!!!!!
    //asm ("mov %0, r1\n\t" : "=g" (cur->register_save.r1));
    //asm ("mov %0, r2\n\t" : "=g" (cur->register_save.r2));
    asm ("mov %0, r3\n\t" : "=g" (cur->register_save.r3));
    //asm ("mov %0, r4\n\t" : "=g" (cur->register_save.r4));
    asm ("mov %0, r5\n\t" : "=g" (cur->register_save.r5));
    asm ("mov %0, r6\n\t" : "=g" (cur->register_save.r6));
    asm ("mov %0, r7\n\t" : "=g" (cur->register_save.r7));
    //asm ("mov %0, r8\n\t" : "=g" (cur->register_save.r8));
    /*asm ("mov %0, r9\n\t" : "=g" (cur->register_save.r9));
    asm ("mov %0, r10\n\t" : "=g" (cur->register_save.r10));
    asm ("mov %0, r11\n\t" : "=g" (cur->register_save.r11));
    asm ("mov %0, r12\n\t" : "=g" (cur->register_save.r12));*/
    //La última instruccion de ese thread: guarda el SP:
    asm ("mov %0, sp\n\t" : "=g" (cur->register_save.sp));


    //Nos pasamos al nuevo thread, cargamos el SP:
    // asm ("mov %%sp, %0\n\t" : : "r" (next->register_save.sp + thread_stack_ofs)); //Qué pasa si no cambio el SP? 

    //Cargamos todos los 12 registros básicos que estaban guardados. Si el thread está iniciando está todo en 0.
    //asm ("mov %%r0, %0\n\t" : : "r" (next->register_save.r0)); // R0 NO LO REGRESA PORQUE ES EL QUE TRAE A *CUR !!!!!!!!
    //asm ("mov %%r1, %0\n\t" : : "r" (next->register_save.r1));
    //asm ("mov %%r2, %0\n\t" : : "r" (next->register_save.r2));
    asm ("mov %%r3, %0\n\t" : : "r" (next->register_save.r3));
    //asm ("mov %%r4, %0\n\t" : : "r" (next->register_save.r4));
    asm ("mov %%r5, %0\n\t" : : "r" (next->register_save.r5));
    asm ("mov %%r6, %0\n\t" : : "r" (next->register_save.r6));
    asm ("mov %%r7, %0\n\t" : : "r" (next->register_save.r7));
    //asm ("mov %%r8, %0\n\t" : : "r" (next->register_save.r8));
    /*asm ("mov %%r9, %0\n\t" : : "r" (next->register_save.r9));
    asm ("mov %%r10, %0\n\t" : : "r" (next->register_save.r10));
    asm ("mov %%r11, %0\n\t" : : "r" (next->register_save.r11));
    asm ("mov %%r12, %0\n\t" : : "r" (next->register_save.r12));*/


    set_thread_running(next);

    return cur;
}