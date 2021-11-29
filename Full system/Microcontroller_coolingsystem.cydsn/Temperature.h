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
#include "RTD_1.h"

void Temperature_Setup(uint16_t ref_res);
uint8_t GetTemperature();
void SetTemperature(uint16_t rtd_ratio);

/* [] END OF FILE */
