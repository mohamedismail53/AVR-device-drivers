/*
 * KeyPad_PRG.c
 *
 * Created: 10/17/2020 4:30:47 PM
 * Author: Mohamed Ismail
 */ 


#ifndef F_CPU
#define F_CPU	8000000UL
#endif
#include "KeyPad_INT.h"
#include "delay.h"



/* private functions */
#if (COLS == 3)
	static uint8 KeyPad4x3(uint8 pressed_number);
	
#elif (COLS == 4)
	static uint8 KeyPad4x4(uint8 pressed_number);
#endif 



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/* initialize keypad */
void KeyPad_Init(void)
{
	/* Set rows direction to be output */
	DIO_SetPinDirection(keypad_port, ROW0, OUTPUT);
	DIO_SetPinDirection(keypad_port, ROW1, OUTPUT);
	DIO_SetPinDirection(keypad_port, ROW2, OUTPUT);
	DIO_SetPinDirection(keypad_port, ROW3, OUTPUT);
	
	/* Set cols direction to be inputs */
	#if (COLS == 3)
		DIO_SetPinDirection(keypad_port, COL0, INPUT);
		DIO_SetPinDirection(keypad_port, COL1, INPUT);
		DIO_SetPinDirection(keypad_port, COL2, INPUT);
		/* connect pull up resistance to the input pins */
		DIO_SetPinValue(keypad_port, COL0, HIGH);
		DIO_SetPinValue(keypad_port, COL1, HIGH);
		DIO_SetPinValue(keypad_port, COL2, HIGH);
		
	#elif (COLS == 4)
		DIO_SetPinDirection(keypad_port, COL0, INPUT);
		DIO_SetPinDirection(keypad_port, COL1, INPUT);
		DIO_SetPinDirection(keypad_port, COL2, INPUT);
		DIO_SetPinDirection(keypad_port, COL3, INPUT);
		/* connect pull up resistance to the input pins */
		DIO_SetPinValue(keypad_port, COL0, HIGH);
		DIO_SetPinValue(keypad_port, COL1, HIGH);
		DIO_SetPinValue(keypad_port, COL2, HIGH);
		DIO_SetPinValue(keypad_port, COL3, HIGH);
	#endif
}

/* check which key is pressed and return THE NUMBER for it */
uint8 KeyPad_pressed(void)
{
	uint8 row_count, col_count;
	while(1)
	{
		/* looping on rows */
		for (row_count = 0; row_count < ROWS; row_count++)
		{
			DIO_SetPinValue(keypad_port, ROW0, HIGH);
			DIO_SetPinValue(keypad_port, ROW1, HIGH);
			DIO_SetPinValue(keypad_port, ROW2, HIGH);
			DIO_SetPinValue(keypad_port, ROW3, HIGH);
			_delay_ms(20);
			/* write 0 to the corresponding row in keypad*/
			DIO_SetPinValue(keypad_port, ROW0 + row_count, LOW);
		
			/* looping on cols */
			for (col_count = 0; col_count < COLS; col_count++)
			{
				/* check if number [row][col] is pressed */	
				if (DIO_RdPinValue(keypad_port, col_count + COL0) == 0)
				{
					_delay_ms(10);
					if (DIO_RdPinValue(keypad_port, col_count + COL0) == 0)
					{
						/* Get the value of the currently pressed switch */
						#if (COLS == 3)
						return KeyPad4x3((row_count*COLS)+col_count+1);
						#elif (COLS == 4)
						return KeyPad4x4((row_count*COLS)+col_count+1);
						#endif
					}
				}
			}
		}
	}
}

#if (COLS == 3)
static uint8 KeyPad4x3(uint8 pressed_number)
{
	switch(pressed_number)
	{
		case 10: return '*';
		break;
		case 11: return 0;
		break;
		case 12: return '#'; 
		break;
		default: return pressed_number;
	}
}

#elif (COLS == 4)
static uint8 KeyPad4x4(uint8 pressed_number)
{
	switch(pressed_number)
	{
		case 1: return 7;
		break;
		case 2: return 8;
		break;
		case 3: return 9;
		break;
		case 4: return '%'; 
		break;
		case 5: return 4;
		break;
		case 6: return 5;
		break;
		case 7: return 6;
		break;
		case 8: return '*'; 
		break;
		case 9: return 1;
		break;
		case 10: return 2;
		break;
		case 11: return 3;
		break;
		case 12: return '-';
		break;
		case 13: return 13;  
		break;
		case 14: return 0;
		break;
		case 15: return '='; 
		break;
		case 16: return '+'; 
		break;
	}
}

#endif

