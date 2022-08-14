/*
 * KeyPad_CONFIG.h
 * Description: Interface to get the ID of the pressed key,
 *			    this function doesn't handle the situation if 2 keys are pressed at the same time
 *				user can use two functions KEYPAD_Init(); for initailise port and pins for keypad 
 *				and KEYPAD_pressed(); to check which key is pressed
 * Created: 10/17/2020 4:29:57 PM
 *  Author: Mohamed Ismail
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "DIO_INT.h"

/* Select port which will connect keypad on it */
#define keypad_port	PORTA

/* Select in which pis in keypad_port will connect keypad rows and cols  */
#define ROW0	PIN0
#define ROW1	PIN1
#define ROW2	PIN2
#define ROW3	PIN3

#define COL0	PIN4
#define COL1	PIN5
#define COL2	PIN6
#define COL3	PIN7

/* number of rows and cols */
#define ROWS	4
#define COLS	3

#endif /* KEYPAD_CONFIG_H_ */