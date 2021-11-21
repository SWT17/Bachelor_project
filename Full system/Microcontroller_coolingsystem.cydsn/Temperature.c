/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
/*Include files*/
#include "Temperature.h"
/*Delcared internal variables*/
uint8_t Temperature;
uint16_t Ref_resistance;
/*Declared internal functions*/
void calc_temp(float rtd_ratio);



void Temperature_Setup()
{
    Ref_resistance = 4300;
}
void calc_temp(float rtd_ratio)
{
    //Evt haps koden fra arduinoen.
}

/* [] END OF FILE */
