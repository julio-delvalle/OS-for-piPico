#include <stdio.h>
#include "pico/stdlib.h"
#include "threads/thread.h"
#include "lib/debug.h"
#include "misc/timer.h"
#include "lib/palloc.h"
#include "tests/tests.h"


static int round_robin_mode = 1; // 0 es FIFO, 1 es round_robin.



//Para scheduling 
#define TIME_SLICE 45            /* # of timer ticks to give each thread. */
static unsigned round_robin_ticks = 5;
// PARA MODO:
void schedule_set_quantum(int mode, int rrticks);

void schedule_set_quantum(int mode, int rrticks){
    //mode 0 : FIFO
    //mode 1 : round_robin

    if(mode == 0){
        round_robin_mode = 0;
    }else if(mode == 1 && rrticks > 0){
        round_robin_mode = 1;
        round_robin_ticks = rrticks;
    }

}


//PARA TIMER:
/* Number of timer ticks since OS booted. */
int ticks = 0;
extern unsigned thread_ticks;
/* Timer interrupt handler. */
bool timer_interrupt (struct repeating_timer *t)
{
    ticks++;
    thread_tick ();
    printf("Se está ejecutando thread %s, ticks %d\n",thread_current()->name, ticks);
    
    remover_thread_durmiente(ticks);

    return true;
}


 



void after_interrupt(){
    block_if_idle_thread();

    if (thread_current()->duration_ticks <= 0){
        printf("thread_ticks: %d ; duration left %d\n",thread_ticks, thread_current()->duration_ticks);
        thread_exit();
    }

    if(round_robin_mode){ // Si está habilitado round_robin, cambiar al TIME_SLICE
    /* Enforce preemption. */
        if (thread_ticks >= round_robin_ticks){
            //printf("HACER YIELD!\n");
            printf("thread_ticks: %d ; duration left %d\n",thread_ticks, thread_current()->duration_ticks);
            thread_yield();
            //thread_yield_on_return();
        }
    }
}


int main(){
    //Initialize I/O
    stdio_init_all();
    
    //Initialize GPIO - Green led to pin 25
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    printf("=================INICIANDO=================\n");

    printf("Elija un test a ejecutar:\n");
    print_test_names();

    char userInput[5];
    printf("test: ");
    scanf("%s", &userInput);
    

    printf("Se seleccionó el test %s\n\n",userInput);


    thread_init();
    //palloc_init (20); /// NO FUNCIONA, DA HARDFAULT.
    thread_start();

    //TIMER:
    struct repeating_timer timer;
    add_repeating_timer_ms(500, timer_interrupt, NULL, &timer); //TIMER 100 Hz = 10ms


    struct thread *current = thread_current();
    printf("current thread: %s\n",&current->name);

    print_all_list();


    //Después de start, ya se creó idle. Pasarse a idle.
    thread_yield();


    ASSERT (1 < 2); //prueba de ASSERT. Si este falla fallarán todos los de adentro.

    



    run_test("round-robin-simple");
    
    while(1){
        after_interrupt();
    }

    thread_exit();  // NUNCA SE DEBERÍA LLEGAR AQuí
}



/*#include "pico/stdlib.h"
#include <stdio.h>


static int ticks = 0;



bool timer_interrupt (struct repeating_timer *t)
{
    ticks++;
    printf("timera: %d\n",ticks);
}



int main(){
    stdio_init_all();
    printf("INICIANDO\n");
    
    //Initialize GPIO - Green led to pin 25
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
    gpio_put(25,1);


    struct repeating_timer timer;

    printf("se creó timer\n");

    add_repeating_timer_ms(500, timer_interrupt, NULL, &timer);

    printf("se creó repeating timer\n");

    sleep_ms(5000);

    bool cancelled = cancel_repeating_timer(&timer);
    printf("cancelled... %d\n", cancelled);

}


*/