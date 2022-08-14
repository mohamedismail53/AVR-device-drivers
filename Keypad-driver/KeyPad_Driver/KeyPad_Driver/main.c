/*
 * KeyPad_Driver.c
 *
 * Created: 10/17/2020 4:29:17 PM
 * Author : Mohamed Ismail
 */ 

#ifndef F_CPU
#define F_CPU	8000000UL
#endif

#include "keyPad_INT.h"
#include "DIO_INT.h"
#include "delay.h"

int main(void)
{
	KeyPad_Init();
	uint8 key;
	DIO_SetPortDirection(PORTC, OUTPUT); /* 7-segment pins as output pins */
	DIO_SetPortValue(PORTC,0xf0); /* 7-segment displays Zero at the beginning */
	while(1)
	{
		key = KeyPad_pressed(); /* get the pressed button from keypad */
		_delay_ms(10);
		if((key >= 0) && (key <= 9))
		{
			DIO_SetPortValue(PORTC, key);
		}
	}
}

