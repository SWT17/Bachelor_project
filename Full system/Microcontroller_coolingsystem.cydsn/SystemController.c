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

#include "SystemController.h"


CY_ISR_PROTO(ISR_CLOCK_handler);

uint8_t Switch_State;
uint16 rtd_ratio ;
uint16 ref_res = 4300;
char bit;


int main(void)
{   

    
    System_Setup();
    
    /*Start counter*/
    Temp_sample_counter_Start();
    
    
    for(;;)
    {
        /* Place your application code here. */
    }
 
}

/*Turn system On after being in system off state*/
void System_On()
{
    //Start up the amplifier to get new temperature conversion
    Amplifier_Startup();
    
    //Start up the pump
    Pump_Startup();
    
     /*Start Clock interrupt form polling temperature data.*/
    Clock_TempSampling_Start();
    isr_clock_StartEx(ISR_CLOCK_handler); 
    
    //Turn on indicator LED
    LED_pin_Write(255);
}

/*Turn system off after being in system on state*/
void System_Off()
{
    //Stop the clock interrupt routine
    isr_clock_Disable();
    
    //Shut down the pump
    Pump_Shutdown();
    
    //Shutdown the amplifier
    Amplifier_Shutdown();
    
    //Turn off the indicator LED
    LED_pin_Write(0);
    
}


void System_Setup()
{
    /* Enable global interrupts. */
    CyGlobalIntEnable; 
    //System is off, set state to 0.
    Switch_State = 0;
    
    /*Start UART*/
    UART_1_Start();
    
    /*Set up input voltage to HIGH on HW switch input pin*/     
    Switch_Setup();
    
    /* Stop pump from starting because of setup of transistor*/
    Pump_Setup();
     
    /*Setup amplifier*/
    Amplifier_Setup();
    
    /*Setup the Temperature domain class with reference resistance value*/
    Temperature_Setup(ref_res);
        
    /* Setup switch*/
    Switch_Setup();
    
}

void System_newState()
{
    if(!Switch_State)
    {
        //Set new state to 0.
        Switch_State = 1;
        //Turn system on. 
        System_On();
        
    }else
    {
        //New state 1.
        Switch_State = 0;
        //Turn system off. 
        System_Off();
    }
}

CY_ISR(ISR_CLOCK_handler)
{
    
    UART_1_PutString("Counter interrupt activated \r\n");
    
    //Code to fetch temperature here
    rtd_ratio = GetRtdRatio();
    
    //Set the new temperature measurement.
    SetTemperature(rtd_ratio);
       
    /*Clears counter     interrupt*/
    Temp_sample_counter_ReadStatusRegister();
}




/* [] END OF FILE */