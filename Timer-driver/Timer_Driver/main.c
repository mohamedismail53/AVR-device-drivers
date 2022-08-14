/*
 * Timer_Test.c
 *
 * Created: 4/29/2021 4:45:40 AM
 * Author : Mohamed Ismail
 */ 


#include "Timer_INT.h"

#define F_CPU	8000000UL

#include <util/delay.h>
#include "DIO_INT.h"
#include "LCD_INT.h"


uint8 c = 0;
unsigned short Current=0;


int long GPT_GetTime()
{
	int Cycles;
	int long Time;
	Cycles= c *256 + TCNT0;
	Time= (Cycles * 1000UL) /80000;

	return Time;
}

void interrupt_service(void)
{
	c++;
}

void PWM_SetDutyCycle(char val)
{
	OCR0= (val*255)/100;
}


unsigned short ICU_GetCurrent()
{
	return Current;
}

void ICU_Read()
{
	Current = ICR1L;
	Current= Current | ((unsigned short)ICR1H <<8);
}



/*
int main(void)
{
	uint8 st = 0;
	sei();
	DDRD_REG = 0XFF;
	PORTD_REG = 0X00;
	Timer0_Init(Timer0_Normal_Mode, Timer_Scaler_8, OCO_Disconnected);
	SetCallBack_Timer0_OVF(interrupt_service);
	Timer0_OV_InterruptEnable();
    while (1) 
    {
		if (GPT_GetTime() >= 10000)
		{
			if (st == 0)
			{
				PORTD_REG = 0xff;
				st = 1;
			}
			else
			{
				PORTD_REG = 0;
				st = 0;	
			}
			c = 0;
			TCNT0 = 0;
		}
    }
}
*/
/*
int main(void)
{
	char duty=0;
	DDRB_REG=0xff;
	Timer0_Init(Timer0_CTC_Mode, Timer_Scaler_1024, OCO_Toggle);
	while(1)
	{
		//TODO:: Please write your application code
		PWM_SetDutyCycle(duty);
		_delay_ms(500);
		if(duty!=100)
		{
			duty=duty+10;
		}
		else
		{
			duty=0;
		}
		
		
	}
}*/

/*int main(void)
{
	unsigned short CurrentValue=0;
	sei();
	DIO_Init();
	Timer1_Init(Normal_Mode, Timer_Scaler_1024, OC1A_Disconnected, OC1B_Disconnected);
	Timer1_InputCaptureEdge(FALLING);
	SetCallBack_Timer1_ICU(ICU_Read);
	Timer1_ICU_InterruptEnable();
	LCD_Init();
	while(1)
	{
		CurrentValue=ICU_GetCurrent();
		LCD_SendString("Timer= ");
		LCD_SendNumber(CurrentValue);
		_delay_ms(200);
		LCD_SendCommand(0x01);
	}
}*/


// watchdog test
int main(void)
{
	WDT_ON();
	DDRD_REG=0xFF;
	PORTD_REG=0x00;
	
	while(1)
	{
		PORTD_REG^=(1<<7);
		_delay_ms(2010);
		__asm__("WDR");	
	}
}