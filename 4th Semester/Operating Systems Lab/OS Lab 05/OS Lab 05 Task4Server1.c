#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAXSIZE 10

void ExitWithMessage(char* c)
{
	perror(c);
	exit(1);
}

int main(int agrc, char** argv)
{
	int shmid;
	key_t key;
	int *A;
	
	key = 65;
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0) ExitWithMessage("SHMGET");
	if((A = (int*)shmat(shmid, NULL, 0)) == (int*)-1) ExitWithMessage("SHMAT");
	*A = 0;
	while(*A != -1) sleep(1);
	exit(0);
}
