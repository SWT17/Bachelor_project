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

float regulation_temp;
uint8 res;



void Regulation_setup()
{
    regulation_temp = -10;
    res = 1;
}

uint8 Regulation(float temp)
{
    if(temp > regulation_temp)
    {
        res = 1;
        
    }else if( temp < regulation_temp)
    {
        res = 0;
    }
    return res;
}
/* [] END OF FILE */
