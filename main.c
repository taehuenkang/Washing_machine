
#define  F_CPU 16000000UL  // 16MHZ
#include <avr/io.h>  // PORTA PORTB등의 I/O 관련 register등이 있다.
#include <util/delay.h>  // _delay_ms _delay_us
#include <stdio.h>


#include "df.h"

//전역 변수
volatile int msec_count=0;
volatile int check_1ms=0;
volatile int State=0;
volatile int ultrasonic_check_timer=0;

ISR(TIMER0_OVF_vect)
{
	// 6~256 : 250(1ms) 그래서 TCNT0를 6으로 설정하는것이다.
	TCNT0 = 6;
	msec_count++; // 1ms마다 1씩 증가
	check_1ms++;
	ultrasonic_check_timer++;
}


FILE OUTPUT1 = FDEV_SETUP_STREAM(UART1_transmit,NULL,_FDEV_SETUP_WRITE);


int main(void)
{
	init_anything();
	stdout = &OUTPUT1; 
	sei(); 
	
	DDRA = 0xff;
	PORTA = 0x00;
	
	int mode=1; // 일반, 고속
	
	while(1)
	{
		state_check();
		if(State == 1) //모드 선택
		{
			if(mode == 1 && get_button(BUTTON1,BUTTON1PIN))
			{	
				Button(); //
				mode = 2;
			} 
			if(mode == 2 && get_button(BUTTON1,BUTTON1PIN))
			{
				Button();	
				mode = 1;
			}
			fnd_mode_sonic_select(mode);
			distance_ultrasonic();			
		}
		
		if(State == 2)
		{
			fp[mode] ();
			State = 0;
			Music_Player(Stage_Clear_Tune,Stage_Clear_Beats);
		}
	}
	
	
}

void init_timer0(void)
{
	// 16MHZ / 64분주(DOWN) 분주 : Divider/PreScale
	// 분주비 계산
	// (1) 16000000HZ / 64 = 250.000HZ
	// (2) T(주기) 1clock의 소요시간 : 1/f = 1/250,000 ==> 0.000004sec(4us) : 0.004ms
	// (3) 8bit timer OV(Overflow : 0.004ms x 256 = 0.001024sec --> 1.024ms
	// 1ms마다 정확하게 INT를 띄우고 싶으면 0.004ms x 250개를 count = 0.001sec ==>1ms
	TCNT0=6; // TCNT : 0~256 1마다 TIMER0_OVF_VEC로 진입한다.
	// TCNT0 = 6으로 설정을 한 이유 : 6-->256 : 250개의 PULSE를 COUNT하기 때문에 정확히
	// 1ms가 된다.
	// (4) 분주비 설정 (25,000HZ --> 250KHZ) P296 표13-1
	TCCR0 |= 1<<CS02|0<<CS01|0<<CS00; // CS02 = 1 , CS01 = 0 , CS00 = 0 (64분주)
	// (5) TIMER0 Overflow INT를 허용(enable) P297 표13-5
	TIMSK |= 1<<TOIE0;
}

void init_anything(void)
{
	 init_button();
	 init_timer0(); //TIMER0 초기화 --> OVF INT (1ms 재는 인터럽트)
	 init_fnd();
	 init_pwm();
	 init_speaker();
	 init_uart1();
	 init_ultrasonic();
}