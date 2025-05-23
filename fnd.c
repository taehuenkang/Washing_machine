
#include "fnd.h"



void fnd_mode_select(int mode)
{
	//  0     1      2
	uint8_t fnd_mod_font[] = {~0xc0, ~0xf9, ~0xa4};
	
	uint8_t fnd_round0[] = {~0x86,~0x8e}; //e   f
	uint8_t fnd_round1[] = {~0xaa,~0xe1}; //m   u
	uint8_t fnd_round2[] = {~0x87,~0xc7}; //t   l
	uint8_t fnd_round3[] = {~0x8d,~0xc7}; //y   l		
	
	FND_DIGIT_PORT=0xff; //PORT B SETUP
	FND_DIGIT_PORT2 |= 1 << 0; //PORT G SETUP
	
	static int digit_select=0;  // static를 쓰면 전역 변수 처럼 함수가 빠져 나갔다가 다시 들어 오더라도 값을 유지
	
	switch(digit_select)
	{
		
		case 0:
		FND_DIGIT_PORT = ~0x80;   // PORTB 7번
		if(mode==1)
		FND_DATA_PORT = fnd_mod_font[1];   // 0~9초
		else FND_DATA_PORT = fnd_mod_font[2];
		break;
		case 1:
		FND_DIGIT_PORT = ~0x40;    // PORTB 6번
		FND_DATA_PORT = fnd_mod_font[0];   // 10단위초
		break;
		case 2:
		FND_DIGIT_PORT2 =  ~0x01;   // PORTG 0번
		FND_DATA_PORT = fnd_mod_font[0];   // 1단위 분
		break;
		case 3:
		FND_DIGIT_PORT = ~0x10;   // PORTB 4번
		FND_DATA_PORT = fnd_mod_font[0];   // 10단위 분
		break;
		
		
		case 4:
		FND_DIGIT_PORT = ~0x08; //portb 3번
		if(dis_cm>=10)
		{
			FND_DATA_PORT = fnd_round3[1];//full
		}
		else
		{
			FND_DATA_PORT = fnd_round3[0];
		}
		break;
		case 5:
		FND_DIGIT_PORT = ~0x04;   // PORTB 2번
		if(dis_cm>=10)
		{
			FND_DATA_PORT = fnd_round2[1];//full
		}
		else
		{
			FND_DATA_PORT = fnd_round2[0];
		}
		break;
		case 6:
		FND_DIGIT_PORT = ~0x02; // portb 1번
		if(dis_cm>=10)
		{
			FND_DATA_PORT = fnd_round1[1];//full
		}
		else
		{
			FND_DATA_PORT = fnd_round1[0];
		}
		break;
		case 7:
		FND_DIGIT_PORT = ~0x01; // portb 0번	
		if(dis_cm>=10)
		{
			FND_DATA_PORT = fnd_round0[1];//full
		}
		else
		{
			FND_DATA_PORT = fnd_round0[0];
		}
		break;
		
	}
	digit_select++;
	digit_select %= 8;   // 다음 표시할 자리수 선택
	
}

void init_fnd(void)
{
	FND_DATA_DDR = 0xff;  // PORTC 출력 모드로 설정 

	// FND_DIGIT_DDR |= 0xff;   // DDRB 자릿수 선택 3210
	FND_DIGIT_DDR |= 0xff;
	
	// DDRF 자릿수 선택 0
	FND_DIGIT_DDR2 |= 0x01;

	// fnd를 all off
	FND_DATA_PORT = 0x00;   // fnd를 all off
}

