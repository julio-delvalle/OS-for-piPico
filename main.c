#include <stdio.h>
#include "pico/stdlib.h"
#include "threads/thread.h"
#include "lib/debug.h"
#include "misc/timer.h"
#include "lib/palloc.h"
#include "./tests/tests.h"
#include <stdlib.h>


//Para scheduling 
static int round_robin_mode = 0; // 0 es FIFO, 1 es round_robin.
#define TIME_SLICE 45            /* # of timer ticks to give each thread. */
static unsigned round_robin_ticks = 5;
extern int thread_exit_on_return;

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



//Para tests:
extern const struct test tests[];


//PARA TIMER:
/* Number of timer ticks since OS booted. */
int ticks = 0;
extern unsigned thread_ticks;
//INTERRUPTS:
bool timer_interrupt (struct repeating_timer *t);
void after_interrupt(void);


void after_interrupt(void){
    block_if_idle_thread();

    if (thread_current()->duration_ticks <= 0){
        printf("thread_ticks: %d ; duration left %d\n",thread_ticks, thread_current()->duration_ticks);
        thread_exit();
    }else if(round_robin_mode && !is_ready_list_empty()){ // Si está habilitado round_robin, cambiar al TIME_SLICE
    /* Enforce preemption. */
        if (thread_ticks >= round_robin_ticks){
            //printf("HACER YIELD!\n");
            thread_yield();
            //thread_yield_on_return();
        }
    }
    
    if(thread_exit_on_return && thread_current()->duration_ticks != 0){
        printf("FORCED EXIT thread %s, duration left: %d",thread_current()->name, thread_current()->duration_ticks);
        thread_exit();
        thread_exit_on_return = 0;
    }
}

/* Timer interrupt handler. */
bool timer_interrupt (struct repeating_timer *t)
{
    ticks++;
    thread_tick ();
    printf("Se está ejecutando thread %s, ticks %d\n",thread_current()->name, ticks);
    
    remover_thread_durmiente(ticks);

    return true;
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

    int numberOfTests = getNumberOfTests();

    char userInput[5];
    printf("test: ");
    scanf("%s", &userInput);

    int testSelected = atoi(userInput);
    while((testSelected > numberOfTests) || testSelected <= 0){
        printf("VALOR INCORRECTO. Seleccione test: ");
        scanf("%s", &userInput);
        testSelected = atoi(userInput);
    }

    

    printf("Se seleccionó el test %d\n\n",testSelected);

    if((testSelected <= numberOfTests) && testSelected > 0){
        testSelected--;

        if(testSelected == 14){
            printf("Ingrese ciclos para round robin (>0): ");
            scanf("%s", &userInput);

            int rrCountSelected = atoi(userInput);
            while(testSelected <= 0){
                printf("Debe ser mayor a 0. Ingrese ciclos para round robin: ");
                scanf("%s", &userInput);
                rrCountSelected = atoi(userInput);
            }

            printf("--------------------Configurando round robin para %d ciclos.\n--------------------\n",rrCountSelected);
            schedule_set_quantum(1, rrCountSelected);
        }

        thread_init();
        //palloc_init (20); /// NO FUNCIONA, DA HARDFAULT.
        thread_start();

        //TIMER:
        struct repeating_timer timer;
        add_repeating_timer_ms(500, timer_interrupt, NULL, &timer); //TIMER 500 ms = 2 Hz 


        struct thread *current = thread_current();
        printf("current thread: %s\n",&current->name);

        print_all_list();


        //Después de start, ya se creó idle. Pasarse a idle.
        thread_yield();

        ASSERT (1 < 2); //prueba de ASSERT. Si este falla fallarán todos los de adentro.

        char* test_name = getTestName(testSelected);

        run_test(test_name);

        while(1){
            after_interrupt();
        }

        thread_exit();  // NUNCA SE DEBERÍA LLEGAR AQuí
    }else{
        printf("Test no válido. Saliendo...");
    }
    
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