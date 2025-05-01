#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void SIGTSTP_Handler()
{
	printf("SIGTSTP ignored!\n");
}
void SIGKILL_Handler()
{
	printf("SIGKILL ignored!\n");
}
int main(int argc, char *argv[])
{
	signal(SIGTSTP, SIGTSTP_Handler);
	signal(SIGKILL, SIGKILL_Handler);
	int pid;
	while(1)
	{	
		if(pid = fork())
		{
			kill(pid, SIGKILL);
		}
		else
		{
			sleep(1);
			return 0;
		}
		sleep(1);
	}
	return 0;
}
