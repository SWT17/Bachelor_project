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
#include "MaxanalogOutput.h"

uint8 speed;
uint16 voltage;
void maxAnalogOutputTest()
{
    PGA_SpeedControl_Start();
    VDAC8_SpeedControl_Start();
    
    voltage = 4000;
    speed = (voltage*256)/(4080*2);
    
    VDAC8_SpeedControl_SetValue(speed);
      
}
/* [] END OF FILE */
