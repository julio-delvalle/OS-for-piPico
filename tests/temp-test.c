#include <stdio.h>
#include "pico/stdlib.h"
#include "./tests.h"
#include "../threads/thread.h"
#include "../misc/timer.h"





void hello_world(void *t);

void hello_world(void* t){
    msg("Hello World from thread!\n");
}



void
test_temp_test (void) 
{
    gpio_put(25,1);
    sleep_ms(5000);

    int count = 0;
    char nombre[] = "hola";


    for(int i = 0; i<5;i++){
        sprintf(nombre, "hola%d", i);
        count++; 
        thread_create(nombre, hello_world, NULL, 10*(i+1));
    }

    printf("ALL: ");
    print_all_list();
    printf("READY: ");
    print_ready_list();
    printf("BLOCKED: ");
    print_blocked_list();
    printf("ticks: %d\n",timer_ticks());
    gpio_put(25,1);

    //sleep_ms(5000);
    for(int i=0;i<100000;i++){};
    printf("FUERA DE FOR WAIT\n");
    busy_wait_ms(5000);
    
}
