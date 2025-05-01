#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define MAXSIZE 10

void ExitWithMessage(char *c) 
{
	perror(c);
	exit(1);
}

int main(int argc, char** argv)
{
	int shmid;
	key_t key;
	char *shm = NULL;
	key = 3309;

	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0) ExitWithMessage("shmget");
	if((shm = (char*)shmat(shmid, NULL, 0)) == (char*)-1) ExitWithMessage("shmat");
	while(!(*shm)) usleep(100);
	int x = (int)*shm;
	strncpy(shm, "ready", 5);
	while(*shm != '*')usleep(100);
	for(int i = 1 ; i <= 10 ; i++)
	{
		*(shm + MAXSIZE-1) = (x*i == 42);
		int temp = x*i;
		memcpy(shm, &temp, sizeof(int));
		while(*shm != '*' || *(shm + MAXSIZE-1)) {usleep(100);}
	}
	printf("Done!\n");
	exit(0);
}


