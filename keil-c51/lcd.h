#ifndef _LCD_H
#define _LCD_H

#include<AT89X52.h>

sbit RS=P2^2;
sbit EN=P2^3;
sbit BUSY=P2^7;

#define CMD_LCD_4BIT_MODE 0x28
#define CMD_LCD_DISPLAY_ON_CURSOR_OFF 0x0C
#define CMD_LCD_CLEAR 0x01
void LCD_Init() reentrant;
static void LCD_Ready() reentrant; 
void LCD_DisplayChar(char ch) reentrant;
void LCD_DisplayString(char *str) reentrant;
void LCD_CMDWrite(unsigned char cmd) reentrant;
#endif