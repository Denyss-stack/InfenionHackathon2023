/*******************************************************************************
* File Name: PinOut_Buzz.c  
* Version 2.20
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "PinOut_Buzz.h"


#if defined(PinOut_Buzz__PC)
    #define PinOut_Buzz_SetP4PinDriveMode(shift, mode)  \
    do { \
        PinOut_Buzz_PC =   (PinOut_Buzz_PC & \
                                (uint32)(~(uint32)(PinOut_Buzz_DRIVE_MODE_IND_MASK << \
                                (PinOut_Buzz_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << \
                                (PinOut_Buzz_DRIVE_MODE_BITS * (shift))); \
    } while (0)
#else
    #if (CY_PSOC4_4200L)
        #define PinOut_Buzz_SetP4PinDriveMode(shift, mode)  \
        do { \
            PinOut_Buzz_USBIO_CTRL_REG = (PinOut_Buzz_USBIO_CTRL_REG & \
                                    (uint32)(~(uint32)(PinOut_Buzz_DRIVE_MODE_IND_MASK << \
                                    (PinOut_Buzz_DRIVE_MODE_BITS * (shift))))) | \
                                    (uint32)((uint32)(mode) << \
                                    (PinOut_Buzz_DRIVE_MODE_BITS * (shift))); \
        } while (0)
    #endif
#endif
  

#if defined(PinOut_Buzz__PC) || (CY_PSOC4_4200L) 
    /*******************************************************************************
    * Function Name: PinOut_Buzz_SetDriveMode
    ****************************************************************************//**
    *
    * \brief Sets the drive mode for each of the Pins component's pins.
    * 
    * <b>Note</b> This affects all pins in the Pins component instance. Use the
    * Per-Pin APIs if you wish to control individual pin's drive modes.
    *
    * <b>Note</b> USBIOs have limited drive functionality. Refer to the Drive Mode
    * parameter for more information.
    *
    * \param mode
    *  Mode for the selected signals. Valid options are documented in 
    *  \ref driveMode.
    *
    * \return
    *  None
    *
    * \sideeffect
    *  If you use read-modify-write operations that are not atomic, the ISR can
    *  cause corruption of this function. An ISR that interrupts this function 
    *  and performs writes to the Pins component Drive Mode registers can cause 
    *  corrupted port data. To avoid this issue, you should either use the Per-Pin
    *  APIs (primary method) or disable interrupts around this function.
    *
    * \funcusage
    *  \snippet PinOut_Buzz_SUT.c usage_PinOut_Buzz_SetDriveMode
    *******************************************************************************/
    void PinOut_Buzz_SetDriveMode(uint8 mode)
    {
		PinOut_Buzz_SetP4PinDriveMode(PinOut_Buzz__0__SHIFT, mode);
    }
#endif


