
#include "speaker.h"




int School_Bell_Tune[] = {SO_01, SO_01, LA_01, LA_01, SO_01, SO_01, MI_01, 
					 	  SO_01, SO_01, MI_01, MI_01, RE_01, 
					 	  SO_01, SO_01, LA_01, LA_01, SO_01, SO_01, MI_01, 
					 	  SO_01, MI_01, RE_01, MI_01, DO_01,'/0'};
const int School_Bell_Beats[] = {BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1_2,
						   BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1,
						   BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1_2, 
						   BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1};
						   
const int Elise_Tune[] = {MI_02, RE_02_H, MI_02, RE_02_H, MI_02, TI_01, RE_02, DO_02, LA_01, 0,
	DO_01, MI_01, LA_01, TI_01, 0, MI_01, SO_01_H, TI_01, DO_02, 0,
	MI_01, MI_02, RE_02_H, MI_02, RE_02_H, MI_02, TI_01, RE_02, DO_02, LA_01, 0,
	DO_01, MI_01, LA_01, TI_01, 0, MI_01, DO_02, TI_01, LA_01,
	MI_02, RE_02_H, MI_02, RE_02_H, MI_02, TI_01, RE_02, DO_02, LA_01, 0,
	DO_01, MI_01, LA_01, TI_01, 0, MI_01, SO_01_H, TI_01, DO_02, 0,
	MI_01, MI_02, RE_02_H, MI_02, RE_02_H, MI_02, TI_01, RE_02, DO_02, LA_01, 0,
	DO_01, MI_01, LA_01, TI_01, 0, MI_01, DO_02, TI_01, LA_01, 0,
	TI_01, DO_02, RE_02, MI_02, 0, SO_01, FA_02, MI_02, RE_02, 0, FA_01, MI_02, RE_02, DO_02, 0,
	MI_01, RE_02, DO_02, TI_01, 0, MI_01, MI_02, MI_03,
	RE_02_H, MI_02, RE_02_H, MI_02, RE_02, MI_02, RE_01_H, MI_02, TI_01, RE_01, DO_02, LA_01, 0,
	DO_01, MI_01, LA_01, TI_01, 0, MI_01, SO_01_H, TI_01, DO_02, 0,
	MI_01, MI_02, RE_02_H, MI_02, RE_02_H, MI_02, TI_01, RE_02, DO_02, LA_01, 0, DO_01, MI_01, LA_01, TI_01, 0,
RE_01, DO_02, TI_01, LA_01,'/0'};

const int Elise_Beats[] = 
   { BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_4,
	BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_4,
	BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_4,
	BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_2,
	BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_4,
	BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_4,
	BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_4,
	BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_2, BEAT_1_8,
	BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8,
	BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8,
	BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8,
	BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8,
	BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8,
BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8};

int GrandFa_Tune[] = {SO_01, DO_02, TI_01, DO_02, RE_02, DO_02, RE_02, MI_02, FA_02, MI_02, LA_01, RE_02, RE_02, DO_02, DO_02, DO_02, TI_01, LA_01, TI_01, DO_02, 0,
	SO_01, DO_02, TI_01, DO_02, RE_02, DO_02, RE_02, MI_02, FA_02, MI_02, LA_01, RE_02, RE_02, DO_02, DO_02, DO_02, TI_01, LA_01, TI_01, DO_02, 0,
	DO_02, MI_02, SO_02, MI_02, RE_02, DO_02, TI_01, DO_02, RE_02, DO_02, TI_01, LA_01, SO_01, DO_02, MI_02, SO_02, MI_02, RE_02, DO_02, TI_01, DO_02, RE_02,
SO_01, DO_02, RE_02, MI_02, FA_02, MI_02, LA_01, RE_02, RE_02, DO_02, DO_02, DO_02, TI_01, LA_01, TI_01, DO_02, '/0'};

const int GrandFa_Beats[] = {BEAT_1_4, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_2, BEAT_1_4,
	BEAT_1_4, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_2, BEAT_1_4,
	BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4,
BEAT_1_4, BEAT_1_2, BEAT_1_2, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_4, BEAT_1_8, BEAT_1_8, BEAT_1_2};


// Green Greens 멜로디 (긴 버전)
const int Stage_Clear_Tune[] = {
	FA_03,SO_03,LA_03,FA_03,SO_03,TI_03,
	DO_04,LA_03,SO_03,
	FA_03,SO_03,LA_03,FA_03,SO_03,TI_03,
	DO_04,SO_03,
	FA_03,SO_03,LA_03,FA_03,SO_03,TI_03,
	DO_04,LA_03,SO_03,
	SO_04,FA_04  ,MI_04,RE_04,MI_04,DO_04,'/0'
};

