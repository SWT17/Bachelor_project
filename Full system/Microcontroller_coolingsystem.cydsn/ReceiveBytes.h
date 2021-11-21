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
#include "isr_uart_rx.h"
#include "UART_1.h"

void handleByteReceived(uint8_t byteReceived);
CY_ISR_PROTO(ISR_UART_rx_handler);

/* [] END OF FILE */
