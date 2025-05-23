/*
 * button.c
 *
 * Created: 2025-03-14 오후 12:09:43
 *  Author: microsoft
 */ 
#include "button.h"




void init_button(void) //BUTTON 초기화
{
	BUTTON_DDR &= ~( 1 << BUTTON0PIN | 1 << BUTTON1PIN | 1 << BUTTON2PIN );
}

int get_button(int button_num, int button_pin)
{
	static unsigned char button_status[BUTTON_NUMER] =
	{BUTTON_RELEASE,BUTTON_RELEASE,BUTTON_RELEASE,BUTTON_RELEASE};
	// 	지역 변수에 static을 쓰면 전역 변수처럼 함수를 빠져 나갔다 다시 들어 와도 값을 유지 한다.
	int currtn_state;
	
	currtn_state = BUTTON_PIN & (1 << button_pin);   // 버튼을 읽는다.
	if (currtn_state && button_status[button_num] == BUTTON_RELEASE)  // 버튼이 처음 눌려진 noise high
	{
		_delay_ms(60);   // noise가 지나가기를 기다린다.
		button_status[button_num] = BUTTON_PRESS;   // noise가 지나간 상태의 High 상태
		return 0;   // 아직은 완전히 눌렸다 떼어진 상태가 아니다.
	}
	else if (currtn_state==BUTTON_RELEASE && button_status[button_num] == BUTTON_PRESS)
	{
		_delay_ms(60);
		button_status[button_num] = BUTTON_RELEASE;   // 다음 버튼 체크를 위해서 초기화
		return 1;   // 완전히 1번 눌렸다 떼어진 상태로 인정
	}
	
	return 0;   // 버튼이 open상태
}

void state_check(void)
{
	if(get_button(BUTTON0, BUTTON0PIN))
	{
		State=0;
	}
	if(State == 0 && get_button(BUTTON0, BUTTON0PIN))
	{
		powerOnTone();
		State = 1;
	}
	if(State == 1 && get_button(BUTTON2, BUTTON2PIN))
	{
		start_device();
		State = 2;
	}
}

