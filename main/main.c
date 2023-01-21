/*
 * File:   main.c
 * Author: LucasGabriel
 *
 * Created on 19 de Janeiro de 2023, 22:09
 */


#include "system.h"

void main(void) 
{
    System_Initializer();
    
    uint16_t sensor_value = 0; 
    uint8_t channel = 0;
    printf("S1:");
    LCD_Move_Cursor(2,1);
    printf("S2:");
    
    while(1)
    {
        channel ^= 1;
        sensor_value = ADC_Get_Value(channel);
        LCD_Move_Cursor(channel+1,4);
        printf("     ");
        LCD_Move_Cursor(channel+1,4);
        
        if(1 == channel)
            sensor_value = (uint16_t)((sensor_value/255.0)*100);
        
        printf("%3.0u",sensor_value);
        __delay_ms(500);
    }
}
