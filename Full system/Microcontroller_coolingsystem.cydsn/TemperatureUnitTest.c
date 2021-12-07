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
#include "TemperatureUnitTest.h"

/*This test aims to verify that the correct RTD resistance is
calculated based of the ratio given to the method.*/
void calc_RTD_value_RatiosSent_RTDresistancereceived()
{

    //Setup the temperature class with af reference resistance
    Temperature_Setup(4300);
    
    //Run the test
    SetTemperature(7239);
    SetTemperature(7620);
    SetTemperature(8611);
}

/*Test the resulting temperature if it corresponds with the
Standard 60751 when feeding it with known RTD resistance values*/
void calc_Calctemp_RatiosSent_RTDresistancereceived()
{
    //Setup the temperature class with af reference resistance
    Temperature_Setup(4300);
    
    UART_1_Start();
    //Run the test
    SetTemperature(7232);
    char temp[50];
            
    float temp_string = GetTemperature();
    sprintf(temp,"RTD resistance value = 7232 Temperature: %f\n\r",temp_string);
    UART_1_PutString(temp);
    SetTemperature(7620);

            
    temp_string = GetTemperature();
    sprintf(temp,"RTD resistance value = 7620 Temperature: %f\n\r",temp_string);
    UART_1_PutString(temp);
    SetTemperature(8598);
    
            
     temp_string = GetTemperature();
    sprintf(temp,"RTD resistance value = 8598 Temperature: %f\n\r",temp_string);
    UART_1_PutString(temp);

}










/* [] END OF FILE */

