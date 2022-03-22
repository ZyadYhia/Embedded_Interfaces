/*
 * myTimers.h
 *
 * Created: 3/10/2022 3:45:19 AM
 *  Author: User
 */ 


#ifndef MYTIMERS_H_
#define MYTIMERS_H_


// Timer Source CLK
#define TimerOff	  0
#define Internal_No   1
#define Internal_8    2
#define Internal_64   3
#define Internal_256  4
#define Internal_1024 5
#define External_Falling 6
#define External_Rising  7

// Timer Mode
#define Normal 0x00
#define PWM	   0x40
#define CTC	   0x08
#define FPWM   0x48

//Compare OC0
#define OC0_OFF			0
#define OC0_CTC_TOGGLE  1
#define OC0_CTC_CLEAR   2
#define OC0_CTC_SET		3

//Compare OC0
#define OC0_FPWM_CLEARonCompare   2
#define OC0_FPWM_SETonCompare     3

//Compare OC0
#define OC0_PWM_CLEARonCompare   2
#define OC0_PWM_SETonCompare	 3

#define TOV_INTERRUPT 0
#define TOC_INTERRUPT 1
#define TIMER_INT_OFF 3

void Timer0_CLKSource(int Clk);
void Timer0_Mode(int Mode);
void Timer0_OC0(int Mode);
void Timer0_INIT(int TimerMode, int Clk, int OC0_state, int dutyCycle);
void Timer0_Interrupt(int Timer_Interrupt);
void Timer0_SET_COMP(int value );
void Timer0_OC0_setDutyCycle(int);


#endif /* MYTIMERS_H_ */