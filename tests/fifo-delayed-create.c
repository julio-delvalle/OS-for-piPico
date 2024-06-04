#include <stdio.h>
#include "pico/stdlib.h"
#include "./tests.h"
#include "../threads/thread.h"
#include "../misc/timer.h"


static int count = 0;
static char nombre[] = "thread";


int64_t fifo_thread_create_alarm_callback(alarm_id_t id, void *user_data) { 
    printf("\n====================================\n\nINTERRUPT! Create thread %d\n", count); 
    sprintf(nombre, "thread%d", count);
    thread_create(nombre, NULL, NULL, 10);
    print_lists();
    count++;
    printf("\n====================================\n");
    return 98765*100;
}

void
test_fifo_delayed_create (void) 
{
    gpio_put(25,1);
    sleep_ms(1000);

    schedule_set_quantum(0,4);

    //schedule_set_quantum(1,5); //round robin mode, con cambios cada 5

    


    for(int i = 0; i<3;i++){
        sprintf(nombre, "thread%d", i);
        count++; 
        thread_create(nombre, NULL, NULL, 10);
    }

     add_alarm_in_ms(9876, fifo_thread_create_alarm_callback, NULL, false);

    

    print_lists();

    //sleep_ms(5000);
    //for(int i=0;i<100000;i++){};
    //busy_wait_ms(5000);
    
}
