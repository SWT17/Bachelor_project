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
#include "PumpCtrlUnitTest.h"
void Test_setup();
void setConstantSpeed_SetVoltage1_5_and2_4_SpeedIs47_and_75();

void Test_setup()
{
    UART_1_Start(); 
}

void Run_Tests()
{
    UART_1_Start();
    setConstantSpeed_SetVoltage1_5_and2_4_SpeedIs47_and_75();
}

void setConstantSpeed_SetVoltage1_5_and2_4_SpeedIs47_and_75()
{
    
    uint8 speed;
    
    UART_1_PutString("Speed control voltage set to 1500 mV\r\n");
    Pump_Startup(1500);
    speed = (1500*256)/(4096*2);;
    snprintf(outputBuffer, sizeof(outputBuffer), "Expected result is 46: result = %u;\r\n",speed);
    UART_1_PutString(outputBuffer);
    
    UART_1_PutString("Speed control voltage set to 24000 mV\r\n");
    Pump_Startup(1500);
    speed = (2400*256)/(4096*2);;
    snprintf(outputBuffer, sizeof(outputBuffer), "Expected result is 75: result = %u;\r\n",speed);
    UART_1_PutString(outputBuffer);

}

void Pump_Setup_CallMethod_CallsMethodInBody()
{
    UART_1_PutString("Expected to call methods: \r\n");
    
}

/* [] END OF FILE */
