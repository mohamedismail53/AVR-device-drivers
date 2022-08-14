/*
 * SEG_PRG.c
 *
 * Created: 2/6/2021 7:15:04 PM
 *  Author: Mohamed Ismail
 */ 

#include "SEG_INT.h"

void Seg_Init(void)
{
	#if (BCD_DECODER == 1)
	DIO_SetPinDirection(SEG_PORT, SEG_PINA, OUTPUT);
	DIO_SetPinDirection(SEG_PORT, SEG_PINB, OUTPUT);
	DIO_SetPinDirection(SEG_PORT, SEG_PINC, OUTPUT);
	DIO_SetPinDirection(SEG_PORT, SEG_PIND, OUTPUT);
	#else
	DIO_SetPortDirection(SEG_PORT, OUTPUT);
	#endif
	DIO_SetPinDirection(SEG_CONTROL_PORT, SEG1_EN, OUTPUT);
	DIO_SetPinDirection(SEG_CONTROL_PORT, SEG2_EN, OUTPUT);
	Seg_DisplayEN1(DISABLE);
	Seg_DisplayEN2(DISABLE);
	Seg_WriteValue(0);
}

void Seg_DisplayEN1(uint8 state)
{
	DIO_SetPinDirection(SEG_CONTROL_PORT, SEG1_EN, state);
}


void Seg_DisplayEN2(uint8 state)
{
	DIO_SetPinDirection(SEG_CONTROL_PORT, SEG2_EN, state);
}

void Seg_WriteValue(uint8 num)
{
	#if (BCD_DECODER == 1)
	switch(num)
	{
		case 0:
			DIO_SetPinValue(SEG_PORT, SEG_PINA, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PINB, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PINC, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PIND, LOW);
			break;
		case 1:
			DIO_SetPinValue(SEG_PORT, SEG_PINA, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PINB, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PINC, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PIND, LOW);
			break;
		case 2:
			DIO_SetPinValue(SEG_PORT, SEG_PINA, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PINB, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PINC, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PIND, LOW);
			break;
		case 3:
			DIO_SetPinValue(SEG_PORT, SEG_PINA, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PINB, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PINC, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PIND, LOW);
			break;
		case 4:
			DIO_SetPinValue(SEG_PORT, SEG_PINA, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PINB, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PINC, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PIND, LOW);
			break;
		case 5:
			DIO_SetPinValue(SEG_PORT, SEG_PINA, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PINB, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PINC, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PIND, LOW);
			break;
		case 6:
			DIO_SetPinValue(SEG_PORT, SEG_PINA, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PINB, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PINC, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PIND, LOW);
			break;
		case 7:
			DIO_SetPinValue(SEG_PORT, SEG_PINA, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PINB, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PINC, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PIND, LOW);
			break;
		case 8:
			DIO_SetPinValue(SEG_PORT, SEG_PINA, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PINB, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PINC, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PIND, HIGH);
			break;
		case 9:
			DIO_SetPinValue(SEG_PORT, SEG_PINA, HIGH);
			DIO_SetPinValue(SEG_PORT, SEG_PINB, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PINC, LOW);
			DIO_SetPinValue(SEG_PORT, SEG_PIND, HIGH);
			break;
		default:	break;
	}
	#else
	switch(num)
	{
		case 0:
			DIO_SetPortValue(SEG_PORT, ZERO);
			break;
		case 1:
			DIO_SetPortValue(SEG_PORT, ONE);
			break;
		case 2:
			DIO_SetPortValue(SEG_PORT, TWO);
			break;
		case 3:
			DIO_SetPortValue(SEG_PORT, THREE);
			break;
		case 4:
			DIO_SetPortValue(SEG_PORT, FOUR);
			break;
		case 5:
			DIO_SetPortValue(SEG_PORT, FIVE);
			break;
		case 6:
			DIO_SetPortValue(SEG_PORT, SIX);
			break;
		case 7:
			DIO_SetPortValue(SEG_PORT, SEVEN);
			break;
		case 8:
			DIO_SetPortValue(SEG_PORT, EIGHT);
			break;
		case 9:
			DIO_SetPortValue(SEG_PORT, NINE);
			break;
		default:	break;
	}
	#endif
}