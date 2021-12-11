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
#include "SystemControllerUnitTest.h"

void SystemController_Switchnewstate1_methodcalled_SystemOnIscalled()
{
    UART_1_Start();
    System_newState(1);
}

void SystemController_Switchnewstate0_methodcalled_SystemOffIscalled()
{
    UART_1_Start();
    System_newState(0);
}

void SystemController_ClockHandle_methodcalled_SystemOffIscalled()
{
   System_newState(1);
}
 

/* [] END OF FILE */
