#include "BH-1750.h"
#include "i2c.h"                                     
#include "delay.h"             
void BH1750_init() reentrant
{ 
   ms_Delay(100);  
   BH1750_write(power_down);
}                  
              

void BH1750_write(unsigned char cmd) reentrant
{ 
   I2C_Start();
   I2C_Write(BH1750_write_cmd);        
   I2C_Write(cmd);                
   I2C_Stop();   
}

              
                                   
unsigned int BH1750_read_word() reentrant
{                      
   unsigned long value = 0; 
   unsigned char lb = 0;
   unsigned char hb = 0;
   
   I2C_Start();
   I2C_Write(BH1750_read_cmd);      
   hb = I2C_Read(1);  
   lb = I2C_Read(0);
   I2C_Stop();                           
   value = ((hb << 8) | lb);     
   return value;
} 


unsigned int get_lux_value(unsigned char mode, unsigned int delay_time) reentrant
{
   unsigned long lux_value = 0;  
       BH1750_write(power_up);
       BH1750_write(mode);
       lux_value += BH1750_read_word();
       ms_Delay(delay_time);
			 BH1750_write(power_down);
   return ((unsigned int)lux_value);
}                                