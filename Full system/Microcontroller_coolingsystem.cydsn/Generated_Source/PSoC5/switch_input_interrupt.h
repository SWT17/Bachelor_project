/*******************************************************************************
* File Name: switch_input_interrupt.h
* Version 1.71
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_switch_input_interrupt_H)
#define CY_ISR_switch_input_interrupt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void switch_input_interrupt_Start(void);
void switch_input_interrupt_StartEx(cyisraddress address);
void switch_input_interrupt_Stop(void);

CY_ISR_PROTO(switch_input_interrupt_Interrupt);

void switch_input_interrupt_SetVector(cyisraddress address);
cyisraddress switch_input_interrupt_GetVector(void);

void switch_input_interrupt_SetPriority(uint8 priority);
uint8 switch_input_interrupt_GetPriority(void);

void switch_input_interrupt_Enable(void);
uint8 switch_input_interrupt_GetState(void);
void switch_input_interrupt_Disable(void);

void switch_input_interrupt_SetPending(void);
void switch_input_interrupt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the switch_input_interrupt ISR. */
#define switch_input_interrupt_INTC_VECTOR            ((reg32 *) switch_input_interrupt__INTC_VECT)

/* Address of the switch_input_interrupt ISR priority. */
#define switch_input_interrupt_INTC_PRIOR             ((reg8 *) switch_input_interrupt__INTC_PRIOR_REG)

/* Priority of the switch_input_interrupt interrupt. */
#define switch_input_interrupt_INTC_PRIOR_NUMBER      switch_input_interrupt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable switch_input_interrupt interrupt. */
#define switch_input_interrupt_INTC_SET_EN            ((reg32 *) switch_input_interrupt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the switch_input_interrupt interrupt. */
#define switch_input_interrupt_INTC_CLR_EN            ((reg32 *) switch_input_interrupt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the switch_input_interrupt interrupt state to pending. */
#define switch_input_interrupt_INTC_SET_PD            ((reg32 *) switch_input_interrupt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the switch_input_interrupt interrupt. */
#define switch_input_interrupt_INTC_CLR_PD            ((reg32 *) switch_input_interrupt__INTC_CLR_PD_REG)


#endif /* CY_ISR_switch_input_interrupt_H */


/* [] END OF FILE */
