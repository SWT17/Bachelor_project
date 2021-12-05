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
#include "UART_1.h"

float voltage;
uint8 output_voltage;
uint8 speed;
uint8 const_speed;
uint8 output_voltage_direction;

void SetSpeed(uint8_t speed);
uint8 SetConstSpeed(uint16 speed_control_voltage);


/*Initialize the VDAC component for speed control and enabling pin*/
void Pump_Setup()
{
    output_voltage = 0;
    //Start VDAC_enabling
    VDAC8_Enabling_Start();
        //Set range for the VDAC for enabling through the transistor
    VDAC8_Enabling_SetRange(VDAC8_Enabling_RANGE_4V); 
    
    

    //Stop pump.
    Pump_Stop();
}

/*Controlled shutdown of pump and it's software components*/
void Pump_Shutdown()
{

    //Stop VDAC in outputting the speed control voltage. Set output value to 0.
    VDAC8_SpeedControl_SetValue(0);
    VDAC8_SpeedControl_Stop();
    
    PGA_SpeedControl_Stop();
    
    //Stop the pump
    Pump_Stop();
}

/*Controlled startup of pump*/
void Pump_Startup(uint16 constVoltage)
{
    //Start VDAC to output the speed control voltage
    VDAC8_SpeedControl_Start();
    //Start PGA for speed control
    PGA_SpeedControl_Start();
    

    //Set speed control voltage to 2.5V
    speed = SetConstSpeed(constVoltage);
    VDAC8_SpeedControl_SetValue(speed);
     
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
    output_voltage = (uint8)(4080 * 255/(4080));
    VDAC8_Enabling_SetValue(output_voltage); 
    
}





/*Set a constant hardcoded speed for the speed control.*/
uint8 SetConstSpeed(uint16 speed_control_voltage)
{
    const_speed = (speed_control_voltage*256)/(4080*2); //Calculate the speed corresponding to 2.5V output
    return const_speed;
}


/*Method for controlling the direction of flow
when regulating the temperature with on/off regulation*/



/* [] END OF FILE */
