/*
 * ADC_Driver.c
 *
 * Created: 10/30/2020 6:24:38 PM
 * Author : hp
 */ 

#include "ADC_INT.h"
#include "LCD_INT.h"


/*int main(void)
{
	uint16 x;
    ADC_Init();
	LCD_Init();
	x = ADC_Read(0);
    while (1) 
    {
		x = ADC_Read(0);
		LCD_SendString("ADC: ");
		LCD_SendNumber(x);
		_delay_ms(1000);
		LCD_Clear();
    }
}*/

int main(void)
{
	uint16 temp, x;
	ADC_Init();
	LCD_Init();
	x = ADC_Read(0);
	while (1)
	{
		LCD_Clear();
		x = ADC_Read(0);
		LCD_SendString("Temp: ");
		temp = x/2;
		LCD_SendNumber(temp);
		_delay_ms(500);
	}
}

