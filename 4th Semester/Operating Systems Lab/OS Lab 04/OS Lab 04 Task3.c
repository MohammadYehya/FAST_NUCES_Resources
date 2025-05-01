#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char** argv)
{
	int nchilds = 3, i;
	for (i = 0 ; i < nchilds ; i++)
	{
		if (!fork())
		{
			if (i == nchilds - 1)
			{
				execl("/bin/sh","/bin/sh","Task3Bash.sh",(char*)NULL);
			}
		}
		else break;
	}
	printf("P%d waiting for P%d\n",i,i+1);
	wait(NULL);
}
