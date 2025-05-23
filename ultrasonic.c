#include "ultrasonic.h"



ISR(INT4_vect)
{
	if(ECHO_PIN & 1<< ECHO) //상승 엣지
	{
		TCNT1=0;
	}
	else
	{
		//ECHO핀에 들어온 pulse 갯수를 msec로 환산
		ultrasonic_dis = 1000000.0 * TCNT1 * 1024 / F_CPU;
		//	TCINT에 10 이 들어 있다고 가정 시
		// 15.625KHz 의 1주기 64us
		// 64us * 10 ==> 640 us
		// 640 us / 58 us ==>11cm
		// ---- 1cm : 58us
		dis_cm=(ultrasonic_dis / 58);
		//sprint는 scm에 dis를 보내주고 나중에도 쓸수 있게 해준다.
		if(dis_cm>=0)
		{
		//sprintf(scm, "dis: %d cm\n", dis_cm);
	
		}
	}
}


void init_ultrasonic(void)
{
	TRIG_DDR |= 1 << TRIG;	//출력 모드 설정
	ECHO_DDR &= ~(1 << ECHO);	//입력 모드 설정
	
	//	p289 표12-6 ==> 0 1 : (rising edge and falling edge)둘 다 INT를 띄우도록 요청
	EICRB |= 0 << ISC41 | 1 << ISC40;
	//	16bit timer1번을 설정을 해서 사용 65535(max) : 0xffff
	//	16MHZ를 1024로 분주 T=0.064msec=64us -->p318 표14-1
	
	
	// 중복 되므로 없애줌
	//TCCR1B |= 1 << CS12 | 1<< CS10;	//1024로 분주
	// =================인터럽트를 작성안했음===============
	
	
	EIMSK |= 1 << INT4;	// p287 그림12-6 ==> external int 4(ECHO핀)
	
}

void trigger_ultrasonic() 
{
	//   0-------->1-------->0으로 설정
	
	TRIG_PORT &= ~(1 << TRIG);  //	TRIG 시작 전에 무조건 low로 시작해야함
	_delay_us(1);
	TRIG_PORT |= (1 << TRIG);   //	TRIG 핀 HIGH
	_delay_us(15);              //	규격은 10us이지만 여유를 둬서 15us 동안 유지
	TRIG_PORT &= ~(1 << TRIG);  //	다시 LOW로 설정
}

void distance_ultrasonic()
{
	if(ultrasonic_check_timer >= 1000) //	1초
	{
		ultrasonic_check_timer = 0;
		printf("%s", scm);
		trigger_ultrasonic();
	}
}


