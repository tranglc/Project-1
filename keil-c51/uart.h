#ifndef _UART_H
#define _UART_H

#include"AT89X52.h"

void UART_Init(unsigned char TH);
void UART_TxChar(char ch);
//char UART_RxChar();
void UART_TxString(char *str);
#endif