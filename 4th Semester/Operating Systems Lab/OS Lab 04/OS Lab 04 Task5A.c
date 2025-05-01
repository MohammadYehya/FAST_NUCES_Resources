#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	printf("I am Process \"Root\"\t and my PID is %d and my parent PID is %d\n",getpid(),getppid());
	if (fork()) //Checking if parent
	{
		wait(NULL);
		//Then Create a leaf node
		if(!fork())
		{
			 printf("I am Process \"Leaf\"\t and my PID is %d and my parent PID is %d\n",getpid(),getppid());
			 exit(0);
		}
		else wait(NULL);
	}
	else  //Checking if child
	{
		printf("I am Process \"InnerNode\" and my PID is %d and my parent PID is %d\n",getpid(),getppid());
		//Then create grandchild
		if(fork()) //Checking if parent (of grandchild)
		{
			wait(NULL);
			if(!fork())
			{
				printf("I am Process \"Leaf\"\t and my PID is %d and my parent PID is %d\n",getpid(),getppid());
				exit(0);
			}
			else
			{
				wait(NULL);
				exit(0);
			}
		}
		else //Checking if grandchild
		{
			printf("I am Process \"Leaf\"\t and my PID is %d and my parent PID is %d\n",getpid(),getppid());
			exit(0);
		}
	}
	printf("As you can see, \"Root\" and \"InnerNode\" are parents of two different children\n");
}
