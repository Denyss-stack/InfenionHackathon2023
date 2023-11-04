#include <project.h>
#define POT_CHAN (0)
#define WRITABLE (3)
int main()
{
    int16 counts; /* ADC result in counts */
    int16 mVolts; /* ADC result in mVolts */

    uint8 i2cReg[3]; /* 1 byte I2C register */
    EZI2C_Start();
    EZI2C_EzI2CSetBuffer1(sizeof(i2cReg), WRITABLE, i2cReg);
    ADC_Start();
    ADC_StartConvert();
    LCD_Start();

    CyGlobalIntEnable;
    for(;;)
    {
        counts = ADC_GetResult16(POT_CHAN);
        mVolts = ADC_CountsTo_mVolts(POT_CHAN,counts);
        //if ((mVolts>= 0x0000) && (mVolts <= 0x000F)){
        //i2cReg[2] = 1;
        //}
        int pot_state =  (mVolts >> 10) +1;
        i2cReg[2] = pot_state;
        
        
        
        

             
        
    
    /* Store ADC value in I2C buffer */
        CyDelay(100);
    }
}

