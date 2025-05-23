/*
 * fnd.h
 *
 * Created: 2025-03-14 오후 2:09:39
 *  Author: microsoft
 */ 


#ifndef FND_H_
#define FND_H_

#define  F_CPU 16000000UL  // 16MHZ
#include <avr/io.h>
#include <util/delay.h>  // _delay_ms _delay_us

#define FND_DATA_PORT  PORTC
#define FND_DATA_DDR   DDRC

#define FND_DIGIT_PORT PORTB //FND1 자릿수 선택
#define FND_DIGIT_DDR  DDRB
#define FND_DIGIT_D1  3
#define FND_DIGIT_D2  2
#define FND_DIGIT_D3  1
#define FND_DIGIT_D4  0

#define FND_DIGIT_PORT2 PORTG //PFG --> 분초 /오른쪽에서 2번째
#define FND_DIGIT_DDR2  DDRG

void fnd_mode_sonic_select(int mode);
void init_fnd(void);
void fnd_restime_circle(int sec_count, int msec_count);
void fnd_display_stop(void);


//ultrasonic.h
extern volatile int dis_cm;


#endif /* FND_H_ */