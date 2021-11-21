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

#include "Switch_input.h"
#include "switch_input_interrupt.h"

void Switch_Setup();
/*Setup interrupt handler*/
CY_ISR_PROTO(switch_newState);

/* Declared functions for Switch class*/
CY_ISR(switch_newState);

/* [] END OF FILE */
