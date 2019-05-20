#include"delay.h"
#include"i2c1.h"

void I2C_Init1(){
	SCL1=1;
	SDA1=1;
}
static void I2C_Clock(){
	us_Delay(1);
	SCL1=1;
	us_Delay(1);
	SCL1=0;
}
//static void I2C_ACK(){
//	SDA1=0;
//	I2C_Clock();
//	SDA1=1;
//}
//static void I2C_NACK(){
//	SDA1=1;
//	I2C_Clock();
//	SCL1=1;
//}
void I2C_Start1(){
	SCL1=0;
	SDA1=1;
	us_Delay(1);
	SCL1=1;
	us_Delay(1);
	SDA1=0;
	us_Delay(1);
	SCL1=0;
}
void I2C_Stop1(){
	SCL1=0;
	us_Delay(1);
	SDA1=0;
	us_Delay(1);
	SCL1=1;
	us_Delay(1);
	SDA1=1;
}
	
void I2C_Write1(unsigned char data_source){
	unsigned char i;
	for(i=0;i<8;i++){
		SDA1=data_source&0x80;
		I2C_Clock();
		data_source=data_source<<1;
	}
	I2C_Clock();
}
//unsigned char I2C_Read1(unsigned char ack){
//	unsigned char i,dat=0x00;
//	SDA1=1;
//	for(i=0;i<8;i++){
//		us_Delay(1);
//		SCL1=1;
//		us_Delay(1);
//		dat=dat<<1;
//		dat=dat|SDA1;
//		SCL1=0;
//	}
//	if(ack==1){
//		I2C_ACK();
//	}else{
//		I2C_NACK();
//	}
//	return dat;
//}



