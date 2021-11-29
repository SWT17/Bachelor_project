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
uint8 SetConstSpeed(uint16 speed_control_voltage);


/*Initialize the VDAC component for speed control and enabling pin*/
void Pump_Setup()
{

    //Set the range for the VDAC Speed control to the 0V-4.080V range
    VDAC8_SpeedControl_SetRange(VDAC8_SpeedControl_RANGE_4V);
    //Set initial speed to 0;
    VDAC8_SpeedControl_SetValue(0);
    
    //Set range for the VDAC for enabling through the transistor
    VDAC8_Enabling_SetRange(VDAC8_Enabling_RANGE_4V);   

    
    //Start VDAC_enabling
    VDAC8_Enabling_Start();

    //Stop pump.
    Pump_Stop();
}

/*Controlled shutdown of pump and it's software components*/
void Pump_Shutdown()
{

    //Stop VDAC in outputting the speed control voltage. Set output value to 0.
    VDAC8_SpeedControl_Stop();
    VDAC8_SpeedControl_SetValue(0);
    
    PGA_SpeedControl_Stop();
    
    //Stop the pump
    Pump_Stop();
}

/*Controlled startup of pump*/
void Pump_Startup()
{
    //Start PGA for speed control
    PGA_SpeedControl_Start();
    
    //Set speed control voltage to 2.5V
    uint8 speed = SetConstSpeed(2500);
    VDAC8_SpeedControl_SetValue(speed);
     
    //Start VDAC to output the speed control voltage
    VDAC8_SpeedControl_Start();
    
    //Call Pump start
    Pump_Start();
}


/*Start the pump by enabling it, and setting the speed control variable*/
void Pump_Start()
{
    //Enable pump through closing transistor.
    VDAC8_Enabling_SetValue(0);
    
}


/*Opens up the transistor, connecting the enable pin on pump controller
board to ground. This stop the pump.*/
void Pump_Stop()
{
    //Set the initial enabling VDAC value to 3.2V from a maximum of 4.080 from the VDAC
    VDAC8_Enabling_SetValue(4.080*3.2/255); 
}



/*Iteration 3 adjustable speed on pump
Set speed of the pump via the VDAC component*/
void SetSpeed(uint8_t speed)
{
    
    voltage = ((float)speed/256)*4096*2; //Calculate the new voltage for the speed control.
    
    /*Check if voltage is below zero == speed has become negative*/
    if(voltage < 0)
    {
        VDAC8_SpeedControl_SetValue(0);       
    }
    /*Check if voltage is above maximum*/
    else if(voltage > 4500)
    {
        speed = (uint8)((4500 * 255) / (4096 * 2)); //Maximum speed when PGA gain is 2.
        VDAC8_SpeedControl_SetValue(speed);
    }
    else
    {
        VDAC8_SpeedControl_SetValue(speed);
    }
    
    
}


uint8 SetConstSpeed(uint16 speed_control_voltage)
{
    uint8 const_speed = (speed_control_voltage*256)/(4096*2); //Calculate the speed corresponding to 2.5V output
    return const_speed;
}
/* [] END OF FILE */
