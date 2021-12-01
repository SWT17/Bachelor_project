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
#include <stdio.h>
#include "VDAC8_SpeedControl.h"
#include "PGA_SpeedControl.h"
#include "VDAC8_Enabling.h"
#include "Enable_pin.h"

void Pump_Setup();
void Pump_Shutdown();
void Pump_Startup(uint16 constVoltage);
void Pump_Stop();
void Pump_Start();



/* [] END OF FILE */
