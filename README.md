# OS-for-piPico



### Tests:

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