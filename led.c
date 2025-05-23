/*
 * led.c
 *
 * Created: 2025-03-14 오후 12:24:31
 *  Author: microsoft
 */ 
#include "led.h"


void washing_normal_led(int sec_count)
{
	DDRA=0x0f; // LED 0 1 2 3을 출력모드로
	PORTA = 0x00;
	if(sec_count <= 60) PORTA |= 1 << 0;
	if(sec_count <= 30) PORTA |= 1 << 1;
	if(sec_count <= 15) PORTA |= 1 << 2;
	if(sec_count <= 0) PORTA |= 1 << 3;
}

void washing_speed_led(int sec_count)
{
	DDRA=0x0f; // LED 0 1 2 3을 출력모드로
	PORTA = 0x00;
	if(sec_count <= 30) PORTA |= 1 << 0;
	if(sec_count <= 15) PORTA |= 1 << 1;
	if(sec_count <= 5) PORTA |= 1 << 2;
	if(sec_count <= 0) PORTA |= 1 << 3;
}