#ifndef _PWM_H
#define _PWM_H

#include "AT89X52.h"

sbit PWM_PIN=P1^2;

void PWM_Init();
void PWM_SetDutyCycle(unsigned char duty_cycle);
void PWM_Start();
void PWM_Stop();


#endif