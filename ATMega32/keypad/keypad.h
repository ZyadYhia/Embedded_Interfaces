/*
* keypad.h
*
* Created: 2/25/2022 3:32:03 AM
*  Author: User
*/


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define DDRx  DDRD
#define PORTx PORTD
#define PINx  PIND

void initKeypad();
int scanKeypad();
#endif /* KEYPAD_H_ */