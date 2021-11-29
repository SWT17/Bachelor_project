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

#include "TempSensor_test.h"
#include "SS.h"

char test_READ_Config_Reg_Adress = 0x00;
char test_WRITE_Config_Reg_Adress = 0x80;
char test_READ_RTD_MSB_Reg_Adress = 0x1;
char test_READ_RTD_LSB_Reg_Adress = 0x2;
char test_READ_fault_Reg_adress = 0x07;

//Initial amplifier start up setup
//VBIAS =1 , Conversion mode = 1, 1-shot = 0, 2-wire = 0, Faultdetection = 0, Fault deteciton = 0, Fault status = 0, 50/60Hz = 0;
char test_Amplifier_Config = 0xC1; 

char config_reg;
char rx_stat;
char tx_stat;

void TempSensor_testrun()
{
    SPIM_1_Start();
    for(;;)
    {
        
        //Read the config register on max31865
        SS_Write(0);    
        SPIM_1_WriteTxData(0x80);
        SPIM_1_WriteTxData(0xC1);
        
        SS_Write(255);
        
        config_reg = SPIM_1_ReadRxData();
        config_reg = SPIM_1_ReadRxData();
        
        SS_Write(0);
        SPIM_1_WriteTxData(0x00);
        SPIM_1_WriteTxData(0xFF);
        SS_Write(255);
        
        config_reg = 0;
        config_reg = SPIM_1_ReadRxData();
        config_reg = SPIM_1_ReadRxData();
        //Read the data sent back from the config reg.
        config_reg = SPIM_1_ReadRxData();
    }
    
    
    
    
    
    
    
    //Write a write commando plus the change to that reg.
    SPIM_1_WriteTxData(0x80);
    config_reg = SPIM_1_ReadRxData();
    SPIM_1_WriteTxData(0xC3);
    config_reg = SPIM_1_ReadRxData();
    
    //Read the new config register
    SPIM_1_WriteTxData(0x00);
    config_reg = SPIM_1_ReadRxData();
   
    
    rx_stat = SPIM_1_GetRxBufferSize();
    tx_stat = SPIM_1_GetTxBufferSize();
    
}

/* [] END OF FILE */
