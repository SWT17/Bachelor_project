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

#include "Regulation.h"

float upper_limit;
float lower_limit;
uint8 res;



void Regulation_setup()
{
    upper_limit = -9;
    lower_limit = -11;
    res = 1;
}

uint8 Regulation(float temp)
{
    if(temp > upper_limit)
    {
        res = 1;
        
    }else if( temp < lower_limit)
    {
        res = 0;
    }
    return res;
}
/* [] END OF FILE */
