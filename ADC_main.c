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
    int data[100];
    int i;
    uint8 baca;
    CyGlobalIntEnable; /* Enable global interrupts. */
    ADC_Start();
    LCD_Start();
    ADC_StartConvert();
    
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;) {
       if(ADC_IsEndConversion(ADC_RETURN_STATUS)){
        baca = ADC_GetResult8();
    }
    data[0]=(baca & 0b10000000 ? 1 : 0);
    data[1]=(baca & 0b01000000 ? 1 : 0);
    data[2]=(baca & 0b00100000 ? 1 : 0);
    data[3]=(baca & 0b00010000 ? 1 : 0);
    data[4]=(baca & 0b00001000 ? 1 : 0);
    data[5]=(baca & 0b00000100 ? 1 : 0);
    data[6]=(baca & 0b00000010 ? 1 : 0);
    data[7]=(baca & 0b00000001 ? 1 : 0);
   
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintNumber(baca);
    
    for ( i=0;i<8;i++) {
       LCD_Position(1,i);
        LCD_PrintNumber(data[i]);
    }
        CyDelay(100);
}}

/* [] END OF FILE */
