/*
 * SPI_Driver.c
 *
 * Created: 4/6/2021 10:41:15 PM
 * Author : Mohamed Ismial
 */ 

#ifndef F_CPU 
#define F_CPU 8000000UL
#endif
#include "SPI_INT.h"
#include <util/delay.h>


int main(void)
{
	uint8 i = 0;
	DIO_Init();
	SPI_Mater_Init();
	//DIO_SetPinValue(PORTB, PIN4, LOW);
	
    while (1) 
    {
		SPI_SendByte(i);
		_delay_ms(100);
		if (i != 9)
		{
			i++;
		}
		else
		{
			i = 0;
		}
			
    }
}

