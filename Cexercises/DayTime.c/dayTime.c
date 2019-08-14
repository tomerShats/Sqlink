#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "dayTime.h"

static char monthsName[12][128]={"january","february","march","april","may","june","august","september","october","november","december"};
static int monthsDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
cTime_t * updateT(cTime_t * time,int hour,int min,int sec){
   time->hour=hour;
   time->min=min;
   time->sec=sec;
   return time;

}

void printTime(cTime_t * time,int format){
if (time!=NULL){
  if(format==1){ 
    printf(" %d:%d:%d \n",time->hour,time->min,time->sec);
    
  }else if(format==2){
       
            printf(" %d:%d:%d  %s  \n",time->hour%12,time->min,time->sec,((time->hour)>=12)?"PM":"AM");
       
  }else{
     printf("your format is not good");
  }

}

}

int getHour(cTime_t * time){
 if (time!=NULL){

   return time->hour;
 }
 return 0;
}
int getMin(cTime_t * time){
  if (time!=NULL){

   return time->min;
  }
 return 0;
}
int getSec(cTime_t * time){
 if (time!=NULL){

   return time->sec;
 }
 return 0;
}


cTime_t * add(cTime_t * time1,cTime_t * time2){
  if ((time1!=NULL)&&(time2!=NULL)){

     int secD,minD;
     secD=(time1->sec+time2->sec)/60;
     minD=(time1->min+time2->min+secD)/60;
     time1->sec=(time1->sec+time2->sec)%60;
     time1->min=(time1->min+time2->min+secD)%60;
     time1->hour=(time1->hour+time2->hour+minD)%24;
     
     return time1;

   }
 return NULL;

}


cDate_t * updateD(cDate_t * date,int day,int mon,int year){
  if (date!=NULL){
   date->year=year;
   date->mon=mon;
   date->day=day;
   return date;
  }
 return NULL;
}


void printDate(cDate_t * date,int format){
 if (date!=NULL){
   if(format==1){ 
    printf(" %d:%s:%d \n",date->day,monthsName[(date->mon)-1],date->year);
    
  }else if(format==2){
       
            printf(" %d:%d:%d \n",date->day,date->mon,date->year);
       
  }else if(format==3){
         printf(" %d:%d:%d \n",date->mon,date->day,date->year);
       
  }else{
    printf("your format is not good");
  }
}
 
}

int getDay(cDate_t * date){
 if (date!=NULL){
   return date->day;
  }
  return 0;
}
int getMon(cDate_t * date){
  if (date!=NULL){
   return date->mon;
  }
  return 0;
}
int getYear(cDate_t * date){
  if (date!=NULL){
   return date->year;
   } 
  return 0;
}

int getDayYear(cDate_t * date){
 if (date!=NULL){
   int sumDays=0,i;
   for(i=0;i<(date->mon)-1;i++){
      sumDays+=monthsDays[i];
     
   }
   if((ifLeapYear(date)==1)&&(date->mon>2)){
      sumDays++;
   }

   sumDays+=date->day;
   return sumDays;
 }
 return 0;
}

int ifLeapYear(cDate_t * date){
if (date!=NULL){
    if(date->year%4==0){
         return 1;
    }
 }
 return 0;
}

char * getMonthName(cDate_t * date){
  if (date!=NULL){
    return monthsName[(date->mon)-1]; 
   }
  return NULL; 

}

cDate_t * addDays(cDate_t * date1,cDate_t * date2){
  if ((date1!=NULL)&&(date2!=NULL)){

 
    int dayf;
    if(ifLeapYear(date1)==0){
        monthsDays[1]=28;
      
    }else{ 
       monthsDays[1]=29;   
   
    }
    dayf=date1->day+date2->day;
        if(dayf>monthsDays[(date1->mon)-1]){
     
           dayf=1;    
  
        }else{
           dayf=0;
        }

     
      date1->day=(date1->day+date2->day)%monthsDays[(date1->mon)-1];
      date1->mon=(date1->mon+dayf)%12;
      date1->year=date1->year+((date1->mon+dayf)/12);
     return date1; 
  }
return NULL;

}















