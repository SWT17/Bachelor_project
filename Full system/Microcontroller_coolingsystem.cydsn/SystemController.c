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
uint8 Switch_State;
uint16 rtd_ratio ;
uint16 ref_res = 4300; //Reference resistance on the amplifier circuit
float last_regu;
float regu;


int main(void)
{   

    Pump_PumpStop_CallMethod_OutputIs4_6VOnPin02();    
//    System_Setup();
    
    
    /*Wait for interrupts*/
    for(;;)
    {
       
    }
 
}

//Initial setup upon Powering the PSOC
void System_Setup()
{
    /* Enable global interrupts. */
    CyGlobalIntEnable; 
    //System is off, set state to 0.
    Switch_State = 0;
    last_regu = 0;
       
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



/*Turn system On after being in system off state*/
void System_On()
{
    UART_1_PutString("SystemOn called \r\n");
    //Start up the amplifier to get new temperature conversion
    Amplifier_Startup();
    
    //Start up the pump
    Pump_Startup(2500);
    
    /*Start counter for sampling the temperature*/
    Temp_sample_counter_Start();
    Clock_TempSampling_Start();
    isr_clock_StartEx(ISR_CLOCK_handler); 
    
    //Turn on indicator LED
    Turn_ON();
}

/*Turn system off after being in system on state*/
void System_Off()
{
    UART_1_PutString("SystemOff called \r\n");
    //Stop the clock interrupt routine
    isr_clock_Disable();
    
    //Stop the clock of the temperature sampling
    Temp_sample_counter_Stop();
    Clock_TempSampling_Stop();
    
    //Shut down the pump
    Pump_Shutdown();
    
    //Shutdown the amplifier
    Amplifier_Shutdown();
    
    //Turn off the indicator LED
    Turn_OFF();
    
}





void System_newState(uint8 switchstate)
{
    Switch_State = switchstate;
    
    if(Switch_State)
    {
        //Turn system on. 
        System_On();
        
    }else
    {
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
    
    //Get temperature sample and print to uart
    char temp[50];
            
    float temp_string = GetTemperature();
    sprintf(temp,"Temperature: %f\n\r",temp_string);
    UART_1_PutString(temp);
    
     /*Clears counter     interrupt*/
    Temp_sample_counter_ReadStatusRegister();
}




/* [] END OF FILE */