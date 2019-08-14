#ifndef DA_T
#define DA_T

typedef struct{
int sec;
int min;
int hour;

} cTime_t;

typedef struct{
int year;
int mon;
int day;

} cDate_t;


cTime_t * update(cTime_t * time,int hour,int min,int sec); 
void printTime(cTime_t * time,int format);
int getHour(cTime_t * time);
int getMin(cTime_t * time);
int getSec(cTime_t * time);
cTime_t * add(cTime_t * time1,cTime_t * time2);


cDate_t * updateD(cDate_t * date,int day,int mon,int year);
void printDate(cDate_t * date,int format);
int getDay(cDate_t * date);
int getMon(cDate_t * date);
int getYear(cDate_t * date);
int getDayYear(cDate_t * date);
int ifLeapYear(cDate_t * date);
char * getMonthName(cDate_t * date);
cDate_t * addDays(cDate_t * date1,cDate_t * date2);












#endif
