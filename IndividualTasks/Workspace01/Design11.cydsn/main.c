    #include <project.h>
int main()
{
uint8 button1=0;
 /* Must enable interrupts before starting CapSense */
 CyGlobalIntEnable;
 
 CapSense_Start();
 CapSense_ScanAllWidgets(); /* Do initial scan */
 for(;;)
     {
         if(!CapSense_IsBusy())
         {
            CapSense_ProcessAllWidgets();
            button1 = CapSense_IsWidgetActive(CapSense_BUTTON0_WDGT_ID);
            CapSense_ScanAllWidgets();
         }
         led_Write(button1); /* Turn on LED if the button is being pressed */
    }
}