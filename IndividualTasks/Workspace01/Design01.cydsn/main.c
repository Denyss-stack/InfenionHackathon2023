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
#define POT_CHAN (0)
int main(void)
{
    int16 counts = 0;
    int16 mVolts =0;
    CyGlobalIntEnable; /* Enable global interrupts. */
    ADC_Start();
    ADC_StartConvert();
    LCD_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    

    for(;;)
    {
        counts = ADC_GetResult16(POT_CHAN);
        mVolts = ADC_CountsTo_mVolts(POT_CHAN, counts);
        LCD_Position(0,0);
        LCD_PrintNumber(mVolts);
        LCD_PrintString("mV " );
        
    }
}

/* [] END OF FILE */
