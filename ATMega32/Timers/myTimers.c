/*
* myTimers.c
*
* Created: 3/10/2022 3:45:05 AM
*  Author: User
*/
#include <avr/io.h>
#include "myTimers.h"

void Timer0_CLKSource(int Clk){
	if (Clk <8)
	{
		TCCR0 |= Clk;
	}
	else
	{
	}
}

void Timer0_Mode(int Mode){
	TCCR0 |= Mode;
}

void Timer0_OC0(int Mode){
	DDRB |= (1<<3);
	TCCR0 |= (Mode<<4);
}

void Timer0_INIT(int TimerMode, int Clk, int OC0_state, int dutyCycle){
	Timer0_Mode(TimerMode);
	Timer0_OC0(OC0_state);
	Timer0_OC0_setDutyCycle(dutyCycle);
	//Timer0_Interrupt(TOV_INTERRUPT);
	Timer0_Interrupt(TOC_INTERRUPT);
	Timer0_CLKSource(Clk);
}

void Timer0_Interrupt(int Timer_Interrupt){
	if (Timer_Interrupt == TIMER_INT_OFF)
	{
		TIMSK &= ~((1<<0)|(1<<1));
	}
	else
	{
		TIMSK |= (1<<Timer_Interrupt);
	}
}

void Timer0_SET_COMP(int value){
	OCR0 = value;
}

void Timer0_OC0_setDutyCycle(int dutyCycle){
	OCR0 = 2.55 * (float)dutyCycle;
}
