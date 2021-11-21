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

char READ_Config_Reg_Adress = 0x0;
char WRITE_Config_Reg_Adress = 0x80;
char READ_RTD_MSB_Reg_Adress = 0x1;
char READ_RTD_LSB_Reg_Adress = 0x2;

//Initial amplifier start up setup
//VBIAS =1 , Conversion mode = 1, 1-shot = 0, 2-wire = 0, Faultdetection = 0, Fault deteciton = 0, Fault status = 0, 50/60Hz = 0;
char Amplifier_Config = 0xc0; 

/* [] END OF FILE */
