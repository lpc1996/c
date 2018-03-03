#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
//#include <WinBase.h>

typedef struct _time{
	int year;
	int mon;
	int day;
	int hour;
	int minute;
	int seconds;
}Time;

Time* get_time();
void print_time();

void main(){
	print_time();
}

Time* get_time(){
	time_t date_time;
	struct tm *tm_ptr = NULL;
	time(&date_time);
	tm_ptr = gmtime(&date_time);
	tm_ptr = localtime(&date_time);
	Time *tm_data = (Time *)malloc(sizeof(Time));
	tm_data->year = tm_ptr->tm_year+1900;
	tm_data->mon = tm_ptr->tm_mon+1;
	tm_data->day = tm_ptr->tm_mday;
	tm_data->hour = tm_ptr->tm_hour;
	tm_data->minute = tm_ptr->tm_min;
	tm_data->seconds = tm_ptr->tm_sec;
	return tm_data;
}

void print_time(){
	Time *time = NULL;
	do{
		time = get_time();
		printf("Now time:%d年%02d月%02d日    %02d:%02d:%02d\n",time->year,time->mon,time->day,time->hour,time->minute,time->seconds);
		sleep(1);
	}while(1);
}
