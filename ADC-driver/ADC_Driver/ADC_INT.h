/*
 * ADC_INT.h
 * Description: Assume reference Voltage as AVCC with external capacitor, user can change state by setting and clearing REFS0 AND REFS1 in ADMUX
				also using right adjust assuming that user use 8-bit resolution if user uses 10-bit resolution it's prefer to use left adjust by setting ADLAR in ADMUX
				assuming user uses 10-bit resolution, user should return ADCH instead of ADCL in ADC_Read function using left adjust
				
 * Created: 10/30/2020 6:25:18 PM
 *  Author: MohamedIsmail
 */ 


#ifndef ADC_INT_H_
#define ADC_INT_H_

#include "std_types.h"
#include "Bit_Math.h"

/* Configurations */

/* if DEFAULT this means, reference Voltage as AVCC with external capacitor
 * ,right adjust, and Prescaler Configuration as 128 , if it's 0 then make your own from datasheet */
#define DEFAULT	1
#define  ADC_ADMUX_INITVAL 0b01000000
#define  ADC_ADCSR_INITVAL 0b10000111

//ADC Multiplexer Register
#define ADMUX	(*(volatile uint8 *) 0x27)
#define ADLAR 5
#define REFS0 6
#define REFS1 7

//ADC Control And Status Register
#define	ADCCSRA	(*(volatile uint8 *) 0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7

//ADC Low Register
#define	ADCL	(*(volatile uint8 *) 0x24)

//ADC High Register
#define	ADCH	(*(volatile uint8 *) 0x25)

#define SFIOR	(*(volatile uint8 *) 0x50)

//ADC Initialization And Enable
void ADC_Init(void);

//Read From The ADC Channel
uint16 ADC_Read(uint8 channel);

#endif /* ADC_INT_H_ */