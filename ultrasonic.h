


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define  F_CPU 16000000UL  // 16MHZ
#include <avr/io.h>
#include <util/delay.h>  // _delay_ms _delay_us
#include <avr/interrupt.h>	//interrupt 헤어파일

//	상승엣지에서 INT한번 하강엣지에서 INT한번->H/W
#define ECHO 4
#define ECHO_PIN PINE	//external INT4
#define ECHO_DDR DDRE

//	tirgger pin은 portG의 4번
#define TRIG 4
#define  TRIG_PORT PORTG
#define  TRIG_DDR DDRG

void init_ultrasonic();
void trigger_ultrasonic();
void distance_ultrasonic();


extern volatile int ultrasonic_check_timer;
volatile int ultrasonic_dis=0;
volatile int dis_cm=0;
volatile char scm[50];

#endif