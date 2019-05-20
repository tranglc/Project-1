#include"uart.h"
#include"delay.h"
void UART_Init(unsigned char TH){
	TMOD=0x22; // timer 1 in mode 2 (8-bit auto-reload) to set baud rate
	TH1=TH;
	SCON=0x50;
	TR1=1;
}
void UART_TxChar(char ch){
	SBUF=ch;
	while(TI==0);
	TI=0;
}
//char UART_RxChar(){
//	char dat;
//	while(RI==0);
//	RI=0;
//	dat=SBUF;
//	return dat;
//}
void UART_TxString(char* str){
	while(*str){
		ms_Delay(1);
		UART_TxChar(*str++);
	}
}
	