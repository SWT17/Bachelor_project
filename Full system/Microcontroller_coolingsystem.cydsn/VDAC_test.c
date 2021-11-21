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

#include "VDAC8_1.h"
#include "PGA_1.h"
#include "UART_1.h"
#include "ReceiveBytes.h"
#include "VDAC_test.h"
#include <stdio.h>
uint8 speed;
float voltage;
static char outputBuffer[256];


void VDAC_test_run()
{
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start();
    UART_1_PutString("VDAC test begun: \r\n");
    UART_1_PutString("Initial speed = 0. \r\n");
    VDAC8_1_Start();
    PGA_1_Start();  
    speed = 0;
    
    for(;;)
    {
        
    }
    
}

CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived); // echo back
        
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case 'h' :
        {
            if(speed >=255)
            {
                speed = 255;
                UART_1_PutString("Speed at max");
            }else
            {
                speed += 1;
            }
            
            voltage = ((float)speed/255)*4096*2;
            
            snprintf(outputBuffer, sizeof(outputBuffer), "Speed = %u and Voltage = %f mV \r\n",speed,voltage);
            UART_1_PutString(outputBuffer);
            VDAC8_1_SetValue(speed);
            
        }
        break; 
        case 'l' :
        {
            if(speed <=0)
            {
                speed = 0;
                UART_1_PutString("Speed at minimum");
            }else
            {
                speed -= 1;
            }
            snprintf(outputBuffer, sizeof(outputBuffer), "Speed = %u \r\n",speed);
            UART_1_PutString(outputBuffer);
            VDAC8_1_SetValue(speed);
            
        }
        break;

    }
}

/* [] END OF FILE */
