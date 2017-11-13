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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    DAC_Start();
    LCD_Start();
    uint8 output_analog;
    for(;;)
    {
        /* Place your application code here. */
        output_analog = DAC_Data;
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintString("DAC");
        LCD_Position(1,0)
        LCD_PrintNumber(output_analog);
        CyDelay(500);
    }
}

/* [] END OF FILE */
