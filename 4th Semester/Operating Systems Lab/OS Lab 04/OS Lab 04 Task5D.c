#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	printf("I am Process \"1\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
	if(fork())
	{
		if(!fork())
		{
			printf("I am Process \"3\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
			if(fork())
			{
				if(!fork())
				{
					printf("I am Process \"7\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
				}
			}
			else printf("I am Process \"6\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
		}
	}
	else
	{
		printf("I am Process \"2\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
		if(fork())
		{
			if(!fork())
			{
				printf("I am Process \"4\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
				if(fork())
				{
					if(!fork()) printf("I am Process \"8\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
				}
				else printf("I am Process \"9\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
			}
		}
		else printf("I am Process \"5\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
	}
	usleep(750);
}
