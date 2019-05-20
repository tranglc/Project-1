#include"pwm.h"

unsigned char PWM_duty_cycle=50;
volatile unsigned char cycleTime=0;
bit PWM_Enabled=0;
void PWM_Init(){
	TL0=0x00;
	TH0=0xDF;
	ET0=1;
}

void PWM_SetDutyCycle(unsigned char duty_cycle){
	if(duty_cycle>100)
		duty_cycle=100;
	PWM_duty_cycle=duty_cycle;
}

void PWM_Start(){
	PWM_Enabled=1;
	TR0=1;
}

void PWM_Stop(){
	PWM_Enabled=0;
	TR0|=PWM_Enabled;
}

void PWM_Trigger() interrupt 1{
	TF0=0;
	if(cycleTime>=100){
		cycleTime=0;
	}else{
		cycleTime++;
	}
	if(PWM_Enabled==1){
		if(cycleTime==PWM_duty_cycle){
			PWM_PIN=0;
		}else if(cycleTime==0){
			PWM_PIN=1;
		}
	}
}
	