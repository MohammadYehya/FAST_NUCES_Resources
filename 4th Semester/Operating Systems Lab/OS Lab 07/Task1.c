#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM 3
void* print(void *t)
{
	printf("Thread %ld\n",(long)t + 1);
	pthread_exit(0);
}
int main(int argc, char *argv[], char *envp[])
{
	pthread_t thread[NUM];
	for(int i = 0 ; i < NUM ; i++)
	{
		int rv = pthread_create(&thread[i], NULL, print, (void*)(long)i);
		if (rv)
		{
			printf("Error!");
			exit(-1);
		}
	}
	for(int i = 0 ; i < NUM ; i++) 
	{
		int rv = pthread_join(thread[i], NULL);
		printf("Thread %d returns %d\n",i + 1, rv);
	}
	return 0;
}
