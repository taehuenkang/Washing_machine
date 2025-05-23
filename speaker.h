/*
 * speaker.h
 *
 * Created: 2025-03-14 오후 8:06:09
 *  Author: microsoft
 */ 


#ifndef SPEAKER_H_
#define SPEAKER_H_\

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "speaker.h"
#include "fnd.h"

#define DO_01   1911
#define DO_01_H 1817
#define RE_01   1703
#define RE_01_H 1607
#define MI_01   1517
#define FA_01   1432
#define FA_01_H 1352
#define SO_01   1276
#define SO_01_H 1199
#define LA_01   1136
#define LA_01_H 1073
#define TI_01   1012
#define DO_02   956
#define DO_02_H 909
#define RE_02   851
#define RE_02_H 804
#define MI_02   758
#define FA_02   716
#define FA_02_H 676
#define SO_02   638
#define SO_02_H 602
#define LA_02   568
#define LA_02_H 536
#define TI_02   506
#define DO_03   478
#define DO_03_H 450
#define RE_03	425
#define RE_03_H 401
#define MI_03	378
#define FA_03   358
#define SO_03	319
#define LA_03	284
#define TI_03	253
#define DO_04	239
#define RE_04	212
#define MI_04	189
#define FA_04	179
#define SO_04   159

#define F_CLK       16000000L //클럭
#define F_SCALER	8 //프리스케일러
#define BEAT_1_32	42
#define BEAT_1_16	86
#define BEAT_1_8	250
#define BEAT_1_4	150
#define BEAT_1_3	325
#define BEAT_1_2	400
#define BEAT_1		136



void Music_Player(int *tone, int *Beats);
void init_speaker(void);
void powerOnTone(void);
void Button(void);
void start_device(void);
void delay_ms(int ms);

const int Elise_Tune[];
const int Elise_Beats[];
const int Stage_Clear_Tune[];
const int Stage_Clear_Beats[];

#endif /* SPEAKER_H_ */