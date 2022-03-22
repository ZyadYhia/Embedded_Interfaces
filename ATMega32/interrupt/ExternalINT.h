/*
 * ExternalINT.h
 *
 * Created: 3/4/2022 1:25:46 AM
 *  Author: User
 */ 


#ifndef EXTERNALINT_H_
#define EXTERNALINT_H_

#define RisingMode 0
#define FallingMode 1
#define LowLevelMode 2
#define AnyLogicalChangeMode 3

void INT0_Init(int);
void INT1_Init(int);
void INT2_Init(int);




#endif /* EXTERNALINT_H_ */