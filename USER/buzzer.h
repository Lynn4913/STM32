#ifndef __BUZZER_H
#define __BUZZER_H
#include "stm32f10x.h"

void Buzzer_Init(void);
void Buzzer_SetFreq(uint16_t freq);
void Buzzer_Stop(void);

#endif
