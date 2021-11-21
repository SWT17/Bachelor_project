/*******************************************************************************
* File Name: Switch_input.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Switch_input_ALIASES_H) /* Pins Switch_input_ALIASES_H */
#define CY_PINS_Switch_input_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Switch_input_0			(Switch_input__0__PC)
#define Switch_input_0_INTR	((uint16)((uint16)0x0001u << Switch_input__0__SHIFT))

#define Switch_input_INTR_ALL	 ((uint16)(Switch_input_0_INTR))

#endif /* End Pins Switch_input_ALIASES_H */


/* [] END OF FILE */
