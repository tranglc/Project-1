#ifndef _I2C_H
#define _I2C_H

#include<AT89X52.h>

sbit SCL=P1^0;
sbit SDA=P1^1;

void I2C_Init(void) reentrant;
void I2C_Start(void) reentrant;
void I2C_Stop(void) reentrant;
void I2C_Write(unsigned char ) reentrant;
unsigned char I2C_Read(unsigned char) reentrant;

#endif