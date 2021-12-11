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
#pragma once
#include "PumpCtrl.h"
#include "UART_1.h"

void Run_Tests();
void Pump_StartPump_CallMethod_PumpStarted();
void Pump_PumpStartUp_CallMethod_CorrectMethodsCalled();
void Pump_SetConstSpeed_CallMethodWith63_OutputIs2V();
void Pump_SetConstSpeed_CallMethodWith94_OutputIs3V();
void Pump_PumpStop_CallMethod_OutputIs4_6VOnPin02();
/* [] END OF FILE */
