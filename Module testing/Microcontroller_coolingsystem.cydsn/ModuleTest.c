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
#include "ModuleTest.h"
CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);

float Speed = 0.496*256 / 4.096;
float Vout = 0.496;
static char outputBuffer[256];

uint8 start = 0;

void Init_testsetup()
{
      
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_uart_rx_StartEx(ISR_UART_rx_handler); /* setup uart interrupt handle */
    UART_1_Start(); /* start uart */
    PGA_1_Start();
    

}


void Start_test()
{
     while(start == 0) /* Wait for start signal from actor */
    {
    }
    
    VDAC8_1_Start(); /* Start VDAC */

    UART_1_PutString("PGA and VDAC started \r\n"); 
    snprintf(outputBuffer, sizeof(outputBuffer), "Initial Speed %f corresponding voltage %f \r\n", Speed, Vout);
    UART_1_PutString(outputBuffer);  /* Output initial status message - VDAC started, initial speed and voltage */
   
    for(;;)  /* run infinite loop */
    {
    }
    
}


CY_ISR(ISR_UART_rx_handler)  /* Interrupt handler - reading byte sent */
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
void handleByteReceived(uint8_t byteReceived)  /* Method to translate incoming byte into actions */
{
    switch(byteReceived)
    {
        case 'q' :
        {
            if(Speed<255)
            {
                Speed = Speed+1;
                Vout = (Speed/256) * 4.096;
                VDAC8_1_SetValue(Speed);
                snprintf(outputBuffer, sizeof(outputBuffer), "Speed is increased to %fV; \r\n", Vout);
                UART_1_PutString(outputBuffer);
                snprintf(outputBuffer, sizeof(outputBuffer), "Speed increased to %f corresponding voltage %f \r\n", Speed, Vout);
                UART_1_PutString(outputBuffer);
            }else
            {
                UART_1_PutString("Speed is at maximum 4.096V \r\n");
            }
            
        }
        break;
        case 'p' :
        { 
            if(Speed > 1)
            {
                Speed = Speed-1;
                Vout = (Speed/256) * 4.096;
                VDAC8_1_SetValue(Speed);
                snprintf(outputBuffer, sizeof(outputBuffer), "Speed decreased to %fV corresponding voltage %f \r\n",Speed, Vout);
                UART_1_PutString(outputBuffer);
            }else
            {
                UART_1_PutString("Speed is at minimum 0V \r\n");
            }
        }
        case 's':
        {
            start=1;
        }
        
        break;

        
    }
}

/* [] END OF FILE */
