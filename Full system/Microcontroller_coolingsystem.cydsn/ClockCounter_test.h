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
#include "Temp_sample_counter.h"
#include "ReceiveBytes.h"
#include "isr_clock.h"

void ClockCounter_test_run();
CY_ISR_PROTO(ISR_CLOCK_test_handler);


/* [] END OF FILE */
