#include "adc.h"
#include "leds.h"
#include <stdint.h>

void adc_init()
{
    TRISCbits.TRISC6 = 1; //Input based on Protoboard
    //TRISBbits.TRISB1= 1;
    //TRISBbits.TRISB0 = 1;
    
    ANSELC = 0; //DISABLE ANALOG INPUT ON PORT C, then enable port 6
    ANSELCbits.ANSELC6 = 1; //Analog based on protoboard
    //ANSELBbits.ANSELB1 = 1;
    //ANSELBbits.ANSELB0 = 1;
    
    ADCON0bits.ON = 1; //ADC is enabled
    ADCON0bits.CS = 1; //Clock supplied from FRC deticated oscillator
    ADCON0bits.FM = 1; //Data is right justified
    PIE1bits.ADIE = 1; //Set interrupt enable bit
    ADREFbits.PREF = 0b00; //Positive reference voltage is VDD
    ADREFbits.NREF = 0; //Negative reference voltage is VSS
}

void adc_interrupt_handler()
{ 
    //testing led
    WHITE_LED = !WHITE_LED;
   
    PIR1bits.ADIF = 0; //Clear adc interrupt flag
    
    uint8_t sensor_identifier = ADPCH - 8;
    
    uint8_t result_high = ADRESH;
    uint8_t result_low = ADRESL;
    
    ADCON0bits.ON = 0; //Turn off ADC
    
    can_msg_t radiation_msg;

    uint16_t adc_res = ((uint16_t) (result_high) << 8) | (uint16_t) (result_low);
    
    build_radi_info_msg(millis(), sensor_identifier, adc_res, &radiation_msg);
    BLUE_LED = !BLUE_LED;
    txb_enqueue(&radiation_msg);
}