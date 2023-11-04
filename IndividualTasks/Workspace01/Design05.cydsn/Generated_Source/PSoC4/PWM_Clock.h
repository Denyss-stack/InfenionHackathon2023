/*******************************************************************************
* File Name: PWM_Clock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_PWM_Clock_H)
#define CY_CLOCK_PWM_Clock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void PWM_Clock_StartEx(uint32 alignClkDiv);
#define PWM_Clock_Start() \
    PWM_Clock_StartEx(PWM_Clock__PA_DIV_ID)

#else

void PWM_Clock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void PWM_Clock_Stop(void);

void PWM_Clock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 PWM_Clock_GetDividerRegister(void);
uint8  PWM_Clock_GetFractionalDividerRegister(void);

#define PWM_Clock_Enable()                         PWM_Clock_Start()
#define PWM_Clock_Disable()                        PWM_Clock_Stop()
#define PWM_Clock_SetDividerRegister(clkDivider, reset)  \
    PWM_Clock_SetFractionalDividerRegister((clkDivider), 0u)
#define PWM_Clock_SetDivider(clkDivider)           PWM_Clock_SetDividerRegister((clkDivider), 1u)
#define PWM_Clock_SetDividerValue(clkDivider)      PWM_Clock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define PWM_Clock_DIV_ID     PWM_Clock__DIV_ID

#define PWM_Clock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define PWM_Clock_CTRL_REG   (*(reg32 *)PWM_Clock__CTRL_REGISTER)
#define PWM_Clock_DIV_REG    (*(reg32 *)PWM_Clock__DIV_REGISTER)

#define PWM_Clock_CMD_DIV_SHIFT          (0u)
#define PWM_Clock_CMD_PA_DIV_SHIFT       (8u)
#define PWM_Clock_CMD_DISABLE_SHIFT      (30u)
#define PWM_Clock_CMD_ENABLE_SHIFT       (31u)

#define PWM_Clock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << PWM_Clock_CMD_DISABLE_SHIFT))
#define PWM_Clock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << PWM_Clock_CMD_ENABLE_SHIFT))

#define PWM_Clock_DIV_FRAC_MASK  (0x000000F8u)
#define PWM_Clock_DIV_FRAC_SHIFT (3u)
#define PWM_Clock_DIV_INT_MASK   (0xFFFFFF00u)
#define PWM_Clock_DIV_INT_SHIFT  (8u)

#else 

#define PWM_Clock_DIV_REG        (*(reg32 *)PWM_Clock__REGISTER)
#define PWM_Clock_ENABLE_REG     PWM_Clock_DIV_REG
#define PWM_Clock_DIV_FRAC_MASK  PWM_Clock__FRAC_MASK
#define PWM_Clock_DIV_FRAC_SHIFT (16u)
#define PWM_Clock_DIV_INT_MASK   PWM_Clock__DIVIDER_MASK
#define PWM_Clock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_PWM_Clock_H) */

/* [] END OF FILE */
