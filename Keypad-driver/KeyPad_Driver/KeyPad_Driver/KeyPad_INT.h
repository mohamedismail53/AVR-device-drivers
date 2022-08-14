/*
 * KeyPad_INT.h
 *
 * Created: 10/17/2020 4:30:24 PM
 *  Author: Mohamed Ismail
 */ 


#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#include "KeyPad_CONFIG.h"

/* initialize keypad */ 
void KeyPad_Init(void);

/* check which key is pressed and return ASCII for it , if nothing is pressed return -1 */
uint8 KeyPad_pressed(void);

#endif /* KEYPAD_INT_H_ */