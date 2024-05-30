cmake_minimum_required(VERSION 3.21)

include(pico_sdk_import.cmake)

project(pico-projects)

pico_sdk_init()

add_executable(main
    main.c 
    misc/list.c
    misc/timer.c
    threads/thread.c
    threads/interrupt.c
    lib/debug.c
)

target_link_libraries(main pico_stdlib)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

pico_add_extra_outputs(main)