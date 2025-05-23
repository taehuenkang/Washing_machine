/*
 * button.h
 *
 * Created: 2025-03-14 오후 12:07:43
 *  Author: microsoft
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#define  F_CPU 16000000UL  // 16MHZ
#include <avr/io.h>  // PORTA PORTB등의 I/O 관련 register등이 있다.
#include <util/delay.h>  // _delay_ms _delay_us

#define BUTTON_DDR DDRD //PORTBD
#define BUTTON_PIN PIND //PIND

#define BUTTON0PIN 4 // PD4
#define BUTTON1PIN 5 // PD5
#define BUTTON2PIN 6 // PD6

#define BUTTON0   0   // PORTD.4의 가상의 index(S/W 번호)
#define BUTTON1   1   // PORTD.5의 가상의 index(S/W 번호)
#define BUTTON2   2   // PORTD.6의 가상의 index(S/W 번호)

#define BUTTON_PRESS  1   // 버튼을 누르면 high(active-high)
#define BUTTON_RELEASE 0  // 버튼을 떼면 low

#define BUTTON_NUMER 3   // button갯수 

//main
extern volatile int State;

//button
void init_button(void);
void state_check(void);
int get_button(int button_num, int button_pin);

//buzzer
#include "speaker.h"

#endif /* BUTTON_H_ */