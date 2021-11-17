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
#include "project.h"
CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);
uint8 Speed = 50;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start();
    PWM_1_Start();
    PWM_1_WriteCompare1(Speed);
    UART_1_PutString("PWM started\r\n");

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}


CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        //UART_1_WriteTxData(byteReceived); // echo back
        
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}
void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case 'q' :
        { 
            Speed = Speed+1;
            UART_1_PutString("PWM increased\r\n");
           PWM_1_WriteCompare1(Speed);
        }
        break;
        case 'p' :
        { 
            Speed = Speed-1;
            UART_1_PutString("PWM decreased\r\n");
           PWM_1_WriteCompare1(Speed-1);
        }
        break;

        
    }
}

/* [] END OF FILE */