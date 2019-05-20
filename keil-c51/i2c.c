#include"delay.h"
#include"i2c.h"

void I2C_Init() reentrant{
	SCL=1;
	SDA=1;
}
static void I2C_Clock() reentrant{
	us_Delay(1);
	SCL=1;
	us_Delay(1);
	SCL=0;
}
static void I2C_ACK() reentrant{
	SDA=0;
	I2C_Clock();
	SDA=1;
}
static void I2C_NACK() reentrant{
	SDA=1;
	I2C_Clock();
	SCL=1;
}
void I2C_Start() reentrant{
	SCL=0;
	SDA=1;
	us_Delay(1);
	SCL=1;
	us_Delay(1);
	SDA=0;
	us_Delay(1);
	SCL=0;
}
void I2C_Stop() reentrant{
	SCL=0;
	us_Delay(1);
	SDA=0;
	us_Delay(1);
	SCL=1;
	us_Delay(1);
	SDA=1;
}
	
void I2C_Write(unsigned char data_source) reentrant {
	unsigned char i;
	for(i=0;i<8;i++){
		SDA=data_source&0x80;
		I2C_Clock();
		data_source=data_source<<1;
	}
	I2C_Clock();
}
unsigned char I2C_Read(unsigned char ack) reentrant{
	unsigned char i,dat=0x00;
	SDA=1;
	for(i=0;i<8;i++){
		us_Delay(1);
		SCL=1;
		us_Delay(1);
		dat=dat<<1;
		dat=dat|SDA;
		SCL=0;
	}
	if(ack==1){
		I2C_ACK();
	}else{
		I2C_NACK();
	}
	return dat;
}



