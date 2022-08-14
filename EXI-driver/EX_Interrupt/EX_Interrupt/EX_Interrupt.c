/*
 * EX_Interrupt.c
 *
 * Created: 10/19/2020 4:05:48 PM
 *  Author: MohamedIsmail
 */ 

#include "EX_Interrupt.h"

#define NULL (void *)(0)

//pointer to functions
static void (*INT0_ptr)(void) = NULL;
static void (*INT1_ptr)(void) = NULL;
static void (*INT2_ptr)(void) = NULL;


//function to enable Interrupt source, the input for this function is EX_InturruptSourceType enum  ex) EX_InturruptEnable(EX_INT0); to enable INT0
void EX_InturruptEnable(EX_InturruptSourceType ex_int)
{
	switch(ex_int)
	{
		case EX_INT0:	SET_BIT(GICR, INT0);	break;
		case EX_INT1:	SET_BIT(GICR, INT1);	break;
		case EX_INT2:	SET_BIT(GICR, INT2);	break;
	}
}


//function to disable Interrupt source, the input for this function is EX_InturruptSourceType enum ex) EX_InturruptDisable(EX_INT0); to disable INT0
void EX_InturruptDisable(EX_InturruptSourceType ex_int)
{
	switch(ex_int)
	{
		case EX_INT0:	CLR_BIT(GICR, INT0);	break;
		case EX_INT1:	CLR_BIT(GICR, INT1);	break;
		case EX_INT2:	CLR_BIT(GICR, INT2);	break;
	}	
}


//function to set edge triggering mode, the input for this function is EX_InturruptSourceType enum and Edge_TriggerType
//ex) EX_InturruptEdgeTriggering(EX_INT0, FALLING_Edge); to control INT0 with falling edge
void EX_InturruptEdgeTriggering(EX_InturruptSourceType ex_int, Edge_TriggerType edgeType)
{
	switch(ex_int)
	{
		case EX_INT0:
		switch(edgeType)
		{
			case LOW_LEVEL:		CLR_BIT(MCUCR, ISC00);
								CLR_BIT(MCUCR, ISC01);
								break;
			case ANY_CHANGE:	SET_BIT(MCUCR, ISC00);
								CLR_BIT(MCUCR, ISC01);
								break;
			case FALLING_Edge:	CLR_BIT(MCUCR, ISC00);
								SET_BIT(MCUCR, ISC01);
								break;
			case RISING_Edge:	SET_BIT(MCUCR, ISC00);
								SET_BIT(MCUCR, ISC01);
								break;					
		}
		break;
		
		case EX_INT1:
		switch(edgeType)
		{
			case LOW_LEVEL:		CLR_BIT(MCUCR, ISC10);
								CLR_BIT(MCUCR, ISC11);
								break;
			case ANY_CHANGE:	SET_BIT(MCUCR, ISC10);
								CLR_BIT(MCUCR, ISC11);
								break;
			case FALLING_Edge:	CLR_BIT(MCUCR, ISC10);
								SET_BIT(MCUCR, ISC11);
								break;
			case RISING_Edge:	SET_BIT(MCUCR, ISC10);
								SET_BIT(MCUCR, ISC11);
								break;
		}
		break;
		case EX_INT2:
		switch(edgeType)
		{
			case FALLING_Edge:	CLR_BIT(MCUCSR, ISC2);		break;
			case RISING_Edge:	SET_BIT(MCUCSR, ISC2);		break;
			default:			CLR_BIT(MCUCSR, ISC2);		break;
		}
		break;
	}
}

//call back function
void SetCallBackFunction(EX_InturruptSourceType ex_int, void (*ptrtofunc)(void))
{
	switch(ex_int)
	{
		case EX_INT0:	INT0_ptr = ptrtofunc;	break;
		case EX_INT1:	INT1_ptr = ptrtofunc;	break;
		case EX_INT2:	INT2_ptr = ptrtofunc;	break;
	}
}

ISR(INT0_vect)
{
	if (INT0_ptr != NULL)
	{
		INT0_ptr();
	}
}

ISR(INT1_vect)
{
	if (INT1_ptr != NULL)
	{
		INT1_ptr();
	}
}

ISR(INT2_vect)
{
	if (INT2_ptr != NULL)
	{
		INT2_ptr();
	}
}


