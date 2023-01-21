/*
 * File:   system.c
 * Author: LucasGabriel
 *
 * Created on 21 de Janeiro de 2023, 13:46
 */

#include "system.h"

/**********************************************************************/
/*                      Private Functions Prototipes                  */
/**********************************************************************/
void Clock_Initializer(void);
void Pin_Initializer(void);

/**********************************************************************/
/*                              Functions                             */
/**********************************************************************/
void System_Initializer(void)
{
    Clock_Initializer();
    Pin_Initializer();
    LCD_Initializer();
    ADC_Initializer();
}

void Clock_Initializer(void)
{
    OSCCON = 0x00;
}

void Pin_Initializer(void)
{
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0x0F;
    TRISD = 0xF3;
    TRISE = 0x07;
    
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    LATD = 0x00;
    LATE = 0x00;
    
    ADCON1 |= 0x07;
}