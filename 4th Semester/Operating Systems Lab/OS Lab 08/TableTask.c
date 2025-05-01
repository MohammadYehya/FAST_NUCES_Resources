#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;

void *Tables(void *num)
{
	pthread_mutex_lock(&mutex);
	for(int i = 0 ; i <= 10 ; i++) 
	{
		printf("%ld x %d = %ld\n", (long)num, i, (long)num * i);
	}
	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
}
int main(int argc, char *argv[], char *envp[])
{
	pthread_t t[4];
	pthread_mutex_init(&mutex,0);
	for(int i = 0 ; i <= 3 ; i++) pthread_create(&t[i], NULL, Tables, (void*)(long)(i+5));
	for(int i = 0 ; i <= 3 ; i++) pthread_join(t[i], NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
