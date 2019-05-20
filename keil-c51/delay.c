#include"delay.h"

void us_Delay(unsigned int us_count)
 {    
    while(us_count!=0)
      {
         us_count--;
       }
 }

void ms_Delay(unsigned int ms_count)
 {
     while(ms_count!=0)
      {
         us_Delay(CountForOneMs);
          ms_count--;
      }

 }