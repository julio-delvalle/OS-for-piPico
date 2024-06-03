#include <stdio.h>
#include "pico/stdlib.h"
#include "threads/thread.h"
#include "lib/debug.h"
#include "misc/timer.h"
#include "lib/palloc.h"




//PARA TIMER:
/* Number of timer ticks since OS booted. */
int ticks = 0;
/* Timer interrupt handler. */
bool timer_interrupt (struct repeating_timer *t)
{
    ticks++;
    thread_tick ();
}




void hello_world(void *t);

void hello_world(void* t){
    printf("\n\nHello World from thread!\n\n");
    thread_exit();
}



int main(){
    //Initialize I/O
    stdio_init_all();
    
    //Initialize GPIO - Green led to pin 25
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    printf("INICIANDO\n");
    

    thread_init();
    //palloc_init (20); /// NO FUNCIONA, DA HARDFAULT.
    thread_start();

    //TIMER:
    struct repeating_timer timer;
    printf("se creó timer\n");
    add_repeating_timer_ms(10, timer_interrupt, NULL, &timer); //TIMER 100 Hz = 10ms


    struct thread *current = thread_current();
    printf("current thread: %s\n",&current->name);

    print_all_list();


    ASSERT (1 < 2); //prueba de ASSERT. Si este falla fallarán todos los de adentro.

    int count = 0;
    char nombre[] = "hola";

    while(1){

        // ============== LLAMAR TESTS, VER INIT.C EN PINTOS =============
        gpio_put(25,1);
        sleep_ms(2000);

        if(count < 5){
            sprintf(nombre, "hola-%d", count);
            count++; 
            thread_create(nombre, hello_world, NULL);
        }
        printf("ALL: ");
        print_all_list();
        printf("READY: ");
        print_ready_list();
        printf("ticks: %d\n",timer_ticks());
        gpio_put(25,0);
        sleep_ms(1000);
    }

    thread_exit();
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