#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(int argc, char** argv)
{
	int i = fork();
	if (i < 0)
	{printf("Unsuccessful Child Process Creation!");exit(0);}
	else if (i > 0)
	{
		wait(NULL);
		for (int j = 0 ; j < 10 ; j++)
		{
			if (!(j % 2)) printf("%d ",j);
		}
		printf("Parent Ends!\n");
	}
	else
	{
		printf("Parent ID: %d\n",getppid());
		for (int j = 0 ; j < 10 ; j++)
		{
			if ((j % 2)) printf("%d ",j);
		}
		printf("Child Ends!\n");
	}
}
