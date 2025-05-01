#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	printf("I am Process \"A\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
	if(fork())
	{
		if(fork())
		{
			if(!fork())
			{
				printf("I am Process \"D\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
			}
		}
		else
		{
			printf("I am Process \"C\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
			if(fork())
			{
				if(!fork())
				{
					printf("I am Process \"G\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
				}
			}
			else
			{
				printf("I am Process \"F\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
			}
		}
	}
	else
	{
		printf("I am Process \"B\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
		if(!fork())
		{
			printf("I am Process \"E\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
		}
	}
	usleep(500);
}
