#include <stdio.h>
#include "pico/stdlib.h"
#include "./tests.h"
#include "../threads/thread.h"
#include "../misc/timer.h"


static int count = 0;
static char nombre[] = "thread";


int64_t rr_thread_create_alarm_callback(alarm_id_t id, void *user_data) { 
    printf("\n====================================\n\nTimer fired! Create thread %d\n", count); 
    sprintf(nombre, "thread%d", count);
    thread_create(nombre, NULL, NULL, 20);
    print_lists();
    count++;
    printf("\n====================================\n");
    return 65432*100;
}

void
test_round_robin_delayed_create (void) 
{
    gpio_put(25,1);
    sleep_ms(1000);

    schedule_set_quantum(1,4);

    //schedule_set_quantum(1,5); //round robin mode, con cambios cada 5

    


    for(int i = 0; i<3;i++){
        sprintf(nombre, "thread%d", i);
        count++; 
        thread_create(nombre, NULL, NULL, 10);
    }

     add_alarm_in_ms(6543, rr_thread_create_alarm_callback, NULL, false);

    

    print_lists();

    //sleep_ms(5000);
    //for(int i=0;i<100000;i++){};
    //busy_wait_ms(5000);
    
}
