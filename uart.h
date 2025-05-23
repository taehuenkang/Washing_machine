/*
 * uart.h
 *
 * Created: 2025-03-15 오후 1:28:37
 *  Author: microsoft
 */ 


#ifndef UART_H_
#define UART_H_

#define  F_CPU 16000000UL  // 16MHZ
#include <avr/io.h>
#include <util/delay.h>  // _delay_ms _delay_us
#include <avr/interrupt.h>
#include "df.h"


#include <avr/io.h>
#include <string.h>
#include <stdio.h>
#include "uart.h"

void init_uart1(void);
void UART1_transmit(uint8_t data);
void bt_command_processing(void);

volatile uint8_t Rx1_msg_received=0;
volatile int Rear = 0; // input index : USART0_RX_vect에서 집어 넣어 주는 index
volatile int Front = 0; // output index
volatile int check_time = 0; // 남은 시간 check하는 변수
// led_all_on\n
// led_all_off\n
// uart0로 부터 들어온 문자를 저장하는 버퍼(변수)
volatile uint8_t Rx1_buffer[COMMAND_NUMBER][COMMAND_LENGTH]; //인터럽트 관련된 변수는 volatile
volatile int check_time;


#endif /* UART_H_ */