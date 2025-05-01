#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *Print(void *x)
{
	printf("Hello from thread %ld - I was created in iteration %ld\n",(long)x + 2,(long)x);
	pthread_exit(0);
}

void *MainThread(void *x)
{
	pthread_t t[(long)x];
	for(long i = 0 ; i < (long)x ; i++)
	{
		printf("I am thread 1. Created new thread (%ld) in iteration %ld...\n", i+2, i);
		pthread_create(&t[i], NULL, Print, (void*)i);
		if((i % 5) == 0) sleep(1);
	}
	for(long i = 0 ; i < (long)x ; i++)
	{
		pthread_join(t[i], NULL);
	}
	pthread_exit(0);
}

int main(int argc, char *argv[], char *envp[])
{
	pthread_t mt;
	pthread_create(&mt, NULL, MainThread, (void*)(long)atoi(argv[1]));
	pthread_join(mt, NULL);
	return 0;
}
