/*
 * File:   adc.c
 * Author: LucasGabriel
 *
 * Created on 19 de Janeiro de 2023, 22:52
 */

#include "adc.h"

union
{
    uint16_t value;
    struct
    {
        uint8_t low_register;
        uint8_t high_register;
    };
} adc;

void ADC_Initializer(void)
{
    //ADCS <= Fosc/32; CHS <= 0; GOnDone <= Clear; ADON <= A/D converter is powered up 
    ADCON0 = 0x81;
    
    //ADFM <= Righ justification; ADCS2 <= Fosc/32; PCFG <= DDDDADAA; 
    ADCON1 = 0x04;
}

uint16_t ADC_Get_Value(uint8_t channel)
{
    ADCON0bits.CHS = channel;   //choose channel
    
    ADCON0bits.GO_nDONE = 0b1;  //start adc conversion
    while(ADCON0bits.GO_nDONE); //polling register
    ADCON0bits.GO_nDONE = 0b1;  //start adc conversion
    while(ADCON0bits.GO_nDONE); //polling register
    ADCON0bits.GO_nDONE = 0b1;  //start adc conversion
    while(ADCON0bits.GO_nDONE); //polling register
    
//    adc.low_register  = ADRESL; //get low register value 
//    adc.high_register = ADRESH; //get high register value
    
    return (uint16_t)ADRESH;
}
