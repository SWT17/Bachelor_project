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
/*Include files*/
#include "Temperature.h"
#include "UART_1.h"

/*Delcared internal variables*/
int32 Temperature;
float temp_float;
uint16_t Ref_resistance;

/*Declared internal functions*/
void calc_temp(uint16 rtd_ratio);
uint32_t calc_RTD_value(uint16 rtd_ratio);




/*Setup of the internal reference resistance in the amplifier.
The amplifier uses this for calculating the RTD/ref_res ratio stored in the
RTD_MSB and RTD_LSB data registers*/
void Temperature_Setup(uint16_t ref_res)
{
    Ref_resistance = ref_res;
    Temperature = 0;
}

int32 GetTemperature()
{
    return temp_float; 
}

void SetTemperature(uint16_t rtd_ratio)
{
    calc_temp(rtd_ratio);
}



/*Caluculation of the temperature. Done with the RTD component in PSOC*/
void calc_temp(uint16 rtd_ratio)
{
    uint32 rtd_res;
    rtd_res = calc_RTD_value(rtd_ratio);
    
    Temperature = RTD_1_GetTemperature(rtd_res); //Uses the RTD calculator to calculate the temperature. Datasheet RTD calculoator p.4
    temp_float = (float)Temperature/100;

}

/*Calculation of the RDT resistance based on the ratio
measured by the amplifier. Returned in mili Ohm*/
uint32_t calc_RTD_value(uint16 rtd_ratio)
{
    
    float rtd_res = (rtd_ratio*Ref_resistance)/pow(2,15); //Calculates the RTD resistance in mili Ohm from equation p. 19 in MAX31865 datasheet
    uint32 rtd_res_mOhm = rtd_res * 1000;
    return rtd_res_mOhm;
}

/* [] END OF FILE */
