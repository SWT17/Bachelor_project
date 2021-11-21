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
#include "TempSensorUnit.h"
#include "AmplifierRegisters.h"

/*Internal function declarations*/
void SPI_Setup();
void Set_WireSetup();
void Set_FilterSetup();
void WriteByteToAdress(char adress);
char ReadByteFromAdress(char adress);

/*Internal variables declartion*/
uint16_t rtd_ratio;


/*Does initial setup of the amplifier*/
void Amplifier_Setup()
{
    SPI_Setup();
    Set_WireSetup();
    Set_FilterSetup();
}


/*Retrieve RTD ration by reading the RTD msb byte and 
the RTD lsb byte from the amplifier registers*/
uint16_t GetRtdRatio()
{
    uint16_t rtd_ratio;
    //Read MSB byte from amplifier
    char RTD_msb = ReadByteFromAdress(READ_RTD_MSB_Reg_Adress);
    
    //Read LSB byte from amplifier
    char RTD_lsb = ReadByteFromAdress(READ_RTD_LSB_Reg_Adress);
    
    //Concatenate MSB and LSB to form the 15Bit RTD ration according to datasheet MAX31865 page 15 Table. 4
    rtd_ratio = ((uint16_t)RTD_msb << 7) | RTD_lsb>>1;
    
    return rtd_ratio;
}

/*Make a controller shuwdown off the amplifier*/
void Amplifier_Shutdown()
{
    //Set conversion mode "normally off", VBIAS off. See datasheet max31865
    
    Amplifier_Config |= 0 << 7; //VBiAS = "OFF";
    Amplifier_Config |= 0 << 6; //Conversion mode = "Normally OFF";
    
    //Write new configuration to the amplifier.
    WriteByteToAdress(Amplifier_Config);
    
}


/*Controlled startup after being shutdown*/
void Amplifier_Startup()
{
    
}





/*Setup SPI communication*/
void SPI_Setup()
{
    
}

/*Setting up the amplifier for the current wire configuration
This being a 2-wire config. Possible to do 3 og 4 wire as well*/
void Set_WireSetup()
{
    //Code to communicate the 2 wire config to the amplifier
    //Set Bit D4 = 0. Look at datasheet for Max865
    Amplifier_Config |= 0 << 4;
    WriteByteToAdress(Amplifier_Config);
}



/*Setting up the filter setup, either 50Hz or 60Hz
Dependent on country (Denmark), this will be 50Hz*/
void Set_FilterSetup()
{  
    //Code to communicate the 50Hz filter configuration to the amplifier on top of base setup.
    //Set Bit D0 = 1. Look at datasheet for Max865
    Amplifier_Config |= 1 << 0;
    WriteByteToAdress(Amplifier_Config);
}










//char ReadByteFromAdress(char adress)
//{
//    //SPI code for reading byte
//}
//
//void WriteByteToAdress(char adress)
//{
//    //SPI code for writing a byte
//    
//}







/* [] END OF FILE */
