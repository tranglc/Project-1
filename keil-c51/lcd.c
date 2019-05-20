#include"delay.h"
#include"lcd.h"


void LCD_CMDWrite(unsigned char cmd) reentrant {
	ms_Delay(1);
	P2=(cmd & 0xF0);
	RS=0;
	EN=1;
	us_Delay(10);
	EN=0;
	ms_Delay(1);
	P2=((cmd<<4) & 0xF0);
	RS=0;
	EN=1;
	us_Delay(10);
	EN=0;
}
void LCD_Init() reentrant {
	LCD_CMDWrite(CMD_LCD_4BIT_MODE);
	LCD_CMDWrite(CMD_LCD_DISPLAY_ON_CURSOR_OFF);
	LCD_CMDWrite(0x06);
}
void LCD_DisplayChar(char ch) reentrant {
	ms_Delay(1);
	P2=(ch & 0xF0);
	RS=1;
	EN=1;
	us_Delay(10);
	EN=0;
	ms_Delay(1);
	P2=((ch<<4) & 0xF0);
	RS=1;
	EN=1;
	us_Delay(10);
	EN=0;
	}
void LCD_DisplayString(char *string) reentrant {
	while(*string){
		LCD_DisplayChar(*string++);
	}
}