#include <stdio.h>
#include "pico/stdlib.h"
#include "./tests.h"
#include "../threads/thread.h"
#include "../misc/timer.h"




void
test_sleep_multiple_rr (void) 
{
    gpio_put(25,1);
    sleep_ms(1000);

    schedule_set_quantum(1,4);

    int count = 0;
    char nombre[] = "thread";


    for(int i = 0; i<5;i++){
        sprintf(nombre, "thread%d", i);
        count++; 
        thread_create(nombre, NULL, NULL, 3*(i+1));
        thread_sleep(5*(i+1));
    }

    print_lists();

    //sleep_ms(5000);
    //for(int i=0;i<100000;i++){};
    //busy_wait_ms(5000);
    
}
