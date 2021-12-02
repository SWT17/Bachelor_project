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
#include "Amplifier.h"
#include "AmplifierRegisters.h"

/*Internal function declarations*/
void SPI_Setup();
void MAX31865_Setup();
void Set_WireSetup(char wireconfig);
void Set_FilterSetup(char filterconfig);
void Set_VBIAS(char vbias_mode);
void Clear_Fault();
void Set_ConverionMode(char conversionmode);
void WriteByteToAdress(char adress, char data);
char ReadByteFromAdress(char adress);
uint16_t Conc_RTDdata(uint8_t MSB, uint8_t LSB);

/*Internal variables declartion*/
uint16_t rtd_ratio;
uint8 dummy_bytes;
uint8 bytes_received ;
char config;


void ReadReg();

/*Does initial setup of the amplifier*/
void Amplifier_Setup()
{
    SPI_Setup();
    MAX31865_Setup();
    
}

//Setup the microchipon the amplifier circuit
void MAX31865_Setup()
{
    Set_WireSetup(TWO_OR_FOUR_WIRECONFIG);
    Set_FilterSetup(FILTER_50HZ);
    Set_VBIAS(VBIAS_ON);
    Clear_Fault();
    ReadReg();
}

/*Retrieve RTD ration by reading the RTD msb byte and 
the RTD lsb byte from the amplifier registers*/
uint16 GetRtdRatio()
{
    
    uint16_t rtd_ratio;
    //Read MSB byte from amplifier
    char RTD_msb = ReadByteFromAdress(READ_RTD_MSB_REG_ADRESS);
    
    //Read LSB byte from amplifier
    char RTD_lsb = ReadByteFromAdress(READ_RTD_LSB_REG_ADRESS);
    
    rtd_ratio = Conc_RTDdata(RTD_msb, RTD_lsb);
    
    return rtd_ratio;
}

/*Make a controlled shuwdown off the amplifier. Meaning, shutting down temperature conversions
shutting down the communication.*/
void Amplifier_Shutdown()
{
    Set_ConverionMode(CONVERSIONMODE_OFF);
    Set_VBIAS(VBIAS_OFF);
    
    SPIM_1_Stop();
    
}


/*Controlled startup after being shutdown. Setting up temperature conversion
starting SPI communication again*/
void Amplifier_Startup()
{
    //Starts SPI again
    SPI_Setup();
    
    Set_VBIAS(VBIAS_ON);
    Set_ConverionMode(CONVERSIONMODE_AUTO);
    Clear_Fault();
 
}


uint16_t Conc_RTDdata(uint8_t MSB, uint8_t LSB)
{
    //Concatenate MSB and LSB to form the 15 Bit RTD ration according to datasheet MAX31865 page 15 Table. 4
    rtd_ratio = ((uint16_t)MSB << 7) | LSB>>1;
    return rtd_ratio;
}


/*Setup SPI communication*/
void SPI_Setup()
{
    //Start up SPI. All setups are done in the TopDesign file.
    SPIM_1_Start();
}

/*Setting up the amplifier for the current wire configuration
This being a 2-wire config. Possible to do 3 og 4 wire as well*/
void Set_WireSetup(char wireconfig)
{
    //Code to communicate the 2 wire config to the amplifier
    //Set Bit D4 = 0. Look at datasheet for Max865
    config = ReadByteFromAdress(READ_CONFIG_REG_ADRESS);
    
    if(wireconfig == TWO_OR_FOUR_WIRECONFIG)
    {
        //Sets bit D4 = 0 equal to 2-wire config. See datasheet for max31865
        config &= ~(1 << 3);
        //Write new config setup to amplifier.
        WriteByteToAdress(WRITE_CONFIG_REG_ADRESS,config); 
    }
    if(wireconfig == THREE_WIRECONFIG)
    {
        //Set bit D4 to 1
        config |= 1 << 3;
        //Write new config setup to amplifier.
        WriteByteToAdress(WRITE_CONFIG_REG_ADRESS,config); 
    }
    
}



/*Setting up the filter setup, either 50Hz or 60Hz
Dependent on country (Denmark), this will be 50Hz*/
void Set_FilterSetup(char filterconfig)
{  
    config = ReadByteFromAdress(READ_CONFIG_REG_ADRESS);
    if(filterconfig == FILTER_50HZ)
    {
       config |= FILTER_50HZ;
       WriteByteToAdress(WRITE_CONFIG_REG_ADRESS,config); 
    }
    if(filterconfig == FILTER_60HZ)
    {
        config &= ~(1 << 0);
        WriteByteToAdress(WRITE_CONFIG_REG_ADRESS,config);
    }
    
    
}

//Sets the conversion mode to auto
void Set_ConverionMode(char conversionmode)
{
    
    config = ReadByteFromAdress(READ_CONFIG_REG_ADRESS);
    if(conversionmode == CONVERSIONMODE_AUTO)
    {
        config |= CONVERSIONMODE_AUTO;
        WriteByteToAdress(WRITE_CONFIG_REG_ADRESS,config);
    }
    if(conversionmode==CONVERSIONMODE_OFF)
    {
        config &= ~(1 << 6);
        WriteByteToAdress(WRITE_CONFIG_REG_ADRESS,config);
    }

    
}

void Set_VBIAS(char vbias_mode)
{    
    config = ReadByteFromAdress(READ_CONFIG_REG_ADRESS);
    if(vbias_mode == VBIAS_ON)
    {
        config |= VBIAS_ON;
        WriteByteToAdress(WRITE_CONFIG_REG_ADRESS,config);        
    }
    if(vbias_mode == VBIAS_OFF)
    {
        config &= ~(1 << 7);
        WriteByteToAdress(WRITE_CONFIG_REG_ADRESS,config);
    }


}

//Clears the fault register upon setup
void Clear_Fault()
{
    config = ReadByteFromAdress(READ_CONFIG_REG_ADRESS);
    config |= CLEAR_FAULTBIT;
    WriteByteToAdress(WRITE_CONFIG_REG_ADRESS,config);
}

char ReadByteFromAdress(char adress)
{

    
    SS_Write(0);
    //According to the datasheet for the max31865 the amplifier first needs the read adress
    //Then it needs a default signal, to return what is on the adress requested in the first SPI write msg.
    SPIM_1_WriteTxData(adress);
    SPIM_1_WriteTxData(0xFF);
    CyDelay(20);
    SS_Write(255);
    
    dummy_bytes = SPIM_1_ReadRxData();
    bytes_received = SPIM_1_ReadRxData();

    
    //Clear TX and RX FIFO for the SPI to make it ready for the next transmission.
    
    return bytes_received;
    
}

void WriteByteToAdress(char adress, char data)
{
    
    
    //Pull Slave select low, start transmission.
    SS_Write(0);
    SPIM_1_WriteTxData(adress);
    SPIM_1_WriteTxData(data);
    //Pull slave select up, end transmission.
    CyDelay(20);
    SS_Write(255);
    
    dummy_bytes = SPIM_1_ReadRxData();
    dummy_bytes = SPIM_1_ReadRxData();
    
    //This is done to empty the data received for every WRITE in the RX buffer and TX

       
}

void ReadReg()
{
    config = ReadByteFromAdress(READ_CONFIG_REG_ADRESS);
    
}







/* [] END OF FILE */
