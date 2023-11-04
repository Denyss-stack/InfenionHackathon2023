/*******************************************************************************
* File Name: butt_cheat.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "butt_cheat.h"

static butt_cheat_BACKUP_STRUCT  butt_cheat_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: butt_cheat_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet butt_cheat_SUT.c usage_butt_cheat_Sleep_Wakeup
*******************************************************************************/
void butt_cheat_Sleep(void)
{
    #if defined(butt_cheat__PC)
        butt_cheat_backup.pcState = butt_cheat_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            butt_cheat_backup.usbState = butt_cheat_CR1_REG;
            butt_cheat_USB_POWER_REG |= butt_cheat_USBIO_ENTER_SLEEP;
            butt_cheat_CR1_REG &= butt_cheat_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(butt_cheat__SIO)
        butt_cheat_backup.sioState = butt_cheat_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        butt_cheat_SIO_REG &= (uint32)(~butt_cheat_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: butt_cheat_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to butt_cheat_Sleep() for an example usage.
*******************************************************************************/
void butt_cheat_Wakeup(void)
{
    #if defined(butt_cheat__PC)
        butt_cheat_PC = butt_cheat_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            butt_cheat_USB_POWER_REG &= butt_cheat_USBIO_EXIT_SLEEP_PH1;
            butt_cheat_CR1_REG = butt_cheat_backup.usbState;
            butt_cheat_USB_POWER_REG &= butt_cheat_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(butt_cheat__SIO)
        butt_cheat_SIO_REG = butt_cheat_backup.sioState;
    #endif
}


/* [] END OF FILE */