// 비트 배열 (각 음의 길이)
const int Stage_Clear_Beats[] = {
	BEAT_1_4, BEAT_1_4, BEAT_1_4, BEAT_1_4,BEAT_1_4, BEAT_1_4, 
	BEAT_1_8, BEAT_1_4,BEAT_1_2, 
	BEAT_1_4, BEAT_1_4, BEAT_1_4,BEAT_1_4, BEAT_1_4, BEAT_1_4, 
	BEAT_1_2,BEAT_1_2, 
	BEAT_1_4, BEAT_1_4, BEAT_1_4,
	BEAT_1_4, BEAT_1_4, BEAT_1_4, 
	BEAT_1_8,BEAT_1_4, BEAT_1_8, 
	BEAT_1_4, BEAT_1_3,BEAT_1_4, BEAT_1_3, BEAT_1_4, BEAT_1_4
};

void Music_Player(int *tone, int *Beats)
{
	while(*tone != '/0')
	{
		fnd_display_stop();
		PORTA |= 1 << 0x0f; // 멜로디 동안 led_all_on
		OCR1A = *tone;
		delay_ms(*Beats);
		tone++;
		Beats++;
		OCR1A = 0;
		_delay_ms(10);		
	}
	PORTA |= 1 << 0x00; // 노래가 끝나면 led_all_off
	return;
}  
// Timer3 위상교정 PWM
void init_speaker(void)
{
	DDRB |= 0x20;   // PWM CHANNEL  OC3A(PE3) 출력 모드로 설정 한다. 
	TCCR1A = (1<<COM1A0); // COM3A0 : 비교일치시 PE3 출력 반전 (P328 표14-6 참고)
	TCCR1B = (1<<WGM32) | (1<<CS31);   // WGM32 : CTC 4(P327 표14-5) CS31: 8분주(P318)
	// CTC mode : 비교일치가 되면 카운터는 reset되면서 PWM 파형 출력 핀의 출력이 반전 됨. 
	// 정상모드와 CTC모드의 차이점은 비교일치 발생시 TCNT1의 레지스터값을 0으로 설정 하는지 여부 이다. 
	// 정상모드를 사용시 TCNT1이 자동으로 0으로 설정 되지 않아 인터럽트 루틴에서 TCNT1을 0으로 설정 해 주었다. 
	// 위상교정 PWM mode4  CTC 분주비 8  16000000/8 ==> 2,000,000HZ(2000KHZ) : 
	// up-dounting: 비교일치시 LOW, down-counting시 HIGH출력
	// 1/2000000 ==> 0.0000005sec (0.5us)
	// P599 TOP 값 계산 참고
	// PWM주파수 = OSC(16M) / ( 2(up.down)x N(분주율)x(1+TOP) ) 
	// TOP =  (fOSC(16M) /  2(up.down)x N(분주율)x 원하는주파수 )) -1 
	//-----------------------------------------------------------
	// - BOTTOM :  카운터가 0x00/0x0000 일때를 가리킨다.
    // - MAX : 카운터가 0xFF/0xFFFF 일 때를 가리킨다.
    // - TOP?:  카운터가 가질 수 있는 최대값을 가리킨다. 오버플로우 인터럽트의 경우 TOP은 0xFF/0xFFFF
    //          이지만 비교일치 인터럽트의 경우 사용자가 설정한 값이 된다. 
    
	TCCR1C = 0;  // P328 그림 14-11 참고 
	OCR1A = 0;   // 비교 일치값을 OCR3A에 넣는다. 
	
	return;
}

void powerOnTone(void)
{
	OCR1A = 1911;  // 0.00025sec (250us) : 0.0000005 * 500
	_delay_ms(300);
	OCR1A = 1517;
	_delay_ms(300);
	OCR1A = 1276;
	_delay_ms(200);
	OCR1A = 1517;
	_delay_ms(200);
	OCR1A = 1276;
	_delay_ms(200);
	OCR1A =  956;
	_delay_ms(300);
	OCR1A = 0;
}

void start_device(void)
{
	OCR1A = 284;  // 0.00025sec (250us) : 0.0000005 * 500
	_delay_ms(50);
	OCR1A = 253;
	_delay_ms(50);
	OCR1A = 239;
	_delay_ms(50);
	OCR1A = 0;
}

void Button(void)
{
	OCR1A = 500;  // 0.00025sec (250us) : 0.0000005 * 500
	_delay_ms(50);
	OCR1A = 0;
} 


void delay_ms(int ms)
{
	while(ms-- != 0)_delay_ms(1);
}