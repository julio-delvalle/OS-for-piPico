#include <stdio.h>
#include "pico/stdlib.h"
#include "threads/thread.h"
#include "lib/debug.h"



void hello_world(void){
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
        gpio_put(25,0);
        sleep_ms(1000);
    }
}
