
#include "uart.h"

ISR(USART1_RX_vect) //ST0P비트가 들어옴과 동시에 INTERRUPT
{
	volatile uint8_t rx_data;
	volatile static int i=0;
	
	//rx_data의 형은 안바꿔줘도됌 -> char로 가져와서 이차원배열에 저장하기 때문
	rx_data = UDR1; // uart0의 H/W register(UDR0)로 부터 1byte를 읽어 들인다.
					// rx_data = UDR0;를 실행하면 UDR0의 내용이 비워진다.(empty)
	if (rx_data == '\n')
	{
		Rx1_buffer[Rear++][i] = '\0';
		Rear % COMMAND_NUMBER; // rear : 0~9
		i=0;
		// rx_buffer queue full check 하는 logic 추가
	}
	else
	{
		Rx1_buffer[Rear][i++] = rx_data;
		// COMMAND_LENGTH를 check하는 logic 추가
	}
}

void init_uart1(void)
{
	// 1. 9600bps로 설정
	UBRR1H = 0x00; //상위 4비트
	UBRR1L = 207; // 9600bps P219 표 9-9 하위 8비트
	//UBRR0L = 16; // 115200bps P219 표 9-9 하위 8비트
	// 2. 2배속 통신 표9-1
	UCSR1A |= 1 << U2X0; // 2배속 통신
	UCSR1C |= 0x06; // 비동기/data=8bit/none parity
	// P215 표9-1
	// RXEN1 : UART1로부터 수신이 가능하도록
	// TXEN1 : UART1로부터 송신이 가능하도록
	// RXCIE1 : UART1로부터 1byte가 들어오면(STOP BIT가 들어 오면) rx interrupt를 발생 시킨다.
	UCSR1B |= 1 << RXEN1 | 1 << TXEN1 | 1 << RXCIE1;
}

// UART1로 1byte를 전송 하는 함수 (polling방식)
void UART1_transmit(uint8_t data)
{
	// 데이터 전송 중이면 전송이 끝날 때 까지 기다린다.
	while (!(UCSR1A & 1 <<UDRE1)); //1이 될때 while 종료
	UDR1 = data; // data를 H/W전송 register에 쏜다.
}

void bt_command_processing(void)
{
	if(Front != Rear) // rx_buffer에 데이터가 존재하면
	{
		char *ptr = Rx1_buffer[Front];
		while (*ptr) {
			if (*ptr == '\r') {
				*ptr = '\0';  // '\r'을 NULL로 변경하여 문자열 끝에 영향을 주지 않게 함
				break;
			}
			ptr++;
		}
		if(!strcmp(Rx1_buffer[Front],"남은시간")) // 남은시간을 입력했을 경우
		{
			check_time=1; // pwm.c에서 처리
		}
		Front++;
		Front %= COMMAND_NUMBER;
	}
}