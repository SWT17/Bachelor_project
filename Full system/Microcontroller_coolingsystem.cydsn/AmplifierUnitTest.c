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
#include "AmplifierUnitTest.h"


void Amplifier_AmplifierSetup_MethodCalled_SubsequentMethodCallsAsExpected()
{
    UART_1_Start();
    Amplifier_Setup();
}

void Amplifier_AmplifierShutdown_MethodCalled_SubsequentMethodCallsAsExpected()
{
    UART_1_Start();
    Amplifier_Setup();
}

void Amplifier_AmplifierStartup_MethodCalled_SubsequentMethodCallsAsExpected()
{
    UART_1_Start();
    Amplifier_Startup();
}

void Amplifier_AmplifierGetRtdRatio_MethodCalled_SubsequentMethodCallsAsExpected()
{
    UART_1_Start();

    uint16 res = GetRtdRatio();
    
    char temp[50];
            
    sprintf(temp,"Temperatur: %u \n\r",res);
    UART_1_PutString(temp);
}
/* [] END OF FILE */

