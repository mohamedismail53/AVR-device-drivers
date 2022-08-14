/*
 * SPI_PRG.c
 *
 * Created: 4/7/2021 12:27:19 AM
 *  Author: Mohamed Ismial
 */ 

#include "SPI_INT.h"

void SPI_Mater_Init(void)
{	
	DDRB_REG |= (1 << PIN4); 
	DDRB_REG |= (1 << PIN5);
	DDRB_REG &= ~(1 << PIN6);
	DDRB_REG |= (1 << PIN7); 
	
	SPCR = (1<<SPE) | (1<<MSTR); 
}


void SPI_Slave_Init(void)
{
	DDRB_REG &= ~(1 << PIN4);
	DDRB_REG &= ~(1 << PIN5);
	DDRB_REG |= (1 << PIN6);
	DDRB_REG &= ~(1 << PIN7);
	
	SPCR = (1<<SPE);
}


void SPI_SendByte(uint8 byte)
{
	SPDR = byte;
	while(!RD_BIT(SPSR, SPIF));
}

uint8 SPI_RecieveByte(void)
{
	while(!RD_BIT(SPSR, SPIF));
	return SPDR;
}

void SPI_SendString(uint8 * str)
{
	uint8 i = 0;
	while(str[i] != '\0')
		SPI_SendByte(str[i++]);
}

void SPI_RecieveString(uint8 * str)
{
	uint8 i = 0;
	while(str[i] != '*')
		str[i++] = SPI_RecieveByte();
	str[i] = '\0';
}

