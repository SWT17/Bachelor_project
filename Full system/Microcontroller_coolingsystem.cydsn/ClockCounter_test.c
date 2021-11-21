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
#include "ClockCounter_test.h"

void ClockCounter_test_run()
{  
    UART_1_Start();
    UART_1_PutString("CLock counter test started \r\n");
    /*Start interrupts*/
    isr_clock_StartEx(ISR_CLOCK_test_handler); 
    Temp_sample_counter_Start();
    
    for(;;)
    {
    }
}

CY_ISR(ISR_CLOCK_test_handler)
{
    UART_1_PutString("Clock counter triggered \r\n");
    Temp_sample_counter_ReadStatusRegister();
}

/* [] END OF FILE */
