#include <stdio.h>
#include "pico/stdlib.h"
#include "./tests.h"
#include "../threads/thread.h"
#include "../misc/timer.h"




void
test_round_robin_simple (void) 
{
    gpio_put(25,1);
    sleep_ms(1000);

    schedule_set_quantum(1,5);

    //schedule_set_quantum(1,5); //round robin mode, con cambios cada 5

    int count = 0;
    char nombre[] = "thread";


    for(int i = 0; i<5;i++){
        sprintf(nombre, "thread%d", i);
        count++; 
        thread_create(nombre, NULL, NULL, 10);
    }

    print_lists();

    //sleep_ms(5000);
    //for(int i=0;i<100000;i++){};
    //busy_wait_ms(5000);
    
}
