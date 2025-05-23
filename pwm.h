/*
 * pwm.h
 *
 * Created: 2025-03-14 오후 12:45:22
 *  Author: microsoft
 */ 


#ifndef PWM_H_
#define PWM_H_

#define  F_CPU 16000000UL  // 16MHZ
#include <avr/io.h>
#include <util/delay.h>  // _delay_ms _delay_us
#include <avr/interrupt.h>
#include <stdio.h> // printf scanf fgets puts gets 등이 들어있다.

//main
extern volatile int msec_count;
extern volatile int check_1ms;
extern volatile int State;

//button
#include "button.h"

//pwm
void init_pwm(void);
void init_timer3(void);
void Run_stop(void);
void Run_normal(void);
void Run_speed(void);

//fnd
#include "fnd.h"

//buzzer
#include "speaker.h"

//uart
#include "uart.h"

void (*fp[]) () =
{
	Run_stop,
	Run_normal,
	Run_speed
};

#endif /* PWM_H_ */