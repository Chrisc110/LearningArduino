#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pic18f26k83.h>
#include "led.h"

void led_init(){
    TRISBbits.TRISB2 = 0; //set output
    TRISBbits.TRISB3 = 0;
    //TRISBbits.TRISB4 = 0;
    TRISB4 = 0;
    LATB4 = 1;
    
    
    LATBbits.LATB2 = 1;
    LATBbits.LATB3 = 1;
    //LATBbits.LATB4 = 0;
}