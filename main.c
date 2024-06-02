#include <stdio.h>
#include "pico/stdlib.h"
#include "threads/thread.h"
#include "lib/debug.h"


int main(){
    //Initialize I/O
    stdio_init_all();
    
    //Initialize GPIO - Green led to pin 25
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    printf("INICIANDO\n");

    thread_init();

    ASSERT (1 < 2);

    while(1){
        gpio_put(25,1);
        thread_create(NULL, NULL, NULL);
        sleep_ms(1000);
        gpio_put(25,0);
        sleep_ms(1000);
    }
}