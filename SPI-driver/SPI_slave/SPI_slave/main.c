/*
 * SPI_slave.c
 *
 * Created: 4/7/2021 1:19:26 AM
 * Author : hp
 */ 

#define F_CPU	8000000UL
#include "SPI_INT.h"
#include "SEG_INT.h"
#include <util/delay.h>

/*
int main(void)
{
	DIO_Init();
    SPI_Slave_Init();
	Seg_Init();
	
    while (1) 
    {
		uint8 A = SPI_RecieveByte();
		Seg_WriteValue(A);
		_delay_ms(100);	
    }
}*/


int main(void)
{
	DIO_Init();
	SPI_Slave_Init();
	Seg_Init();
	
	while (1)
	{
		uint8 A = SPI_RecieveByte();
		Seg_WriteValue(A);
		_delay_ms(100);
	}
}
