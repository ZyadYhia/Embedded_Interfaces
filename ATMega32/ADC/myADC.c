/*
* myADC.c
*
* Created: 3/9/2022 3:58:47 AM
*  Author: User
*/
#include <avr/io.h>
#include "myADC.h"


void ADC_CH(int channelNo){
	/*
	ADMUX = 0xE0;
	ADMUX |= channelNo;
	
	To Prevent Reading During changing channel throw the last two instructions
	*/
	if (channelNo < 8)
	{
		ADMUX = (ADMUX & 0xE0)|channelNo;
	}
}

void ADC_REF(int Ref){
	ADMUX |= (ADMUX & 0x3F)|(Ref<<6);
}

void ADC_FREQ(int Prescaler){
	if (ADCSRA & (1<<ADIE))
	{
		ADCSRA &= ~(1<<ADIE);
		ADCSRA |= (Prescaler);
		ADCSRA |= (1<<ADIE);
		} else {
		ADCSRA |= (Prescaler);
	}
	
}

void ADC_INIT(int channelNo, int Ref, int Prescaler){
	ADC_CH(channelNo);
	ADC_REF(Ref);
	ADC_FREQ(Prescaler);
	ADCSRA |= (1<<ADIE);
	ADCSRA |= (1<<ADEN);
}

void ADC_StartConv(){
	ADCSRA |= (1<<ADSC);
}

int ADC_Read(void){
	int val = ADCL;
	val |= (ADCH<<8);
	return val;
}

void waitConversion(void){
	//wait flag
	while(!(ADCSRA & (1<<ADIF)));
}