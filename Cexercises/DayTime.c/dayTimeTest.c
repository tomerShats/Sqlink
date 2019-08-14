#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "dayTime.h"


int main(){
   int hour,min,sec,format,day,mon,year,sumDays;
   cDate_t * date;
   cDate_t * date2;
   

   
	   cTime_t * time1;
	   cTime_t * time2;
	   time1=malloc(sizeof(cTime_t));
	   time2=malloc(sizeof(cTime_t));
	   printf("enter an hour ");
	   scanf("%d",&hour);
	   printf("enter an minutes ");
	   scanf("%d",&min);
	   printf("enter an seconds ");
	   scanf("%d",&sec);
	   updateT(time1,hour,min,sec);
	   printf("enter a format to print 1 or 2 ");
	   scanf("%d",&format);
	   printTime(time1,format);
	   printf("the hour is: %d\n",getHour(time1));
	   printf("the minutes are: %d\n",getMin(time1));
	   printf("the seconds are: %d\n",getSec(time1));
	   printf("now create one more time and add this time to the last time\n ");
	   printf("enter an hour ");
	   scanf("%d",&hour);
	   printf("enter an minutes ");
	   scanf("%d",&min);
	   printf("enter an seconds ");
	   scanf("%d",&sec);
	   updateT(time2,hour,min,sec);
	   add(time1,time2);
	   printTime(time1,format);


	   date=malloc(sizeof(cDate_t));
	   date2=malloc(sizeof(cDate_t));
	   printf("enter a day ");
	   scanf("%d",&day);
	   printf("enter a mon ");
	   scanf("%d",&mon);
	   printf("enter a year ");
	   scanf("%d",&year);
	   updateD(date,day,mon,year);
	   printf("enter a format to print 1 or 2 or 3 \n");
	   scanf("%d",&format);
	   printDate(date,format);
	   printf("the day is: %d\n",getDay(date));
	   printf("the mon is: %d\n",getMon(date));
	   printf("the year is: %d\n",getYear(date));
	   sumDays=getDayYear(date);
	   printf("the day in year is: %d\n",sumDays);
	   printf("if leap year?: %d\n",ifLeapYear(date));
	   printf("the name of months is: %s\n",getMonthName(date));
	   printf("enter another date with same month and year \n");
	   printf("enter a day ");
	   scanf("%d",&day);
	   printf("enter a mon ");
	   scanf("%d",&mon);
	   printf("enter a year ");
	   scanf("%d",&year);
	   updateD(date2,day,mon,year);
	   printf(" now the days add to the previous date \n");
	   date=addDays(date,date2);
	   printDate(date,format);
	   
	   
   
   
  

   free(date);
   free(date2);
   free(time1);
   free(time2);
 return 0;
}
