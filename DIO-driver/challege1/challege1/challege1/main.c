/*
 * challege1.c
 * Description: count from 0 to 9 into a 7-seg 
 * Created: 1/19/2021 10:55:26 PM
 * Author : Mohamed Ismail
 */ 

#ifndef F_CPU
#define  F_CPU 8000000ul
#endif

#include "DIO_INT.h"
#include <util/delay.h>


/*
static uint8 arr_7seg[] = {0x3f, 0x06, 0x5b, 0x4f,
						   0x66, 0x6d, 0x7d, 0x07,
						   0x7f, 0x6f};

 
int main(void)
{
    DIO_SetPortDirection(PORTD, 127);
	
    while (1) 
    {
		for (uint8 i = 0; i < 10; i++)
		{
			DIO_SetPortValue(PORTD, arr_7seg[i]);
			_delay_ms(1000);
		}
    }
}
*/

// test ports

/*
int main(void)
{
	DIO_SetPortDirection(PORTD, 0XFF);
	DIO_SetPortValue(PORTD, 0);
	uint8 i = 0;
	while (1)
	{
			DIO_SetPinValue(PORTD, i , HIGH);
			_delay_ms(1000);
			DIO_SetPinValue(PORTD, i , LOW);
			if (i == 8)
			{
				i = 0;
			}
			else
			{
				i++;
			}
	}
}*/



int main(void)
{
	DIO_Init();
	DIO_SetPortDirection(PORTA, 255);
	DIO_SetPinDirection(PORTB, PIN0, OUTPUT);
	DIO_SetPortDirection(PORTC, OUTPUT);
	DIO_SetPortDirection(PORTD, INPUT);
	
	DIO_SetPinValue(PORTB, PIN0, HIGH);
	DIO_SetPortValue(PORTA, 15);
	_delay_ms(1000);
	DIO_SetPortValue(PORTA, 3);
	_delay_ms(1000);
	DIO_SetPortValue(PORTA, 0);
	DIO_SetPortValue(PORTD, 255);
	while(1)
	{
		if (DIO_RdPinValue(PORTD, PIN0) == 0)
		{
			DIO_SetPinValue(PORTB, PIN0, LOW);
		}
		if (DIO_RdPortValue(PORTD) == (uint8)(~2))
		{
			DIO_SetPortValue(PORTA, 15);
		}
	}
}
