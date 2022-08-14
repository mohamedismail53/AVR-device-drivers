/* Group of register for PORTA */
#define DDRA_REG	*((volatile uint8 *)0x3A)
#define PINA_REG	*((volatile uint8 *)0x39)
#define PORTA_REG	*((volatile uint8 *)0x3B)

/* Group of register for PORTB */
#define DDRB_REG	*((volatile uint8 *)0x37)
#define PINB_REG	*((volatile uint8 *)0x36)
#define PORTB_REG	*((volatile uint8 *)0x38)

/* Group of register for PORTC */
#define DDRC_REG	*((volatile uint8 *)0x34)
#define PINC_REG	*((volatile uint8 *)0x33)
#define PORTC_REG	*((volatile uint8 *)0x35)

/* Group of register for PORTD */
#define DDRD_REG	*((volatile uint8 *)0x31)
#define PIND_REG	*((volatile uint8 *)0x30)
#define PORTD_REG	*((volatile uint8 *)0x32)

#ifndef F_CPU	
#define F_CPU	8000000UL
#endif
#include <util/delay.h>
#include "Servo.h"


int main(void)
{
   Servo_Init();

   DDRD_REG|=(1<<4)|(1<<5);   //PWM Pins as Out

   while(1)
   {

		Servo_SetAngle(0);
		_delay_ms(10000);
		Servo_SetAngle(90);
		_delay_ms(10000);
   }
}