/*******************************************************************************
* Function Name: PinOut_Buzz_Write
****************************************************************************//**
*
* \brief Writes the value to the physical port (data output register), masking
*  and shifting the bits appropriately. 
*
* The data output register controls the signal applied to the physical pin in 
* conjunction with the drive mode parameter. This function avoids changing 
* other bits in the port by using the appropriate method (read-modify-write or
* bit banding).
*
* <b>Note</b> This function should not be used on a hardware digital output pin 
* as it is driven by the hardware signal attached to it.
*
* \param value
*  Value to write to the component instance.
*
* \return 
*  None 
*
* \sideeffect
*  If you use read-modify-write operations that are not atomic; the Interrupt 
*  Service Routines (ISR) can cause corruption of this function. An ISR that 
*  interrupts this function and performs writes to the Pins component data 
*  register can cause corrupted port data. To avoid this issue, you should 
*  either use the Per-Pin APIs (primary method) or disable interrupts around 
*  this function.
*
* \funcusage
*  \snippet PinOut_Buzz_SUT.c usage_PinOut_Buzz_Write
*******************************************************************************/
void PinOut_Buzz_Write(uint8 value)
{
    uint8 drVal = (uint8)(PinOut_Buzz_DR & (uint8)(~PinOut_Buzz_MASK));
    drVal = (drVal | ((uint8)(value << PinOut_Buzz_SHIFT) & PinOut_Buzz_MASK));
    PinOut_Buzz_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: PinOut_Buzz_Read
****************************************************************************//**
*
* \brief Reads the associated physical port (pin status register) and masks 
*  the required bits according to the width and bit position of the component
*  instance. 
*
* The pin's status register returns the current logic level present on the 
* physical pin.
*
* \return 
*  The current value for the pins in the component as a right justified number.
*
* \funcusage
*  \snippet PinOut_Buzz_SUT.c usage_PinOut_Buzz_Read  
*******************************************************************************/
uint8 PinOut_Buzz_Read(void)
{
    return (uint8)((PinOut_Buzz_PS & PinOut_Buzz_MASK) >> PinOut_Buzz_SHIFT);
}


/*******************************************************************************
* Function Name: PinOut_Buzz_ReadDataReg
****************************************************************************//**
*
* \brief Reads the associated physical port's data output register and masks 
*  the correct bits according to the width and bit position of the component 
*  instance. 
*
* The data output register controls the signal applied to the physical pin in 
* conjunction with the drive mode parameter. This is not the same as the 
* preferred PinOut_Buzz_Read() API because the 
* PinOut_Buzz_ReadDataReg() reads the data register instead of the status 
* register. For output pins this is a useful function to determine the value 
* just written to the pin.
*
* \return 
*  The current value of the data register masked and shifted into a right 
*  justified number for the component instance.
*
* \funcusage
*  \snippet PinOut_Buzz_SUT.c usage_PinOut_Buzz_ReadDataReg 
*******************************************************************************/
uint8 PinOut_Buzz_ReadDataReg(void)
{
    return (uint8)((PinOut_Buzz_DR & PinOut_Buzz_MASK) >> PinOut_Buzz_SHIFT);
}


/*******************************************************************************
* Function Name: PinOut_Buzz_SetInterruptMode
****************************************************************************//**
*
* \brief Configures the interrupt mode for each of the Pins component's
*  pins. Alternatively you may set the interrupt mode for all the pins
*  specified in the Pins component.
*
*  <b>Note</b> The interrupt is port-wide and therefore any enabled pin
*  interrupt may trigger it.
*
* \param position
*  The pin position as listed in the Pins component. You may OR these to be 
*  able to configure the interrupt mode of multiple pins within a Pins 
*  component. Or you may use PinOut_Buzz_INTR_ALL to configure the
*  interrupt mode of all the pins in the Pins component.       
*  - PinOut_Buzz_0_INTR       (First pin in the list)
*  - PinOut_Buzz_1_INTR       (Second pin in the list)
*  - ...
*  - PinOut_Buzz_INTR_ALL     (All pins in Pins component)
*
* \param mode
*  Interrupt mode for the selected pins. Valid options are documented in
*  \ref intrMode.
*
* \return 
*  None
*  
* \sideeffect
*  It is recommended that the interrupt be disabled before calling this 
*  function to avoid unintended interrupt requests. Note that the interrupt
*  type is port wide, and therefore will trigger for any enabled pin on the 
*  port.
*
* \funcusage
*  \snippet PinOut_Buzz_SUT.c usage_PinOut_Buzz_SetInterruptMode
*******************************************************************************/
void PinOut_Buzz_SetInterruptMode(uint16 position, uint16 mode)
{
    uint32 intrCfg;
    
    intrCfg =  PinOut_Buzz_INTCFG & (uint32)(~(uint32)position);
    PinOut_Buzz_INTCFG = intrCfg | ((uint32)position & (uint32)mode);
}


/*******************************************************************************
* Function Name: PinOut_Buzz_ClearInterrupt
****************************************************************************//**
*
* \brief Clears any active interrupts attached with the component and returns 
*  the value of the interrupt status register allowing determination of which
*  pins generated an interrupt event.
*
* \return 
*  The right-shifted current value of the interrupt status register. Each pin 
*  has one bit set if it generated an interrupt event. For example, bit 0 is 
*  for pin 0 and bit 1 is for pin 1 of the Pins component.
*  
* \sideeffect
*  Clears all bits of the physical port's interrupt status register, not just
*  those associated with the Pins component.
*
* \funcusage
*  \snippet PinOut_Buzz_SUT.c usage_PinOut_Buzz_ClearInterrupt
*******************************************************************************/
uint8 PinOut_Buzz_ClearInterrupt(void)
{
	uint8 maskedStatus = (uint8)(PinOut_Buzz_INTSTAT & PinOut_Buzz_MASK);
	PinOut_Buzz_INTSTAT = maskedStatus;
    return maskedStatus >> PinOut_Buzz_SHIFT;
}


/* [] END OF FILE */
