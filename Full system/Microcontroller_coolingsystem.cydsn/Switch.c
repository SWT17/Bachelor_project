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

#include "switch.h"
#include "UART_1.h"

/*Setup interrupt handler*/
CY_ISR_PROTO(switch_newState);

/* Declared functions for Switch class*/
CY_ISR(switch_newState);

/* Do inital setup of interrupt and internal state*/
void Switch_Setup()
{
    //Set High input to the switch priming it.
    Switch_Startup();
    
    //Enable the interrupt on the switch.
    switch_input_interrupt_StartEx(switch_newState);

    
}

/*Controlled shutdown on switch, shutoff the input power for the switch disabling it*/
void Switch_Shutdown()
{
    Switch_output_Write(0);
}

/*Startup of the switch. Enable the input power enabling the switch*/
void Switch_Startup()
{
    Switch_output_Write(255);
}

/*Interrupt handler for the switch interrupt*/
CY_ISR(switch_newState)
{    
    UART_1_PutString("Switch has been triggered \r\n");
    /*Clears interrupts and enable detection of future interrupts*/
    Switch_input_ClearInterrupt();
    

    //Call system controller that new state is triggered.
    System_newState();
    
    
}

/* [] END OF FILE */
