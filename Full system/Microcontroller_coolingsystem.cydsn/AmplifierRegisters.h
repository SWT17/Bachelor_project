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

#define READ_CONFIG_REG_ADRESS   0x00
#define WRITE_CONFIG_REG_ADRESS  0x80
#define READ_RTD_MSB_REG_ADRESS  0x01
#define READ_RTD_LSB_REG_ADRESS  0x02
#define SHUTDOWN                 0x01
#define STARTUP                  0xC3

#define TWO_OR_FOUR_WIRECONFIG   0x00
#define THREE_WIRECONFIG         0x10
#define FILTER_50HZ              0x01
#define FILTER_60HZ              0x00
#define VBIAS_ON                 0x80
#define VBIAS_OFF                0x00
#define CONVERSIONMODE_AUTO      0x40
#define CONVERSIONMODE_OFF       0x00
#define CLEAR_FAULTBIT           0x02




/* [] END OF FILE */
