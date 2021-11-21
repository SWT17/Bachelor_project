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
#include "Switch.h"
#include "UART_1.h"
#include "SystemController.h"

uint8_t Switch_State; //State off the system. 0 = System OFF , 1 = System ON

/* Do inital setup of interrupt and internal state*/
void Switch_Setup()
{
    //Set state to 0, system off.
    Switch_State = 0;
    
    //Enable the interrupt on the switch.
    switch_input_interrupt_StartEx(switch_newState);
    UART_1_PutString("Switch setup done\r\n");
    
}

void Switch_on()
{
    //Start system by calling system controller.
    System_On();
}

void Switch_off()
{
    //Shutdown system by calling system controller
    System_Off(); 
}


/*Interrupt handler for the switch interrupt*/
CY_ISR(switch_newState)
{
    if(!Switch_State)
    {
        //Set new state to 0.
        Switch_State = 1;
        //Turn system on. 
        Switch_on();
        
    }else
    {
        //New state 1.
        Switch_State = 0;
        //Turn system off. 
        Switch_off();
        
    }
    
    UART_1_PutString("Switch interrupt activated \r\n");
    
    /*Clears interrupts and enable detection of future interrupts*/
    Switch_input_ClearInterrupt();
}

/* [] END OF FILE */
