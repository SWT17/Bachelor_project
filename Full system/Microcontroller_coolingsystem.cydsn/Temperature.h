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
#include <math.h>
#include "RTD_1.h"


float GetTemperature();
void SetTemperature(uint16 rtd_ratio);
void Temperature_Setup(uint16_t ref_res);

/* [] END OF FILE */
