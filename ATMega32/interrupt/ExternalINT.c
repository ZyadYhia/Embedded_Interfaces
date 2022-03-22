/*
 * ExternalINT.c
 *
 * Created: 3/4/2022 1:25:36 AM
 *  Author: User
 */ 
#include <avr/io.h>
#include "ExternalINT.h"


void INT0_Init(int Mode){
	switch (Mode)
	{
		case AnyLogicalChangeMode: 
		//INT0 In Any Logical Change Sense Mode From Micro-controller Control Register [ICS00 -> 1, ICS01 ->0]
		MCUCR &= ~(1<<ISC01);
		MCUCR |= (1<<ISC00);
		break;
		case RisingMode: 
		//INT0 In Rising Edge Sense Mode From Micro-controller Control Register [ICS00 -> 1, ICS01 ->1]
		MCUCR |= ((1<<ISC00) | (1<<ISC01));
		break;
		case FallingMode: 
		//INT0 In Any Logical Change Sense Mode From Micro-controller Control Register [ICS00 -> 0, ICS01 ->1]
		MCUCR |= (1<<ISC01);
		MCUCR &= ~(1<<ISC00);
		break;
		case LowLevelMode:
		//INT0 In Low Level Sense Mode From Micro-controller Control Register [ICS00 -> 1, ICS01 ->0]
		MCUCR &= ~((1<<ISC00)|(1<<ISC01));
		break;
	}
	//Enable INT0 from General Interrupt Control Register
	GICR |= (1<<INT0);
}

void INT1_Init(int Mode){
	switch (Mode)
	{
		case AnyLogicalChangeMode:
		//INT0 In Any Logical Change Sense Mode From Micro-controller Control Register [ICS10 -> 1, ICS11 ->0]
		MCUCR &= ~(1<<ISC11);
		MCUCR |= (1<<ISC10);
		break;
		case RisingMode:
		//INT0 In Rising Edge Sense Mode From Micro-controller Control Register [ICS10 -> 1, ICS11 ->1]
		MCUCR |= ((1<<ISC10) | (1<<ISC11));
		break;
		case FallingMode:
		//INT0 In Falling Edge Sense Mode From Micro-controller Control Register [ICS10 -> 0, ICS11 ->1]
		MCUCR |= (1<<ISC11);
		MCUCR &= ~(1<<ISC10);
		break;
		case LowLevelMode:
		//INT0 In Low Level Sense Mode From Micro-controller Control Register [ICS10 -> 1, ICS11 ->0]
		MCUCR &= ~((1<<ISC10)|(1<<ISC11));
		break;
	}
	//Enable INT0 from General Interrupt Control Register
	GICR |= (1<<INT1);
}

void INT2_Init(int Mode){
	switch (Mode)
	{
		case RisingMode:
		//INT0 In Rising Edge Sense Mode From Micro-controller Control and Status Register [ICS2 -> 1]
		MCUCSR |= (1<<ISC2) ;
		break;
		case FallingMode:
		//INT0 In Falling Edge Sense Mode From Micro-controller Control and Status Register [ICS2 ->0]
		MCUCSR &= ~(1<<ISC2);
		break;
	}
	//Enable INT2 from General Interrupt Control Register
	GICR |= (1<<INT2);
}
