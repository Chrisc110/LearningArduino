#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pic18f26k83.h>
#include "leds.h"

void led_init(){
    TRISBbits.TRISB2 = 0; //set output
    TRISBbits.TRISB3 = 0;
    TRISBbits.TRISB4 = 0;
    
    LATBbits.LATB2 = 1;
    LATBbits.LATB3 = 1;
    LATBbits.LATB4 = 1;
}