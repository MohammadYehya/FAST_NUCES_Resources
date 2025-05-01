#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAXSIZE 10

void ExitWithMessage(char *c) 
{
	perror(c);
	exit(1);
}

int main(void) {
	int shmidA, shmidB;
	key_t keyA, keyB;
	int *shmA, *shmB;
	int A, B, n;
	
	printf("Enter length of Fibonacci Series: "); scanf("%d",&n);
	keyA = 65;
	keyB = 66;
	if((shmidA = shmget(keyA, MAXSIZE, IPC_CREAT | 0666)) < 0) ExitWithMessage("shmget");
	if((shmA = (int*)shmat(shmidA, NULL, 0)) == (int*)-1) ExitWithMessage("shmat");
	if((shmidB = shmget(keyB, MAXSIZE, IPC_CREAT | 0666)) < 0) ExitWithMessage("shmget");
	if((shmB = (int*)shmat(shmidB, NULL, 0)) == (int*)-1) ExitWithMessage("shmat");
	for(int i = 0; i < n ; i++)
	{
		A = *shmA;
		B = *shmB;
		int temp = A+B;
		*shmA = B;
		*shmB = temp;
		printf("%d ",A);
	}
	*shmA = *shmB = -1;
	printf("\n");
	exit(0);
}


