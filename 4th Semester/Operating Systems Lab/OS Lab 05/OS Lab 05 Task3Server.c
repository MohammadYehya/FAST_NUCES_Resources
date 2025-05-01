#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define MAXSIZE 10

void ExitWithMessage(char* c)
{
	perror(c);
	exit(1);
}

int SharedMemChecker(char* ptr, char *c, int n)
{
	for (int i = 1 ; i < n ; i++)
	{
		if (ptr[i] != c[i]) return 0;
	}
	return 1;
}

int main(int argc, char** argv)
{
	int shmid;
	key_t key;
	char *shm = NULL;
	key = 3309;
	
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0) ExitWithMessage("SHMGET");
	if((shm = (char*)shmat(shmid, NULL, 0)) == (char*)-1) ExitWithMessage("SHMAT");
	*shm = 42;
	while(strcmp(shm, "ready"))usleep(100);
	printf("%s\n",shm);
	*shm = '*';
	for(int i = 1 ; i <= 10 ; i++)
	{
		while(*shm == '*' && !*(shm+MAXSIZE-1)) {usleep(100);}//shm+MAXSIZE-1 will act as a boolean test value for the edge case of 42 as the ASCII value of * is 42
		printf("%d ",*(int*)shm);
		*(shm + MAXSIZE-1) = 0;
		*shm = '*';
	}
	printf("\n");
	exit(0);
}
