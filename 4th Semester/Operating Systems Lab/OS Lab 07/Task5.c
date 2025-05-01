#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int p = 100;
bool checkarr[4] = {	false,	// On_day_regs
			false,	//announcements
			false,	//sponsors
			false};	//participants_queries
int countarr[4] = {0};
char *msgarr[4] = {"Managed On Day Registrations. Total Managed:",
		"Handled Announcements. Total Announcements:",
		"Handled Sponsors. Total Sponsors Handled:",
		"Resolved Participant Query. Total Queries Resolved:"};
void *v1(void*x)
{
	while(p > 0)
	{
		if(checkarr[0])
		{
			checkarr[0] = false;
			printf("Volunteer 1: %s %d\n",msgarr[0],++countarr[0]);
		}
	}
	pthread_exit(0);
}
void *v2(void*x)
{
	while(p > 0)
	{
		if(checkarr[1])
		{
			checkarr[1] = false;
			printf("Volunteer 2: %s %d\n",msgarr[1],++countarr[1]);
		}
	}
	pthread_exit(0);
}
void *v3(void*x)
{
	while(p > 0)
	{
		if(checkarr[2])
		{
			checkarr[2] = false;
			printf("Volunteer 3: %s %d\n",msgarr[2],++countarr[2]);
		}
	}
	pthread_exit(0);
}
void *v4(void*x)
{
	while(p > 0)
	{
		if(checkarr[3])
		{
			checkarr[3] = false;
			printf("Volunteer 4: %s %d\n",msgarr[3],++countarr[3]);
		}
	}
	pthread_exit(0);
}
int main(int argc, char* argv[], char* envp[])
{
	srand(time(NULL));
	pthread_t v[4];
	long x = 0;
	pthread_create(&v[0], NULL, v1, NULL);
	pthread_create(&v[1], NULL, v2, NULL);
	pthread_create(&v[2], NULL, v3, NULL);
	pthread_create(&v[3], NULL, v4, NULL);
	for(p = 100 ; p > 0 ; p--)
	{
		x = rand() % 4;
		checkarr[x] = true;
		usleep(5000);		//This is not a good approach and should be replaced by using mutex locks, but we haven't done them yet
	}
	pthread_join(v[0], NULL);
	pthread_join(v[1], NULL);
	pthread_join(v[2], NULL);
	pthread_join(v[3], NULL);
	return 0;
}
