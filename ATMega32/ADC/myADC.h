/*
 * myADC.h
 *
 * Created: 3/9/2022 3:59:00 AM
 *  Author: User
 */ 


#ifndef MYADC_H_
#define MYADC_H_

#define AVCC_MODE 1
#define AREF_MODE 0
#define INTERNAL  3

#define PRE_2   1
#define PRE_4   2
#define PRE_8   3
#define PRE_16  4
#define PRE_32  5
#define PRE_64  6
#define PRE_128 7

#define CH0 0
#define CH1 1
#define CH2 2
#define CH3 3
#define CH4 4
#define CH5 5
#define CH6 6
#define CH7 7

void ADC_CH(int channelNo);
void ADC_REF(int Ref);
void ADC_FREQ(int Prescaler);
void ADC_INIT(int channelNo, int Ref, int Prescaler);
void ADC_StartConv(void);
int  ADC_Read(void);
void waitConversion(void);



#endif /* MYADC_H_ */