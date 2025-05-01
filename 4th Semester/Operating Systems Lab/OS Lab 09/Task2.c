#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

sem_t WeightingMut, SecurityMut, BoardingMut;

void *C(void *args)
{
	long x = *(long*)args;
	
	sem_wait(&WeightingMut);
	printf("Passenger#%ld is weighting their luggage!\n", x);
	sleep(4);
	sem_post(&WeightingMut);
	
	sem_wait(&SecurityMut);
	printf("Passenger#%ld is checking their luggage!\n", x);
	sleep(7);
	sem_post(&SecurityMut);
	
	sem_wait(&BoardingMut);
	printf("Passenger#%ld is boarding!\n", x);
	sleep(3);
	sem_post(&BoardingMut);
}

int main(int argc, char *argv[])
{
	long x[10] = {1,2,3,4,5,6,7,8,9,10};
	pthread_t Passenger[10];
	
	sem_init(&WeightingMut, 0 , 1);
	sem_init(&SecurityMut, 0 , 1);
	sem_init(&BoardingMut, 0 , 1);
	
	for(int i = 0; i < 10; i++) pthread_create(&Passenger[i], NULL, C, (void*)&x[i]);
	for(int i = 0; i < 10; i++) pthread_join(Passenger[i], NULL);
	
	sem_destroy(&WeightingMut);
	sem_destroy(&SecurityMut);
	sem_destroy(&BoardingMut);
	
	return 0;
}
