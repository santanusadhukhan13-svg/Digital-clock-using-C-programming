#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void clear_Screen()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
int main()
{
	int choice = 2;
	
	printf("\n\t\t\tDIGITAL CLOCK");
	printf("\n--------------------------------------------------------------\n");
	printf("\nChoose the time format:\n");
	printf(" 1. 24 Hour Format\n");
	printf(" 2. 12 Hour Format\n");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	while(1)
	{
		time_t raw_time; 
		struct tm *local;
		time(&raw_time);
		local = localtime(&raw_time);
		
		clear_Screen();
		
		printf("\n\n\t\tDay : %s\n",(char *[]){"Monday","Tuesday","Wednessday","Thursday","Friday","Saturday","Sunday"}
		[local->tm_wday]);
		printf("\t\tDate : %02d-%02d-%04d\n", local->tm_mday,local->tm_mon+1,local->tm_year+1900);
		
		
		
		if(choice==1)
		{
			printf("\t\tDigital Clock\n");
			printf("\t\t%02d:%02d:%02d\n",local->tm_hour,local->tm_min,local->tm_sec);
		}
		else
		{
			int hour = local->tm_hour;
			char *ampm;
			if(hour>=12)
				ampm = "PM";
			else 
				ampm = "AM";
				
			if(hour == 0)
				hour = 12;
			else if(hour > 12)
				hour = hour - 12;
			printf("\t\tDigital Clock\n");
			printf("\t\t%02d:%02d:%02d %s\n",local->tm_hour,local->tm_min,local->tm_sec,ampm);
		}
		
		fflush(stdout);
		Sleep(1000);
		printf("\033[1A");
	}
		
	return 0;
}
