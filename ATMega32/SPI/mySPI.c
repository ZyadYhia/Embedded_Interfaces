/*
 * mySPI.c
 *
 * Created: 3/21/2022 10:57:58 PM
 *  Author: User
 */ 
#include <avr/io.h>
#include <stdlib.h>
#include "mySPI.h"


void SPI_init(int Mode){
	//SPI Control Register
	if (Mode == SPI_MASTER)
	{
		DDRB |= (1<<SS)|(1<<MOSI)|(1<<SCK);
		SPCR |= (1<<MSTR);
	} 
	else
	{
		DDRB |= (1<<MISO);
	}
	SPCR |= ((1<<SPE)|(1<<SPR1)|(1<<SPR0));
}

void SPI_MASTER_send(char data){
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

char SPI_SLAVE_receive(){
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

void SPI_MASTER_send_str(char *data){
	for (int i=0; data[i]!='\0'; i++)
	{
		SPI_MASTER_send(data[i]);
	}
}

void SPI_MASTER_send_num(int num){
	char str[10];
	itoa(num, str, 10);
	SPI_MASTER_send_str(str);
}
