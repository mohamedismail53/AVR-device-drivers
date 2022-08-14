/*
 * EX_Interrupt.h
 *
 * Created: 10/19/2020 3:12:12 PM
 *  Author: MohamedIsmail
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

#include "Interrupt_vect.h"
#include "Bit_Math.h"
#include "std_types.h"

//MCU control register for edge triggering INT0, INT1
#define	MCUCR	(*(volatile uint8*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

//MCU control and status register for edge triggering INT2
#define	MCUCSR	(*(volatile uint8*)0x54)
#define ISC2 6

//General interrupt control register to select external interrupt source (INT0, INT1, INT2)
#define	GICR	(*(volatile uint8*)0x5B)
#define INT1 7
#define INT0 6
#define INT2 5

//General interrupt flag register to check flag bit for (INT0, INT1, INT2)
#define	GIFR	(*(volatile uint8*)0x5A)
#define INTF1 7
#define INTF0 6
#define INTF2 5

typedef enum{
	EX_INT0 = 0,
	EX_INT1,
	EX_INT2
	}EX_InturruptSourceType;
	
typedef enum{
	LOW_LEVEL = 0,
	ANY_CHANGE,
	FALLING_Edge,
	RISING_Edge
	}Edge_TriggerType;

//function to enable Interrupt source, the input for this function is EX_InturruptSourceType enum  ex) EX_InturruptEnable(EX_INT0); to enable INT0
void EX_InturruptEnable(EX_InturruptSourceType ex_int);

//function to disable Interrupt source, the input for this function is EX_InturruptSourceType enum ex) EX_InturruptDisable(EX_INT0); to disable INT0
void EX_InturruptDisable(EX_InturruptSourceType ex_int);

/* function to set edge triggering mode, the input for this function is EX_InturruptSourceType enum and Edge_TriggerType
* ex) EX_InturruptEdgeTriggering(EX_INT0, FALLING_Edge); to control INT0 with falling edge */
void EX_InturruptEdgeTriggering(EX_InturruptSourceType ex_int, Edge_TriggerType edgeType);

//call back function
void SetCallBackFunction(EX_InturruptSourceType ex_int, void (*ptrtofunc)(void)); 

#endif /* EX_INTERRUPT_H_ */