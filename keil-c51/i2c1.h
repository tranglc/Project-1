#ifndef _I2C1_H
#define _I2C1_H

#include<AT89X52.h>

sbit SCL1=P3^2;
sbit SDA1=P3^3;

void I2C_Init1(void);
void I2C_Start1(void);
void I2C_Stop1(void);
void I2C_Write1(unsigned char );
//unsigned char I2C_Read1(unsigned char);

#endif