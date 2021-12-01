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
#include "RTD_1.h"

/*Function delcations*/
void System_Setup();
void System_On();
void System_Off();
CY_ISR_PROTO(ISR_CLOCK_handler);

/*Varible decleration*/
uint8_t Switch_State;
uint16 rtd_ratio ;
uint16 ref_res = 4300; //Reference resistance on the amplifier circuit


int main(void)
{   


    System_Setup();

    calc_Calctemp_RatiosSent_RTDresistancereceived();
    
    /*Wait for interrupts*/
    for(;;)
    {
       
    }
 
}

/*Turn system On after being in system off state*/
void System_On()
{
    //Start up the amplifier to get new temperature conversion
    Amplifier_Startup();
    
    //Start up the pump
    Pump_Startup(2500);
    
     /*Start Clock interrupt form polling temperature data.*/
    Clock_TempSampling_Start();
    /*Start counter for sampling the temperature*/
    Temp_sample_counter_Start();
    isr_clock_StartEx(ISR_CLOCK_handler); 
    
    //Turn on indicator LED
    TurnON();
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
    TurnOFF();
    
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
    
    /*Setup the two VDAC and the PGA. Stop pump from starting because of setup of transistor*/
    Pump_Setup();
     
    /*Setup SPI and then the amplifier*/
    Amplifier_Setup();
    
    /*Setup the Temperature domain class with reference resistance value*/
    Temperature_Setup(ref_res);
            
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

    //Code to fetch temperature here
    rtd_ratio = GetRtdRatio();
    
    //Set the new temperature measurement.
    SetTemperature(rtd_ratio);
       
    /*Clears counter     interrupt*/
    Temp_sample_counter_ReadStatusRegister();
}




/* [] END OF FILE */