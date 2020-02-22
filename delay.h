#include <stdio.h>
#include <time.h>

void delay_time(int segundos) 
{ 
    int millisegundos = 1000 * segundos; 
    clock_t relogio = clock(); 
    while (clock() < relogio + millisegundos) 
        ; 
} 