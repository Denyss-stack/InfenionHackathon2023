#include <project.h>
/* ADC channel 0 */
#define POT_CHAN (0)
#define WRITABLE (0)
int main()
{
 int16 counts; /* ADC result in counts */
 int16 mVolts; /* ADC result in mVolts */
 uint8 i2cReg[2]; /* 2 byte I2C register */
 
 ADC_Start();
 ADC_StartConvert();
 LCD_Start();
 EZI2C_Start();
 
 /* 2 byte I2C buffer, 0 bytes writeable by the host, name is I2CReg */
 EZI2C_EzI2CSetBuffer1(sizeof(i2cReg), WRITABLE, i2cReg);
 CyGlobalIntEnable;
 for(;;)
 {
     /* Get ADC result and convert to mV */
     counts = ADC_GetResult16(POT_CHAN);
     mVolts = ADC_CountsTo_mVolts(POT_CHAN,counts);
     
     /* Display value to LCD */
     LCD_Position(0,0);
     LCD_PrintNumber(mVolts);
     LCD_PrintString("mV ");
     
     /* Store ADC value in I2C buffer */
     i2cReg[0] = HI8(mVolts); /* upper byte of result */
     i2cReg[1] = LO8(mVolts); /* lower byte of result */
 }
}