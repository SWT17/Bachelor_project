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
#include "PumpCtrl.h"

float voltage;
void SetSpeed(uint8_t speed);


/*Initialize the VDAC component for speed control*/
void Pump_Setup()
{
    //Set the range for the VDAC to the 0V-4.096V range
    VDAC8_1_SetRange(VDAC8_1_RANGE_4V);
    //Set initial speed to 0;
    VDAC8_1_SetValue(0);
    //Start the VDAC
    VDAC8_1_Start();      
}

/*Controlled shutdown of pump*/
void Pump_Shutdown()
{
}

/*Controlled startup of pump*/
void Pump_Startup()
{
}


/*Start the pump by enabling it, and setting the speed control variable*/
void Pump_Start()
{
    
}
void Pump_Stop()
{
    
}

/*Set speed of the pump via the VDAC component*/
void SetSpeed(uint8_t speed)
{
    
    voltage = ((float)speed/256)*4096*2; //Calculate the new voltage for the speed control.
    
    /*Check if voltage is below zero == speed has become negative*/
    if(voltage < 0)
    {
        VDAC8_1_SetValue(0);       
    }
    /*Check if voltage is above maximum*/
    else if(voltage > 4500)
    {
        speed = (uint8)((4500 * 255) / (4096 * 2)); //Maximum speed when PGA gain is 2.
        VDAC8_1_SetValue(speed);
    }
    else
    {
        VDAC8_1_SetValue(speed);
    }
    
    
}
/* [] END OF FILE */
