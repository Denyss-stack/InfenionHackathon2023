/*******************************************************************************
* File Name: PinOut_Buzz.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PinOut_Buzz_H) /* Pins PinOut_Buzz_H */
#define CY_PINS_PinOut_Buzz_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PinOut_Buzz_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} PinOut_Buzz_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PinOut_Buzz_Read(void);
void    PinOut_Buzz_Write(uint8 value);
uint8   PinOut_Buzz_ReadDataReg(void);
#if defined(PinOut_Buzz__PC) || (CY_PSOC4_4200L) 
    void    PinOut_Buzz_SetDriveMode(uint8 mode);
#endif
void    PinOut_Buzz_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinOut_Buzz_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PinOut_Buzz_Sleep(void); 
void PinOut_Buzz_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PinOut_Buzz__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PinOut_Buzz_DRIVE_MODE_BITS        (3)
    #define PinOut_Buzz_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PinOut_Buzz_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PinOut_Buzz_SetDriveMode() function.
         *  @{
         */
        #define PinOut_Buzz_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PinOut_Buzz_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PinOut_Buzz_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PinOut_Buzz_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PinOut_Buzz_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PinOut_Buzz_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PinOut_Buzz_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PinOut_Buzz_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PinOut_Buzz_MASK               PinOut_Buzz__MASK
#define PinOut_Buzz_SHIFT              PinOut_Buzz__SHIFT
#define PinOut_Buzz_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinOut_Buzz_SetInterruptMode() function.
     *  @{
     */
        #define PinOut_Buzz_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PinOut_Buzz_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PinOut_Buzz_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PinOut_Buzz_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PinOut_Buzz__SIO)
    #define PinOut_Buzz_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PinOut_Buzz__PC) && (CY_PSOC4_4200L)
    #define PinOut_Buzz_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PinOut_Buzz_USBIO_DISABLE              ((uint32)(~PinOut_Buzz_USBIO_ENABLE))
    #define PinOut_Buzz_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PinOut_Buzz_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PinOut_Buzz_USBIO_ENTER_SLEEP          ((uint32)((1u << PinOut_Buzz_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PinOut_Buzz_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinOut_Buzz_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PinOut_Buzz_USBIO_SUSPEND_SHIFT)))
    #define PinOut_Buzz_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PinOut_Buzz_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinOut_Buzz_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PinOut_Buzz__PC)
    /* Port Configuration */
    #define PinOut_Buzz_PC                 (* (reg32 *) PinOut_Buzz__PC)
#endif
/* Pin State */
#define PinOut_Buzz_PS                     (* (reg32 *) PinOut_Buzz__PS)
/* Data Register */
#define PinOut_Buzz_DR                     (* (reg32 *) PinOut_Buzz__DR)
/* Input Buffer Disable Override */
#define PinOut_Buzz_INP_DIS                (* (reg32 *) PinOut_Buzz__PC2)

/* Interrupt configuration Registers */
#define PinOut_Buzz_INTCFG                 (* (reg32 *) PinOut_Buzz__INTCFG)
#define PinOut_Buzz_INTSTAT                (* (reg32 *) PinOut_Buzz__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PinOut_Buzz_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PinOut_Buzz__SIO)
    #define PinOut_Buzz_SIO_REG            (* (reg32 *) PinOut_Buzz__SIO)
#endif /* (PinOut_Buzz__SIO_CFG) */

/* USBIO registers */
#if !defined(PinOut_Buzz__PC) && (CY_PSOC4_4200L)
    #define PinOut_Buzz_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PinOut_Buzz_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PinOut_Buzz_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PinOut_Buzz_DRIVE_MODE_SHIFT       (0x00u)
#define PinOut_Buzz_DRIVE_MODE_MASK        (0x07u << PinOut_Buzz_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PinOut_Buzz_H */


/* [] END OF FILE */
