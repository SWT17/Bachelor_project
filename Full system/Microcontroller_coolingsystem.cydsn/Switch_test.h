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
#include "UART_1.h"
#include "switch_input_interrupt.h"
#include "Switch_input.h"
#include "Switch_output.h"


void Switch_test_run();

CY_ISR_PROTO(switch_newState_test);

/* [] END OF FILE */