void fnd_restime_circle(int sec_count,int msec_count) {
	// print sec,msec 		 0     1      2    3     4     5     6     7     8     9     .
	//uint8_t fnd_font[] = { ~0xc0,~0xf9,~0xa4,~0xb0,~0x99,~0x92,~0x82,~0xd8,~0x80,~0x90,~0x7f};
	// print sec,msec 	      0     9     8      7    6     5     4     3     2     1    .
	uint8_t fnd_font[] = { ~0xc0,~0x90,~0x80,~0xd8,~0x82,~0x92,~0x99,~0xb0,~0xa4,~0xf9,~0x7f};
	// print round
	uint8_t fnd_round0[] = {~0xff, ~0xff, ~0xff, ~0xff, ~0xff, ~0xff, ~0xff, ~0xf7, ~0xe7, ~0xc7, ~0xc6, ~0xc6, ~0xc6};
	uint8_t fnd_round1[] = {~0xff, ~0xff, ~0xff, ~0xff, ~0xff, ~0xff, ~0xf7, ~0xf7, ~0xf7, ~0xf7, ~0xf7, ~0xf6, ~0xf6};
	uint8_t fnd_round2[] = {~0xff, ~0xff, ~0xff, ~0xff, ~0xff, ~0xf7, ~0xf7, ~0xf7, ~0xf7, ~0xf7, ~0xf7, ~0xf7, ~0xf6};
	uint8_t fnd_round3[] = {~0xff, ~0xfe, ~0xfc, ~0xf8, ~0xf0, ~0xf0, ~0xf0, ~0xf0, ~0xf0, ~0xf0, ~0xf0, ~0xf0, ~0xf0};

	FND_DIGIT_PORT = 0xff;
	FND_DIGIT_PORT2 |= 1 << 0;
	static int digit_select = 0;  // static 변수를 사용하여 상태 유지

	int Sec_count = 60 - sec_count;
	switch(digit_select) {
		case 0:
		FND_DIGIT_PORT = ~0x80;   // PORTB 7번
		FND_DATA_PORT = fnd_font[msec_count/10%10];   // 초 (1자리)
		break;
		case 1:
		FND_DIGIT_PORT = ~0x40;    // PORTB 6번
		FND_DATA_PORT = fnd_font[msec_count/100];   // 초 (10단위)
		break;
		case 2:
		FND_DIGIT_PORT2 = ~0x01;   // PORTG 0번
		FND_DATA_PORT = fnd_font[Sec_count % 10];   // 1초 단위
		break;
		case 3:
		FND_DIGIT_PORT = ~0x10;   // PORTB 4번
		FND_DATA_PORT = fnd_font[10-(sec_count / 10 % 10)];   // 10초 단위
		break;
		case 4:
		PORTB = ~0x08;   // PORTB 3번
		FND_DATA_PORT = fnd_round3[Sec_count % 13]; // 큰 원 (속도에 따라)
		break;
		case 5:
		FND_DIGIT_PORT = ~0x04;   // PORTB 2번
		FND_DATA_PORT = fnd_round2[ Sec_count % 13]; // 큰 원 (속도에 따라)
		break;
		case 6:
		FND_DIGIT_PORT = ~0x02;   // PORTB 1번
		FND_DATA_PORT = fnd_round1[ Sec_count % 13]; // 큰 원 (속도에 따라)
		break;
		case 7:
		FND_DIGIT_PORT = ~0x01;   // PORTB 0번
		FND_DATA_PORT = fnd_round0[ Sec_count % 13]; // 큰 원 (속도에 따라)
		break;
	}
	digit_select++;
	digit_select %= 8;  // 0부터 7까지 반복
}

void fnd_display_stop() {
	// print stop
	uint8_t fnd_round0[] = {~0x92};
	uint8_t fnd_round1[] = {~0x87};
	uint8_t fnd_round2[] = {~0xc0};
	uint8_t fnd_round3[] = {~0x8c};

	FND_DIGIT_PORT = 0xff;
	FND_DIGIT_PORT2 |= 1 << 0;
	static int digit_select = 0;  // static 변수를 사용하여 상태 유지
	
	switch(digit_select) {
		case 0:
		FND_DIGIT_PORT = ~0x10;   // PORTB 4번
		FND_DATA_PORT = fnd_round0[0];   // S
		break;
		case 1:
		FND_DIGIT_PORT2 = ~0x01;   // PORTG 0번
		FND_DATA_PORT = fnd_round1[0];   // t
		break;
		case 2:
		FND_DIGIT_PORT = ~0x40;    // PORTB 6번
		FND_DATA_PORT = fnd_round2[0];   // O
		break;
		case 3:
		FND_DIGIT_PORT = ~0x80;   // PORTB 7번
		FND_DATA_PORT = fnd_round3[0]; // P
		break;
	}
	digit_select++;
	digit_select %= 8;  // 0부터 7까지 반복
}

	
