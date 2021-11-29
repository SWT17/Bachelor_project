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

/*Delcared internal variables*/
int32 Temperature;
uint16_t Ref_resistance;

/*Declared internal functions*/
void calc_temp(uint16_t rtd_ratio);
uint32_t calc_RTD_value(uint16_t rtd_ratio);




/*Setup of the internal reference resistance in the amplifier.
The amplifier uses this for calculating the RTD/ref_res ratio stored in the
RTD_MSB and RTD_LSB data registers*/
void Temperature_Setup(uint16_t ref_res)
{
    Ref_resistance = ref_res;
}


void SetTemperature(uint16_t rtd_ratio)
{
    calc_temp(rtd_ratio);
}



/*Caluculation of the temperature. Done with the RTD component in PSOC*/
void calc_temp(uint16_t rtd_ratio)
{
    uint32_t rtd_res = calc_RTD_value(rtd_ratio);
    
    Temperature = RTD_1_GetTemperature(rtd_res); //Uses the RTD calculator to calculate the temperature. Datasheet RTD calculoator p.4

}

uint32_t calc_RTD_value(uint16_t rtd_ratio)
{
    uint32_t rtd_res = rtd_ratio*Ref_resistance/(2^15); //Calculates the RTD resistance from equation p. 19 in MAX31865 datasheet
    return rtd_res;
}

/* [] END OF FILE */
