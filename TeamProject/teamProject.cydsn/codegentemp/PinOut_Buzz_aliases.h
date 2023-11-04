/*******************************************************************************
* File Name: PinOut_Buzz.h  
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

#if !defined(CY_PINS_PinOut_Buzz_ALIASES_H) /* Pins PinOut_Buzz_ALIASES_H */
#define CY_PINS_PinOut_Buzz_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PinOut_Buzz_0			(PinOut_Buzz__0__PC)
#define PinOut_Buzz_0_PS		(PinOut_Buzz__0__PS)
#define PinOut_Buzz_0_PC		(PinOut_Buzz__0__PC)
#define PinOut_Buzz_0_DR		(PinOut_Buzz__0__DR)
#define PinOut_Buzz_0_SHIFT	(PinOut_Buzz__0__SHIFT)
#define PinOut_Buzz_0_INTR	((uint16)((uint16)0x0003u << (PinOut_Buzz__0__SHIFT*2u)))

#define PinOut_Buzz_INTR_ALL	 ((uint16)(PinOut_Buzz_0_INTR))


#endif /* End Pins PinOut_Buzz_ALIASES_H */


/* [] END OF FILE */
