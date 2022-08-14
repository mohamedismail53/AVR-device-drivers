/*
 * EX_Interrupt.c
 *
 * Created: 10/19/2020 3:08:51 PM
 * Author : MohamedIsmail
 */ 

#ifndef F_CPU
#define F_CPU 8000000UL
#endif


#include <util/delay.h>
#include "EX_Interrupt.h"
#include "DIO_INT.h"

void LED_1 (void);
void LED_2 (void);
void LED_3 (void);

uint8 i = 0;


int main(void)
{
	//set global interrupt enable
	sei();
	DIO_Init();
	
	EX_InturruptEdgeTriggering(EX_INT0, FALLING_Edge);
	
	EX_InturruptEnable(EX_INT0);
	
    while (1) 
    {
		if (i == 0)
			SetCallBackFunction(EX_INT0, LED_1);
		else if (i == 1)
			SetCallBackFunction(EX_INT0, LED_2);
		else if (i == 2)
			SetCallBackFunction(EX_INT0, LED_3);
    }
}


void LED_1 (void)
{
	DIO_SetPinValue(PORTA, PIN0, HIGH);
	_delay_ms(500);
	DIO_SetPinValue(PORTA, PIN0, LOW);
	i = 1;
}

void LED_2 (void)
{
	DIO_SetPinValue(PORTA, PIN1, HIGH);
	_delay_ms(500);
	DIO_SetPinValue(PORTA, PIN1, LOW);
	i = 2;
}

void LED_3 (void)
{
	DIO_SetPinValue(PORTA, PIN2, HIGH);
	_delay_ms(500);
	DIO_SetPinValue(PORTA, PIN2, LOW);
	i = 0;
}
