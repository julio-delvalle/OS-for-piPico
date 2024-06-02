#include <stdio.h>
#include "pico/stdlib.h"
#include "threads/thread.h"
#include "lib/debug.h"
#include "misc/timer.h"




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
    printf("Hello World from thread!\n");
}



int main(){
    //Initialize I/O
    stdio_init_all();
    
    //Initialize GPIO - Green led to pin 25
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    printf("INICIANDO\n");
    

    thread_init();
    thread_start();
    //timer_init(10000); //Timer init, con 10000us = 10m

    //TIMER:
    struct repeating_timer timer;

    printf("se creó timer\n");

    add_repeating_timer_ms(10, timer_interrupt, NULL, &timer);


    struct thread *current = thread_current();
    printf("current thread: %s\n",&current->name);

    print_all_list();


    ASSERT (1 < 2); //prueba de ASSERT. Si este falla fallarán todos los de adentro.

    while(1){

        // ============== LLAMAR TESTS, VER INIT.C EN PINTOS =============
        gpio_put(25,1);
        sleep_ms(5000);
        thread_create("hola", hello_world, NULL);
        print_all_list();
        print_ready_list();
        printf("ticks: %d\n",timer_ticks());
        gpio_put(25,0);
        sleep_ms(1000);
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