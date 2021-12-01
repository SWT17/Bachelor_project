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
#include "LED.h"

void TurnON()
{
    LED_pin_Write(255);
}
void TurnOFF()
{
    LED_pin_Write(0);
}

/* [] END OF FILE */
