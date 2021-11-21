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

uint16 rtd_ratio ;

int main(void)
{
    /* Enable global interrupts. */
    CyGlobalIntEnable; 
    System_Setup();
    
    SPIM_1_Start();
    
    char test = 0x80;
    
    UART_1_PutString("SPI started \r\n");
    SPIM_1_WriteTxData(test);
    
    
    UART_1_PutString("System alive\r\n");
    /*Do initial setups*/
    
    UART_1_PutString("System interrupts initiated\r\n");
    
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
    
}

/*Turn system off after being in system on state*/
void System_Off()
{
    
}


void System_Setup()
{
    CY_ISR_PROTO(ISR_CLOCK_handler);
    /* Stop pump from starting because of setup of transistor*/
    Enable_pin_Write(255); 
    
    /*Start interrupts*/
    isr_clock_StartEx(ISR_CLOCK_handler); 
    
    /*Start UART*/
    UART_1_Start();
    
    /*Setup amplifier*/
    
    
    /* Setup switch*/
    Switch_Setup();
    
    
}


CY_ISR(ISR_CLOCK_handler)
{
    
    UART_1_PutString("Counter interrupt activated \r\n");
    /*Clears counter     interrupt*/
    Temp_sample_counter_ReadStatusRegister();
}





/* [] END OF FILE */