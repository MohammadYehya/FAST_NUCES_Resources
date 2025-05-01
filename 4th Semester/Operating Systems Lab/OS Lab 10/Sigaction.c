#include <stdio.h>
#include <signal.h>
#include<wait.h>
#include<unistd.h>

void handler(int signum)
{
	if(signum == SIGINT)
	{
		printf("CONTROL SIGNAL IS PRESSED!");
	}
}
int main()
{
	struct sigaction sa;
	sa.sa_handler = handler;
	while(1)
	{
		printf("/");
		for(int i=0;i<=100000;i++){}
		if(sigaction(SIGINT, &sa, NULL) == -1) perror("S1GACTION");
	}
	return 0;
}
