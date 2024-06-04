#include <stdio.h>
#include "pico/stdlib.h"
#include "./tests.h"
#include "../threads/thread.h"
#include "../misc/timer.h"




void
test_sleep_negative (void) 
{
    gpio_put(25,1);
    sleep_ms(1000);

    schedule_set_quantum(0,5);

    int count = 0;
    char nombre[] = "thread1";


    thread_create(nombre, NULL, NULL, 15);

    print_lists();
    

    thread_sleep(-10);

    print_lists();

    //sleep_ms(5000);
    //for(int i=0;i<100000;i++){};
    //busy_wait_ms(5000);
    
}
