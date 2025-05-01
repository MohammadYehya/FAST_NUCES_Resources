#include <stdio.h>
#include <pthread.h>

volatile int counter = 0; 
pthread_mutex_t myMutex;
void *mutex_testing (void *param)
{
	int i;
	for (i=0; i < 5; i++) 
	{
		pthread_mutex_lock(&myMutex);
		counter++;
		printf("thread %ld counter = %d loop = %d\n", (long)param, counter, i);
		pthread_mutex_unlock(&myMutex);
	}
}
int main(int argc, char *argv[], char* envp[])
{
	
	int one = 1, two = 2, three = 3;
	pthread_t thread1, thread2, thread3;
	pthread_mutex_init(&myMutex,0);
	pthread_create (&thread1, 0, mutex_testing, (void*)(long)one);
	pthread_create (&thread2, 0, mutex_testing, (void*)(long)two);
	pthread_create (&thread3, 0, mutex_testing, (void*)(long)three);
	pthread_join(thread1, 0);
	pthread_join(thread2, 0);
	pthread_join(thread3, 0);
	pthread_mutex_destroy(&myMutex);
	return 0;
}
