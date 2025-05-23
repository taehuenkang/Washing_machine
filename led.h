/*
 * led.h
 *
 * Created: 2025-03-14 오후 12:24:23
 *  Author: microsoft
 */ 


#ifndef LED_H_
#define LED_H_

#define  F_CPU 16000000UL  // 16MHZ
#include <avr/io.h>
#include <util/delay.h>  // _delay_ms _delay_us

void washing_normal_led(int sec_count);
void washing_speed_led(int sec_count);

#endif /* LED_H_ */