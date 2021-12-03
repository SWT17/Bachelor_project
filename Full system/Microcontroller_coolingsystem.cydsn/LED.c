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

void Turn_ON()
{
    LED_pin_Write(255);
}
void Turn_OFF()
{
    LED_pin_Write(0);
}

/* [] END OF FILE */
