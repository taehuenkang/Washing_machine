/*
 * pwm.c
 *
 * Created: 2025-03-14 오후 12:45:33
 *  Author: microsoft
 */ 

#include "pwm.h"


void init_timer3(void)
{
	DDRE |= 1 << 3 | 1 << 5; // PE3,5 출력으로 설정 (현재 4번핀은 초음파 ECHO)
	// 16 timer 3번의 모드 5: 8비트 고속 PWM (P348 표15-6)
	TCCR3A |= 1 << WGM30;
	TCCR3B |= 1 << WGM32;
	// 비반전 모드
	// 사용자가 설정한 PWM값이 일치시 OC3C의 출력핀이 LOW로 바뀌고 BOTTOM에서 HIGH로 바뀐다.
	// P350 표 15-7 (비반전 모드 설정)
	TCCR3A |= 1 << COM3C1;
	// 분주비 : 64 , 16000000 / 64 --> 2500000Hz(250KHz)
	// T=1/f = 1/25000000Hz ==> 0.000004sec(4us)
	// 25000000Hz에서 256개의 펄스를 count하면 소요시간 1.02ms
	//				  127개의 펄스를 count하면 소요시간 0.5ms
	// P318 표 14-1 , TIMER3을 제어하기 때문에 CS30,CS31을 1로 만들어준다. TIMER1은 CS10,CS11
	TCCR3B |= 1 << CS31 | 1 << CS30; // 분주비 : 64
	OCR3C = 0; // OCR(Output Compare Register) : PWM값
}
// PF6 : IN1 (L298N)
// PF7 : IN2 (L298N)
// PF6(IN1)  PF7(IN2)
//    0          0    --> 역회전
//    1          0    --> 정회전
//    1          1    --> STOP

void init_pwm(void)
{
	DDRF |= 1 << 6 | 1 << 7; // 출력 모드로 설정
	PORTF &= ~(1 << 6 | 1 << 7); //RESET
	PORTF |= 1 << 6; // 정회전
	
}

void Run_normal(void) //LED제어랑 FND제어 넣어주면 됌
{
	init_timer3();
	int sec_count=60;
	uint8_t forward=1; // forward <--> backward
	
	while(sec_count >= 0) //60초가 돌아간다. -->일반모드이기 때문
	{
		if (msec_count >= 1000)   // 1초 세주고
		{
			msec_count=0;
			sec_count--;
		}
		OCR3C = 125;
		_delay_ms(1);
		fnd_restime_circle(sec_count,msec_count);
		washing_normal_led(sec_count);
		bt_command_processing();
		
		if(check_time)
		{
			printf("남은 시간 : %d초 \n",sec_count);
			check_time=0;
		}
		
		if(get_button(BUTTON0,BUTTON0PIN)) // BTN0가 우선순위 1순위
		{
			break;
		}
		else if(get_button(BUTTON2,BUTTON2PIN)) // 돌고 있을 때 BTN2를 누르면 버튼을 다시 누를 때 까지 정지
		{
			Button(); // 애는 모드 선택음과 같아서 조금 바꿔줘야할듯 ( 일시정지 버튼을 눌렀을 때 음 )
			while(!get_button(BUTTON2,BUTTON2PIN))
			{
				fnd_display_stop();
				OCR3C = 0;
			}
			Button(); // 애는 모드 선택음과 같아서 조금 바꿔줘야할듯 ( 일시정지 해제 시 음 ) 위에 일시정지음이랑 같아도 상관x
		}
		if (sec_count % 10 == 0) //10초 주기로 방향 전환
		{
			forward = !forward;
			PORTF &= ~(1 << 6 | 1 << 7); // IN1 IN2 RESET
			if(forward)
			{
				PORTF |= 1 << 6;
			}
			else
			{
				PORTF |= 1 << 7;
			}
		}
		
	}
	OCR3C = 0;
}

void Run_speed(void) //LED제어랑 FND제어 넣어주면 됌
{
	init_timer3();
	int sec_count=30;
	uint8_t forward=1; // forward <--> backward
	
	while(sec_count >= 0) //30초가 돌아간다. -->일반모드이기 때문
	{
		if (msec_count >= 1000)   // 1초 세주고
		{
			msec_count=0;
			sec_count--;
		}
		OCR3C = 250;
		_delay_ms(1);
		fnd_restime_circle(sec_count,msec_count);
		washing_speed_led(sec_count);
		bt_command_processing();
		
		if(check_time)
		{
			printf("남은 시간 : %d초 \n",sec_count);
			check_time=0;
		}
		
		if(get_button(BUTTON0,BUTTON0PIN)) // BTN0가 우선순위 1순위
		{
			break;
		}
		else if(get_button(BUTTON2,BUTTON2PIN)) // 돌고 있을 때 BTN2를 누르면 버튼을 다시 누를 때 까지 정지
		{
			Button(); // 애는 모드 선택음과 같아서 조금 바꿔줘야할듯 ( 일시정지 버튼을 눌렀을 때 음 )
			while(!get_button(BUTTON2,BUTTON2PIN))
			{
				fnd_display_stop();
				OCR3C = 0;
			}
			Button(); // 애는 모드 선택음과 같아서 조금 바꿔줘야할듯 ( 일시정지 해제 시 음 ) 위에 일시정지음이랑 같아도 상관x
		}
		if (sec_count % 5 == 0) // 5초 주기로 방향 전환
		{
			forward = !forward;
			PORTF &= ~(1 << 6 | 1 << 7); // IN1 IN2 RESET
			if(forward)
			{
				PORTF |= 1 << 6;
			}
			else
			{
				PORTF |= 1 << 7;
			}
		}
		
	}
	OCR3C=0;
}

void Run_stop(void)
{
	
}