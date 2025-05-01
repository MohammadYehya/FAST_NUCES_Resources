#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

int icecreamremaining = 10;
sem_t mutex;
void *IceCream(void *args)
{
	long x = *(long*)args;
	while(icecreamremaining > 0)
	{
		sem_wait(&mutex);
		
		printf("Contestant# %ld is eating icecream cone# %d!\n", x, icecreamremaining--);
		
		sem_post(&mutex);
		usleep(10);
	}
}
int main(int argc, char *argv[])
{
	long x[3] = {1,2,3};
	sem_init(&mutex, 0 , 1);
	
	pthread_t t[3];
	for(int i = 0; i < 3; i++) pthread_create(&t[i], NULL, IceCream, (void*)&x[i]);
	for(int i = 0; i < 3; i++) pthread_join(t[i], NULL);
	
	sem_destroy(&mutex);
	return 0;
}
