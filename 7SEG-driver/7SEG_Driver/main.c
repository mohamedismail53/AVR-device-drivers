/*
 * 7SEG_Driver.c
 *
 * Created: 2/6/2021 7:14:05 PM
 * Author : Mohamed Ismail
 */ 

#define F_CPU	1000000UL
#include <util/delay.h>
#include "DIO_INT.h"
#include "SEG_INT.h"


int main(void)
{
    /* Replace with your application code */
	Seg_Init();
	Seg_DisplayEN2(ENABLE);
	DIO_SetPinDirection(PORTA, PIN0, INPUT);
	DIO_SetPinDirection(PORTA, PIN1, INPUT);
	DIO_SetPinValue(PORTA, PIN0, HIGH);
	DIO_SetPinValue(PORTA, PIN1, HIGH);
	DIO_SetPinDirection(PORTB, PIN0, OUTPUT);
	DIO_SetPinDirection(PORTB, PIN1, OUTPUT);
	DIO_SetPinValue(PORTB, PIN0, LOW);
	DIO_SetPinValue(PORTB, PIN1, LOW);
	uint8 i = 0;
    while (1) 
    {
		
		if (DIO_RdPinValue(PORTA, PIN0) == 0)
		{
			while(DIO_RdPinValue(PORTA, PIN0) == 0);
			i++;
			Seg_WriteValue(i);
			if (i == 9)
			{
				DIO_SetPinValue(PORTB, PIN0, HIGH);
				i = 0;
			}
		}
		
		if (DIO_RdPinValue(PORTA, PIN1) == 0)
		{
			while(DIO_RdPinValue(PORTA, PIN1) == 0);
			i--;
			Seg_WriteValue(i);
			if (i == 0)
			{
				DIO_SetPinValue(PORTB, PIN1, HIGH);
				i = 1;
			}
		}
		_delay_ms(1000);
		if (i == 0 || i == 1)
		{
			DIO_SetPinValue(PORTB, PIN0, LOW);
			DIO_SetPinValue(PORTB, PIN1, LOW);
		}
    }
}

