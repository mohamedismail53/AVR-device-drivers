/*
 * SEG_INT.h
 *
 * Created: 2/6/2021 7:15:25 PM
 *  Author: Mohamed Ismail
 */ 


#ifndef SEG_INT_H_
#define SEG_INT_H_

#include "DIO_INT.h"
#include "SEG_CONFIG.h"

#if (BCD_DECODER == 1)
#define SEG_PINA	0
#define SEG_PINB	1
#define SEG_PINC	2
#define SEG_PIND	3

#elif(BCD_DECODER == 0)
#if(SEG_TYPE == 0)
#define ZERO   0b00111111
#define ONE    0b00000110
#define TWO    0b01011011
#define THREE  0b01001111
#define FOUR   0b01100110
#define FIVE   0b01101101
#define SIX    0b01111101
#define SEVEN  0b00000111
#define EIGHT  0b01111111
#define NINE   0b01101111
#elif(SEG_TYPE == 1)
#define ZERO   ~(0b00111111)
#define ONE    ~(0b00000110)
#define TWO    ~(0b01011011)
#define THREE  ~(0b01001111)
#define FOUR   ~(0b01100110)
#define FIVE   ~(0b01101101)
#define SIX    ~(0b01111101)
#define SEVEN  ~(0b00000111)
#define EIGHT  ~(0b01111111)
#define NINE   ~(0b01101111)
#endif
#endif

/*********************************************************************************************************
 * Function Name: Seg_Init
 *
 * Description:  Function to initialize 7 segment
 *
 * Function Parameters:	 NONE    
 *
 * Returns:				 NONE
 ********************************************************************************************************/
void Seg_Init(void);

/*********************************************************************************************************
 * Function Name: Seg_WriteValue
 *
 * Description:  Function to Write a value into 7 Segment
 *
 * Function Parameters:	 number to display     
 *
 * Returns:				 NONE
 ********************************************************************************************************/
void Seg_WriteValue(uint8 num);

/*********************************************************************************************************
 * Function Name: Seg_DisplayEN1
 *
 * Description:  Function to Enable or disable displaying over 7 segment
 *
 * Function Parameters:	 its state ENABLE or DISABLE     
 *
 * Returns:				 NONE
 ********************************************************************************************************/
void Seg_DisplayEN1(uint8 state);

/*********************************************************************************************************
 * Function Name: Seg_DisplayEN2
 *
 * Description:  Function to Enable or disable displaying over 7 segment
 *
 * Function Parameters:	 its state ENABLE or DISABLE     
 *
 * Returns:				 NONE
 ********************************************************************************************************/
void Seg_DisplayEN2(uint8 state);

#endif /* SEG_INT_H_ */