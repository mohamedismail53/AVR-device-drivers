/*
 * ADC_PRG.c
 *
 * Created: 10/30/2020 6:25:38 PM
 *  Author: MohamedIsmail
 */ 

#include "ADC_INT.h"

//ADC Initialization And Enable
void ADC_Init(void)
{
	#if(DEFAULT == 1)
		//enable ADC
		SET_BIT(ADCCSRA, ADEN);
	
		//reference Voltage as AVCC with external capacitor
		CLR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
	
		//right adjust
		CLR_BIT(ADMUX, ADLAR);
	
		//Prescaler Configuration as 128
		SET_BIT(ADCCSRA, ADPS0);
		SET_BIT(ADCCSRA, ADPS1);
		SET_BIT(ADCCSRA, ADPS2);
	#elif(DEFAULT == 0)
		ADMUX = ADC_ADMUX_INITVAL;
		ADCCSRA = ADC_ADCSR_INITVAL;
	#endif
}

//Read From The ADC Channel
uint16 ADC_Read(uint8 channel)
{
	uint16 ret = 0;
	//ADC Channel Selection
	ADMUX = (ADMUX & 0xE0) | channel;
	
	//Start conversion
	SET_BIT(ADCCSRA, ADSC);
	
	//wait until the end of conversion
	while(RD_BIT(ADCCSRA, ADIF) !=0);
	
	//ADC Flag Clear
	SET_BIT(ADCCSRA, ADIF);
	
	ret = ADCL;
	ret |= ((uint16) (ADCH << 8)); 
	
	return ret;
}