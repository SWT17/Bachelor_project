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
#include "LEDUnitTest.h"

void LED_TURNON_CALLMETHOD_4_6VOUTPUT()
{
    Turn_ON();
}

void LED_TURNOFF_CALLMETHOD_4_6VOUTPUT()
{
    Turn_ON();
    CyDelay(100);
    Turn_OFF();
}
/* [] END OF FILE */
