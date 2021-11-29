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
#include "project.h"
#include "switch.h"
#include "Amplifier.h"
#include "PumpCtrl.h"
#include "Temperature.h"
#include "SystemController.h"
#include "SystemController_interrupt.h"

#include <stdio.h>

//Test includes
#include "Switch_test.h"
#include "SPI_test.h"
#include "TempSensor_test.h"


//Function delcations
void System_Setup();
void System_On();
void System_Off();


/* [] END OF FILE */
