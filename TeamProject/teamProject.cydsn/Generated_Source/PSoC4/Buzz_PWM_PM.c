/*******************************************************************************
* File Name: Buzz_PWM_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Buzz_PWM.h"

static Buzz_PWM_BACKUP_STRUCT Buzz_PWM_backup;


/*******************************************************************************
* Function Name: Buzz_PWM_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Buzz_PWM_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Buzz_PWM_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Buzz_PWM_Sleep(void)
{
    if(0u != (Buzz_PWM_BLOCK_CONTROL_REG & Buzz_PWM_MASK))
    {
        Buzz_PWM_backup.enableState = 1u;
    }
    else
    {
        Buzz_PWM_backup.enableState = 0u;
    }

    Buzz_PWM_Stop();
    Buzz_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: Buzz_PWM_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Buzz_PWM_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Buzz_PWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Buzz_PWM_Wakeup(void)
{
    Buzz_PWM_RestoreConfig();

    if(0u != Buzz_PWM_backup.enableState)
    {
        Buzz_PWM_Enable();
    }
}


/* [] END OF FILE */
