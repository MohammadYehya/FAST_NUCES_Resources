#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

int bufsize = 10, in = 0, out = 0, buf[10];
sem_t Mutex, Full, Empty;

void *Producer(void *args)
{
	int produce;
	while(1)
	{
		produce = rand()%100;
		sleep(rand()%2+1);	/*Production Time 1-2 sec*/
		
		sem_wait(&Empty);
		sem_wait(&Mutex);
		
		buf[in] = produce;
		printf("Produced %d\n",buf[in]);
		in = (in+1)%bufsize;
		
		sem_post(&Mutex);
		sem_post(&Full);
	}
}

void *Consumer(void *args)
{
	int consume;
	while(1)
	{
		sem_wait(&Full);
		sem_wait(&Mutex);
		
		consume = buf[out];
		printf("\t\tConsumed %d\n",consume);
		out = (out+1)%bufsize;
		
		sem_post(&Mutex);
		sem_post(&Empty);
		
		sleep(rand()%2+2);	/*Consumption Time 2-3 sec*/
	}
}

int main(int argc, char *argv[], char *envp[])
{
	pthread_t prod, cons;
	sem_init(&Mutex, 0, 1);
	sem_init(&Empty, 0, bufsize);
	sem_init(&Full, 0, 0);
	
	pthread_create(&prod, NULL, Producer, NULL);
	pthread_create(&cons, NULL, Consumer, NULL);
	
	pthread_join(prod, NULL);
	pthread_join(cons, NULL);
	
	sem_destroy(&Mutex);
	sem_destroy(&Empty);
	sem_destroy(&Full);
	
	return 0;
}
