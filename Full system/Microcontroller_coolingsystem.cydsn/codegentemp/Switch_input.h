/*******************************************************************************
* File Name: Switch_input.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Switch_input_H) /* Pins Switch_input_H */
#define CY_PINS_Switch_input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Switch_input_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Switch_input__PORT == 15 && ((Switch_input__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Switch_input_Write(uint8 value);
void    Switch_input_SetDriveMode(uint8 mode);
uint8   Switch_input_ReadDataReg(void);
uint8   Switch_input_Read(void);
void    Switch_input_SetInterruptMode(uint16 position, uint16 mode);
uint8   Switch_input_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Switch_input_SetDriveMode() function.
     *  @{
     */
        #define Switch_input_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Switch_input_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Switch_input_DM_RES_UP          PIN_DM_RES_UP
        #define Switch_input_DM_RES_DWN         PIN_DM_RES_DWN
        #define Switch_input_DM_OD_LO           PIN_DM_OD_LO
        #define Switch_input_DM_OD_HI           PIN_DM_OD_HI
        #define Switch_input_DM_STRONG          PIN_DM_STRONG
        #define Switch_input_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Switch_input_MASK               Switch_input__MASK
#define Switch_input_SHIFT              Switch_input__SHIFT
#define Switch_input_WIDTH              1u

/* Interrupt constants */
#if defined(Switch_input__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Switch_input_SetInterruptMode() function.
     *  @{
     */
        #define Switch_input_INTR_NONE      (uint16)(0x0000u)
        #define Switch_input_INTR_RISING    (uint16)(0x0001u)
        #define Switch_input_INTR_FALLING   (uint16)(0x0002u)
        #define Switch_input_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Switch_input_INTR_MASK      (0x01u) 
#endif /* (Switch_input__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Switch_input_PS                     (* (reg8 *) Switch_input__PS)
/* Data Register */
#define Switch_input_DR                     (* (reg8 *) Switch_input__DR)
/* Port Number */
#define Switch_input_PRT_NUM                (* (reg8 *) Switch_input__PRT) 
/* Connect to Analog Globals */                                                  
#define Switch_input_AG                     (* (reg8 *) Switch_input__AG)                       
/* Analog MUX bux enable */
#define Switch_input_AMUX                   (* (reg8 *) Switch_input__AMUX) 
/* Bidirectional Enable */                                                        
#define Switch_input_BIE                    (* (reg8 *) Switch_input__BIE)
/* Bit-mask for Aliased Register Access */
#define Switch_input_BIT_MASK               (* (reg8 *) Switch_input__BIT_MASK)
/* Bypass Enable */
#define Switch_input_BYP                    (* (reg8 *) Switch_input__BYP)
/* Port wide control signals */                                                   
#define Switch_input_CTL                    (* (reg8 *) Switch_input__CTL)
/* Drive Modes */
#define Switch_input_DM0                    (* (reg8 *) Switch_input__DM0) 
#define Switch_input_DM1                    (* (reg8 *) Switch_input__DM1)
#define Switch_input_DM2                    (* (reg8 *) Switch_input__DM2) 
/* Input Buffer Disable Override */
#define Switch_input_INP_DIS                (* (reg8 *) Switch_input__INP_DIS)
/* LCD Common or Segment Drive */
#define Switch_input_LCD_COM_SEG            (* (reg8 *) Switch_input__LCD_COM_SEG)
/* Enable Segment LCD */
#define Switch_input_LCD_EN                 (* (reg8 *) Switch_input__LCD_EN)
/* Slew Rate Control */
#define Switch_input_SLW                    (* (reg8 *) Switch_input__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Switch_input_PRTDSI__CAPS_SEL       (* (reg8 *) Switch_input__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Switch_input_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Switch_input__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Switch_input_PRTDSI__OE_SEL0        (* (reg8 *) Switch_input__PRTDSI__OE_SEL0) 
#define Switch_input_PRTDSI__OE_SEL1        (* (reg8 *) Switch_input__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Switch_input_PRTDSI__OUT_SEL0       (* (reg8 *) Switch_input__PRTDSI__OUT_SEL0) 
#define Switch_input_PRTDSI__OUT_SEL1       (* (reg8 *) Switch_input__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Switch_input_PRTDSI__SYNC_OUT       (* (reg8 *) Switch_input__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Switch_input__SIO_CFG)
    #define Switch_input_SIO_HYST_EN        (* (reg8 *) Switch_input__SIO_HYST_EN)
    #define Switch_input_SIO_REG_HIFREQ     (* (reg8 *) Switch_input__SIO_REG_HIFREQ)
    #define Switch_input_SIO_CFG            (* (reg8 *) Switch_input__SIO_CFG)
    #define Switch_input_SIO_DIFF           (* (reg8 *) Switch_input__SIO_DIFF)
#endif /* (Switch_input__SIO_CFG) */

/* Interrupt Registers */
#if defined(Switch_input__INTSTAT)
    #define Switch_input_INTSTAT            (* (reg8 *) Switch_input__INTSTAT)
    #define Switch_input_SNAP               (* (reg8 *) Switch_input__SNAP)
    
	#define Switch_input_0_INTTYPE_REG 		(* (reg8 *) Switch_input__0__INTTYPE)
#endif /* (Switch_input__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Switch_input_H */


/* [] END OF FILE */
