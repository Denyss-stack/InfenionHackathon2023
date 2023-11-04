/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
uint8 counts = 0;
CY_ISR_PROTO(my_ISR);
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_1_StartEx(my_ISR);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    for(;;)
    {
       LED_Write(1);
       
    }
}
CY_ISR(my_ISR){
    counts++;
}

/* [] END OF FILE */
