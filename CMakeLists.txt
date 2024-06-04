cmake_minimum_required(VERSION 3.21)

include(pico_sdk_import.cmake)

project(pico-projects)

pico_sdk_init()

add_executable(main
    main.c 
    misc/list.c
    misc/timer.c
    threads/thread.c
    lib/debug.c
    lib/switch.S
    lib/switch.c
    #lib/interrupt.c
    #lib/synch.c
    lib/palloc.c
    tests/tests.c

    #listado de tests
    tests/hello-world.c
    tests/fifo-simple.c
    tests/round-robin-simple.c
    tests/round-robin-1tick.c
    tests/fifo-random-duration.c
    tests/round-robin-random-duration.c
    tests/round-robin-delayed-create.c
    tests/sleep-single.c
    tests/sleep-multiple-fifo.c
    tests/sleep-multiple-rr.c
    tests/temp-test.c
)

target_link_libraries(main pico_stdlib hardware_sync)

pico_enable_stdio_usb(main 0)
pico_enable_stdio_uart(main 1)

pico_add_extra_outputs(main)