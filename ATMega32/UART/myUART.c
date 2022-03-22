/*
 * myUART.c
 *
 * Created: 3/20/2022 11:55:55 PM
 *  Author: User
 */ 
#include <avr/io.h>
#include <stdlib.h>
#include "myUART.h"

void UART_init(){
	UCSRB |= (1<<TXEN) | (1<<RXEN);
	UBRRL = 103;
}

void UART_send(char data){
	//pooling
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}

void UART_send_str(char* str){
	for (int i=0; str[i]!= '\0'; i++)
	{
		UART_send(str[i]);
	}
}

void UART_send_num(int num){
	char str[10];
	itoa(num, str, 10);
	UART_send_str(str);
}

char UART_receive(){
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}
