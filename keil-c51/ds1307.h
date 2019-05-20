#ifndef _DS1307_H
#define _DS1307_H

typedef struct
{
  unsigned char sec;
  unsigned char min;
  unsigned char hour;
  unsigned char weekDay;
  unsigned char date;
  unsigned char month;
  unsigned char year;  
}rtc_t;


#define DS1307ReadMode  0xD1u  // DS1307 ID
#define DS1307WriteMode  0xD0u  // DS1307 ID

#define DS1307SecondRegAddress   0x00u   // Address to access Ds1307 SEC register
#define DS1307DateRegAddress    0x04u   // Address to access Ds1307 DATE register
#define DS1307ControlRegAddress  0x07u   // Address to access Ds1307 CONTROL register

void DS1307_Init(void);
void DS1307_SetDateTime(rtc_t *rtc);
void DS1307_GetDateTime(rtc_t *rtc);
#endif