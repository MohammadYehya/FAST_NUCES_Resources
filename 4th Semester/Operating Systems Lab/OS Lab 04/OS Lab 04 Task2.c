#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
	int count = 0;
	int pid = fork();
	if(pid < 0) printf("Unsuccessful Child Process Creation");
	else if (pid == 0)
	{
		for (int i = 0; i < 5 ; i++) printf("%d ",++count);
		printf("\n");
		sleep(3);
		printf("Parent Process ID: %d\n",getppid());
		execl("/usr/bin/gedit",(char*)NULL);
	}
	else
	{
		wait(NULL);
		for (int i = 0; i < 5 ; i++) printf("%d ",++count);
		printf("\n");
	}
}
