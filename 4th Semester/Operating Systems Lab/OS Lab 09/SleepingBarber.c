#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_CUSTOMERS 25

void *customer(void *num);
void *barber(void *);

sem_t waitingRoom;
sem_t barberChair;
sem_t barberPillow;
sem_t seatBelt;

int allDone = 0;
int main(int argc, char *argv[])
{
	pthread_t btid;
	pthread_t tid[MAX_CUSTOMERS];
	int i, x, numCustomers, numChairs; int Number[MAX_CUSTOMERS];
	
	printf("Maximum number of customers can only be 25. Enter number of customers and chairs.\n");
	scanf("%d",&x);
	numCustomers = x;
	
	scanf("%d",&x);
	numChairs = x;
	
	if (numCustomers > MAX_CUSTOMERS)
	{
		printf("The maximum number of Customers is %d.\n", MAX_CUSTOMERS);
		return 0;
	}
	printf("A solution to the sleeping barber problem using semaphores.\n");
	
	for (i = 0; i < MAX_CUSTOMERS; i++) Number[i] = i;
	
	sem_init(&waitingRoom, 0, numChairs);
	sem_init(&barberChair, 0, 1);
	sem_init(&barberPillow, 0, 0);
	sem_init(&seatBelt, 0, 0);

	pthread_create(&btid, NULL, barber, NULL);
	
	for (i = 0; i < numCustomers; i++) pthread_create(&tid[i], NULL, customer, (void *)&Number[i]);
	for (i = 0; i < numCustomers; i++) pthread_join(tid[i],NULL);
	
	allDone = 1;
	sem_post(&barberPillow);

	pthread_join(btid,NULL);
	return 0;
}
void *customer(void *number) {
	int num = *(int *)number;
	
	printf("Customer %d leaving for barber shop.\n", num);
	sleep(5);
	
	printf("Customer %d arrived at barber shop.\n", num);
	sem_wait(&waitingRoom);
	
	printf("Customer %d entering waiting room.\n", num);
	sem_wait(&barberChair);
	sem_post(&waitingRoom); 
	
	printf("Customer %d waking the barber.\n", num);
	sem_post(&barberPillow);
	sem_wait(&seatBelt);
	sem_post(&barberChair);
	
	printf("Customer %d leaving barber shop.\n", num);
}
void *barber(void *junk)
{
	while (!allDone)
	{
		printf("The barber is sleeping\n");
		sem_wait(&barberPillow);
		
		if (!allDone)
		{
			printf("The barber is cutting hair\n");
			sleep(3);
			
			printf("The barber has finished cutting hair.\n");
			sem_post(&seatBelt);
		}
		else printf("The barber is going home for the day.\n");
	}
}
