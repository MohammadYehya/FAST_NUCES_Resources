#include <stdio.h>
#include <signal.h>
int alarmFlag = 0 ;
void alarmHandler() 
{
	printf ("An ALARM clock signal was received\n");
	alarmFlag = 1;
}
int main()
{
	signal(SIGALRM, alarmHandler);
	alarm(5);
	printf("Looping ...\n");
	while(!alarmFlag)
	{
		pause();
		printf("Loop ends due to alarm signal\n");
	}
}
