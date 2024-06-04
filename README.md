# OS for Raspberry Pi Pico
---
Julio Del Valle - 21000492   
Eddy Montenegro - 21000630   
Diego Bances - 20001745   

## Pasos para compilar

Se necesitan las siguientes herramientas y librerías:
Arm GCC Compiler: https://developer.arm.com/downloads/-/gnu-rm
CMake: https://cmake.org/download/ 
Build Tools for Visual Studio 2019: https://visualstudio.microsoft.com/es/downloads/
Python 3: https://www.python.org/downloads/windows/
Git: https://git-scm.com/download/win
Visual Studio Code: https://code.visualstudio.com/Download 

El proyecto actualmente está configurado para Debug usando otra Pico, para compilar para una sola Raspberry en CMakeLists cambiar estas instrucciones, para que la comunicación sea por medio de USB:
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

* Elegir una carpeta donde se va a hacer el proyecto, y agregar el pico-sdk: https://github.com/raspberrypi/pico-sdk
* Desde una Developer Command Prompt for VS, setear la environment variable PICO_SDK_PATH 
* Para compilar, utilizar el comando cmake desde build
* Esto genera un archivo main.uf2
* Conectar la Pico en modo configuración, y colocar el main.uf2 dentro.
* Por medio de una terminal como PuTTY se puede ver la comunicación serial por USB.
* Puede utilizar este videop para una explicación paso a paso de cómo configurar su computadora WINDOWS para ejecutar programas de la Pico. https://youtu.be/mUF9xjDtFfY?si=4lQ4AfsMHvW7GWfi

## Tests:

1: Hello-World: Imprime Hello World desde thread main.

2. fifo-simple: Crea 5 threads con duración 10 ticks, y los ejecuta con FIFO

3. round-robin-simple: Crea 5 threads con duración 10 ticks, y los ejecuta con Round Robin

4. round-robin-1tick: Crea 5 threads con duración 10 ticks, pero ahora el Round Robin hace yield cada UN (1) tick.

5. fifo-random-duration: Crea 5 threads con duración RANDOM, y los ejecuta con FIFO

6. round-robin-random-duration: Crea 5 threads con duración RANDOM, y los ejecuta con Round Robin

7. fifo-delayed-create: Crea 3 threads, y luego cada aprox 10 segundos se forza una interrupción y se crea otro thread. Implementado con FIFO

8. round-robin-delayed-create: Crea 3 threads, y luego cada aprox 10 segundos se forza una interrupción y se crea otro thread. Implementado con Round Robin

9. sleep-single: Crea un (1) thread y lo manda a dormir 25 ticks.

10. sleep-multiple-fifo: Crea 5 threads, los manda a todos a dormir duraciones diferentes, y luego al despertarse los ejecuta con FIFO

11. sleep-multiple-round-robin: Crea 5 threads, los manda a todos a dormir duraciones diferentes, y luego al despertarse los ejecuta con Round Robin

12. sleep-negative: Crea un (1) thread y lo manda a dormir con duración negativa. Esta es una prueba de comportamiendo.

13. fifo-force-exit: Crea 5 threads, pero a los 8 segundos FORZA una interrupción que hace thread_exit del que esté ejecutándose. Implementado con FIFO.

14. round-robin-force-exit: Crea 5 threads, pero a los 8 segundos FORZA una interrupción que hace thread_exit del que esté ejecutándose. Implementado con Round Robin.

15. manual-set-round-robin: Pregunta al usuario cuántos ticks desea para el round robin. Crea 5 threads y los ejecuta con Round Robin con la duración elegida por el usuario.




## Recursos utilizados:

* Pi pico SDK: https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf
* Getting Started with Pi Pico https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf
* Raspberry Pi Pico using C/C++ https://www.youtube.com/playlist?list=PLUwmiNOPP-7hAXx4AmiWiWTyBqumqbIKT
* Raspberry Pi Pico Lecture 3: Timers, timer interrupts, SPI https://www.youtube.com/watch?v=KCGy7Gz1QrE&t=716s&ab_channel=VanAdams