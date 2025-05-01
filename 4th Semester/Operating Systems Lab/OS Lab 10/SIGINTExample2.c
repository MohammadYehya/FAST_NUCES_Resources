#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<signal.h>
int state=0;
void signal_handler(int num)
{
	if(state==0)
	{
		printf("program paused\n");
		state=1;
	}
	if(state==1)
	{
		printf("program resumed\n");
		state=0;
	}
	signal(SIGINT, SIG_DFL);
}
int main()
{
	signal(SIGINT, signal_handler);
	while(1)
	{
		sleep(1);
		printf("Program running\n");
	}
	return 0;
}
