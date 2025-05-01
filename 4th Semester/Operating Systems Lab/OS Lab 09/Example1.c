#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

#define NUM 5

#define IMPLEMENT_SEMAPHORE 1

void handler ( void *ptr );
sem_t mutex;

int counter;
int main() 
{
	int i[NUM] = {0, 1, 2, 3, 4};
	pthread_t thread[NUM];
	
	counter = 0;
	
	sem_init(&mutex, 0, 1);
	
	for(int j = 0; j < NUM; j++) pthread_create(&thread[j], 0, (void *) &handler, (void *) &i[j]);
	
	for(int j = 0; j < NUM; j++) pthread_join(thread[j],NULL);
	
	sem_destroy(&mutex);
	
	return 0;
}
void handler (void *ptr) {
	int x = *((int*)ptr);
	
	printf("sem [INFO] Thread %d Waiting to enter in critical region. \n", x);
	
	if(IMPLEMENT_SEMAPHORE) sem_wait(&mutex);
	
	printf("sem [INFO] Thread %d Enters in Critical Region. \n", x);
	printf("sem [INFO] Thread %d Value of Counter is %d.\n",x,counter);
	printf("sem [INFO] Thread %d Increamenting The Value of counter\n",x);
	
	counter++;
	
	printf("sem [INFO] Thread %d New value of counter is: %d\n",x, counter);
	printf("sem [INFO] Thread %d Exiting Critical Region.\n", x);
	
	if(IMPLEMENT_SEMAPHORE) sem_post(&mutex);
	
	pthread_exit(0);
}
