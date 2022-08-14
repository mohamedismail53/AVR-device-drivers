/*
 * SPI_INT.h
 *
 * Created: 4/7/2021 12:27:38 AM
 *  Author: Mohamed Imsail
 */ 


#ifndef SPI_INT_H_
#define SPI_INT_H_

#include "std_types.h"
#include "Bit_Math.h"
#include "DIO_INT.h"

/******************************************************************************************
*								Preprocessor Macros                                       *
******************************************************************************************/

/* SPI Control Register SPCR */
#define SPCR *((volatile uint8 *)0x2D)
#define SPIE	7
#define SPE		6	
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0


/* SPI Status Register SPSR */
#define SPSR *((volatile uint8 *)0x2E)
#define SPIF	7
#define WCOL	6
#define SPI2X	0


/* SPI Data Register SPDR */
#define SPDR *((volatile uint8 *)0x2F)

/***************************************************************************************
*								Function Prototypes                                    *
***************************************************************************************/


/*********************************************************************************************************
 * Function Name: SPI_Mater_Init
 *
 * Description:  Function to initialize Master of SPI
 *
 * Function Parameters:	 NONE          
 *
 * Returns:				 NONE
 ********************************************************************************************************/
void SPI_Mater_Init(void);

/*********************************************************************************************************
 * Function Name: SPI_Slave_Init
 *
 * Description:  Function to initialize Slave of SPI
 *
 * Function Parameters:	 NONE          
 *
 * Returns:				 NONE
 ********************************************************************************************************/
void SPI_Slave_Init(void);

/*********************************************************************************************************
 * Function Name: SPI_SendByte
 *
 * Description:  Function to send a byte from a Master to a Slave
 *
 * Function Parameters:	 parameter is the transmitted byte           
 *
 * Returns:				 NONE
 ********************************************************************************************************/
void SPI_SendByte(uint8 byte);

/*********************************************************************************************************
 * Function Name: SPI_RecieveByte
 *
 * Description:  Function to recieve a byte from a Master to a Slave
 *
 * Function Parameters:	 NONE           
 *
 * Returns:				 parameter is the recieved byte
 ********************************************************************************************************/
uint8 SPI_RecieveByte(void);


/*********************************************************************************************************
 * Function Name: SPI_SendString
 *
 * Description:  Function to send a string from a Master to a Slave
 *
 * Function Parameters:	 parameter is an array of the transmitted bytes           
 *
 * Returns:				 NONE
 ********************************************************************************************************/
void SPI_SendString(uint8 * str);


/*********************************************************************************************************
 * Function Name: SPI_SendString
 *
 * Description:  Function to send a string from a Master to a Slave
 *
 * Function Parameters:	 parameter is an array of the recieved bytes           
 *
 * Returns:				 NONE
 ********************************************************************************************************/
void SPI_RecieveString(uint8 * str);

#endif