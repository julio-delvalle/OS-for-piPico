#include <stdio.h>
#include "pico/stdlib.h"
#include "./tests.h"
#include "../threads/thread.h"
#include "../misc/timer.h"


static int count = 0;
static char nombre[] = "thread";


int64_t fifo_force_thread_exit_callback(alarm_id_t id, void *user_data) { 
    printf("\n====================================\n\nInterrupt! thread exit \n", count); 
    set_thread_exit_on_return();
    printf("\n====================================\n");
    return 0;
}

void
test_fifo_force_exit (void) 
{
    gpio_put(25,1);
    sleep_ms(1000);

    schedule_set_quantum(0,4);

    //schedule_set_quantum(1,5); //round robin mode, con cambios cada 5

    


    for(int i = 0; i<5;i++){
        sprintf(nombre, "thread%d", i);
        count++; 
        thread_create(nombre, NULL, NULL, 5);
    }

     add_alarm_in_ms(8000, fifo_force_thread_exit_callback, NULL, false);

    

    print_lists();

    //sleep_ms(5000);
    //for(int i=0;i<100000;i++){};
    //busy_wait_ms(5000);
    
}
