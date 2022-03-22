/*
* keypad.c
*
* Created: 2/28/2022 2:52:58 AM
*  Author: User
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"

void initKeypad(){
	DDRx |= ((1<<0) | (1<<1) | (1<<2));
	DDRx &= ~((1<<3) | (1<<4) | (1<<5) | (1<<6));
	PORTx |= ((1<<0) | (1<<1) | (1<<2));
}

int scanKeypad() {
	PORTx |= ((1<<0) | (1<<1) | (1<<2));
	if (PINx & (1<<3))
	{
		PORTx |= (1<<0);
		PORTx &= ~((1<<1) | (1<<2)); // pin 0 is high
		if (PINx & (1<<3)){/* key 1 */ return 1;}
		_delay_ms(50);
		
		PORTx |= (1<<1);
		PORTx &= ~((1<<0) | (1<<2)); // pin 1 is high
		if (PINx & (1<<3)){/* key 2 */ return 2;}
		_delay_ms(50);
		
		PORTx |= (1<<2);
		PORTx &= ~((1<<0) | (1<<1)); // pin 2 is high
		if (PINx & (1<<3)){/* key 3 */ return 3;}
		_delay_ms(50);
	}
	if (PINx & (1<<4))
	{
		PORTx |= (1<<0);
		PORTx &= ~((1<<1) | (1<<2)); // pin 0 is high
		if (PINx & (1<<4)){/* key 4 */ return 4;}
		_delay_ms(50);
		
		PORTx |= (1<<1);
		PORTx &= ~((1<<0) | (1<<2)); // pin 1 is high
		if (PINx & (1<<4)){/* key 5 */ return 5;}
		_delay_ms(50);
		
		PORTx |= (1<<2);
		PORTx &= ~((1<<0) | (1<<1)); // pin 2 is high
		if (PINx & (1<<4)){/* key 6 */ return 6;}
		_delay_ms(50);
	}
	if (PINx & (1<<5))
	{
		PORTx |= (1<<0);
		PORTx &= ~((1<<1) | (1<<2)); // pin 0 is high
		if (PINx & (1<<5)){/* key 7 */ return 7;}
		_delay_ms(50);
		
		PORTx |= (1<<1);
		PORTx &= ~((1<<0) | (1<<2)); // pin 1 is high
		if (PINx & (1<<5)){/* key 8 */ return 8;}
		_delay_ms(50);
		
		PORTx |= (1<<2);
		PORTx &= ~((1<<0) | (1<<1)); // pin 2 is high
		if (PINx & (1<<5)){/* key 9 */ return 9;}
		_delay_ms(50);
	}
	if (PINx & (1<<6))
	{
		PORTx |= (1<<0);
		PORTx &= ~((1<<1) | (1<<2)); // pin 0 is high
		if (PINx & (1<<6)){/* key * */ return 0;}
		_delay_ms(50);
		
		PORTx |= (1<<1);
		PORTx &= ~((1<<0) | (1<<2)); // pin 1 is high
		if (PINx & (1<<6)){/* key 0 */ return 0;}
		_delay_ms(50);
		
		PORTx |= (1<<2);
		PORTx &= ~((1<<0) | (1<<1)); // pin 2 is high
		if (PINx & (1<<6)){/* key # */ return 0;}
		_delay_ms(50);
	}
	return '-';
}

