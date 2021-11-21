/*******************************************************************************
* File Name: Temp_sample_counter_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Temp_sample_counter.h"

static Temp_sample_counter_backupStruct Temp_sample_counter_backup;


/*******************************************************************************
* Function Name: Temp_sample_counter_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Temp_sample_counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Temp_sample_counter_SaveConfig(void) 
{
    #if (!Temp_sample_counter_UsingFixedFunction)

        Temp_sample_counter_backup.CounterUdb = Temp_sample_counter_ReadCounter();

        #if(!Temp_sample_counter_ControlRegRemoved)
            Temp_sample_counter_backup.CounterControlRegister = Temp_sample_counter_ReadControlRegister();
        #endif /* (!Temp_sample_counter_ControlRegRemoved) */

    #endif /* (!Temp_sample_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Temp_sample_counter_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Temp_sample_counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Temp_sample_counter_RestoreConfig(void) 
{      
    #if (!Temp_sample_counter_UsingFixedFunction)

       Temp_sample_counter_WriteCounter(Temp_sample_counter_backup.CounterUdb);

        #if(!Temp_sample_counter_ControlRegRemoved)
            Temp_sample_counter_WriteControlRegister(Temp_sample_counter_backup.CounterControlRegister);
        #endif /* (!Temp_sample_counter_ControlRegRemoved) */

    #endif /* (!Temp_sample_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Temp_sample_counter_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Temp_sample_counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Temp_sample_counter_Sleep(void) 
{
    #if(!Temp_sample_counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Temp_sample_counter_CTRL_ENABLE == (Temp_sample_counter_CONTROL & Temp_sample_counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Temp_sample_counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Temp_sample_counter_backup.CounterEnableState = 0u;
        }
    #else
        Temp_sample_counter_backup.CounterEnableState = 1u;
        if(Temp_sample_counter_backup.CounterEnableState != 0u)
        {
            Temp_sample_counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!Temp_sample_counter_ControlRegRemoved) */
    
    Temp_sample_counter_Stop();
    Temp_sample_counter_SaveConfig();
}


/*******************************************************************************
* Function Name: Temp_sample_counter_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Temp_sample_counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Temp_sample_counter_Wakeup(void) 
{
    Temp_sample_counter_RestoreConfig();
    #if(!Temp_sample_counter_ControlRegRemoved)
        if(Temp_sample_counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Temp_sample_counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Temp_sample_counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
