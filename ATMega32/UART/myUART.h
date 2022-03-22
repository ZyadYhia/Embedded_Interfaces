/*
 * myUART.h
 *
 * Created: 3/20/2022 11:56:07 PM
 *  Author: User
 */ 


#ifndef MYUART_H_
#define MYUART_H_



void UART_init();
void UART_send(char);
void UART_send_str(char*);
void UART_send_num(int);

char UART_receive();

#endif /* MYUART_H_ */