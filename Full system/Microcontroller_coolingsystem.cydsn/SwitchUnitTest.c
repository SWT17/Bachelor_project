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
#include "SwitchUnitTest.h"

void SwitchSetup_CallMethod_CorrectMethodsCalled()
{
    Switch_Setup();
}

void SwitchShutdown_CallMethod_CorrectMethodsCalled()
{
    Switch_output_Write(255);
    CyDelay(300);
    Switch_Shutdown();
}



/* [] END OF FILE */
