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
#include "Switch_test.h"



void Switch_test_run()
{
    //Set voltage to HW switch input pin to high.  
    Switch_output_Write(255);
    UART_1_Start();
    switch_input_interrupt_StartEx(switch_newState_test);
    UART_1_PutString("Switch test has been started \r\n");
    
    for(;;)
    {
    }
}

CY_ISR(switch_newState_test)
{
    UART_1_PutString("Switch has been triggered \r\n");
    /*Clears interrupts and enable detection of future interrupts*/
    Switch_input_ClearInterrupt();
}
/* [] END OF FILE */
