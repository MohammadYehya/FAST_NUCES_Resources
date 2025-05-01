#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define NumOfCooks 5
#define CookingStations 3

#define NumOfServers 4
#define ServingTrays 2

#define BUFFER_SIZE 10

typedef struct OrderData
{
	int StationID;
	int TrayID;
	int OrderNumber;
} OrderData;
void InitData(OrderData* ptr)
{
	for(int i = 0 ; i < BUFFER_SIZE ; i++) {ptr[i].StationID = 0; ptr[i].TrayID = 0; ptr[i].OrderNumber = -1;}
}

typedef struct Buffer
{
	OrderData data[BUFFER_SIZE];
	int idx0, idxn;
} Buffer;
void InitBuffer(Buffer* ptr)
{
	InitData(ptr->data);
	ptr->idx0 = 0;
	ptr->idxn = 0;
}
void _InitBuffer(int* ptr, int size)
{
	for(int i = 0 ; i < size ; i++) ptr[i] = i+1;
}

sem_t CookSem, ServeSem, _ServeSem;
sem_t EmptySem, FullSem;
pthread_mutex_t CookMut, ServeMut, TrayCountMut;
Buffer CookBuffer, ServeBuffer;
int TrayCount = 0, GLOBAL_COUNT = 0, Stations[CookingStations], Trays[ServingTrays];

OrderData dequeue(Buffer* b, pthread_mutex_t* mut)
{
	sem_wait(&FullSem);
	pthread_mutex_lock(mut);
	
	OrderData x = b->data[b->idx0];
	b->data[b->idx0].OrderNumber = -1;
	if(x.OrderNumber == -1)
	{
		pthread_mutex_unlock(mut);
		return x;
	}
	b->idx0 = (b->idx0+1)%BUFFER_SIZE;
	
	pthread_mutex_unlock(mut);
	sem_post(&EmptySem);
	return x;
}
void enqueue(Buffer *b, OrderData x, pthread_mutex_t* mut)
{
	sem_wait(&EmptySem);
	pthread_mutex_lock(mut);
	
	b->data[b->idxn] = x;
	b->idxn = (b->idxn+1)%BUFFER_SIZE;
	
	pthread_mutex_unlock(mut);
	sem_post(&FullSem);
}

void *Cook(void *args)
{
	while(1)
	{
		sem_wait(&CookSem);

		OrderData x = dequeue(&CookBuffer, &CookMut);

		if(x.OrderNumber == -1)
		{
			sem_post(&CookSem);
			continue;
		}
		
		for(int i = 0 ; i < CookingStations ; i = (i + 1)%CookingStations)
		{
			if(Stations[i])
			{
				x.StationID = Stations[i];
				Stations[i] = 0;
				break;
			}
		}
		
		printf("Chef %ld\tCooking Order#%d\t\tUsing Cooking Station %d!\n",(long)args,x.OrderNumber,x.StationID);
		sleep(rand()%3+1);		//Sleep for 1-3 seconds to simulate creation of order
		printf("Chef %ld\tCompleted Order#%d\tFinished using Cooking Station %d!\n",(long)args,x.OrderNumber,x.StationID);

		Stations[x.StationID - 1] = x.StationID;
		
		enqueue(&ServeBuffer, x, &ServeMut);
		sem_post(&CookSem);
		sem_post(&ServeSem);
		sleep(1);
	}
}
void *Server(void *args)
{
	while(1)
	{
		sem_wait(&ServeSem);
		sem_wait(&_ServeSem);
		
		OrderData x = dequeue(&ServeBuffer, &ServeMut);
		
		for(int i = 0 ; i < ServingTrays ; i = (i + 1)%ServingTrays)
		{
			if(Trays[i])
			{
				x.TrayID = Trays[i];
				Trays[i] = 0;
				break;
			}
		}
		printf("Server %ld\t\t\tServed Order#%d\tUsing Tray %d!\n",(long)args,x.OrderNumber,x.TrayID);
		
		sleep(1);
		
		Trays[x.TrayID - 1] = x.TrayID;
		
		sem_post(&_ServeSem);
	}
}
void *StartRestaurant(void *args)
{
	usleep(1000);
	pthread_t _Cook[NumOfCooks], _Server[NumOfServers];
	for(int i = 0 ; i < NumOfCooks; i++) pthread_create(&_Cook[i], NULL, Cook, (void*)(long)(i+1));
	for(int i = 0 ; i < NumOfServers; i++) pthread_create(&_Server[i], NULL, Server, (void*)(long)(i+1));
	
	for(int i = 0 ; i < NumOfCooks; i++) pthread_join(_Cook[i], NULL);
	for(int i = 0 ; i < NumOfServers; i++) pthread_join(_Server[i], NULL);
}

int main(int argc, char *argv[], char *envp[])
{
	InitBuffer(&CookBuffer);
	InitBuffer(&ServeBuffer);
	
	_InitBuffer(Stations, CookingStations);
	_InitBuffer(Trays, ServingTrays);
	
	sem_init(&CookSem, 0, CookingStations);
	sem_init(&ServeSem, 0 , 0);
	sem_init(&_ServeSem, 0 , ServingTrays);
	sem_init(&EmptySem, 0 , BUFFER_SIZE);
	sem_init(&FullSem, 0 , 0);
	
	pthread_mutex_init(&CookMut, NULL);
	pthread_mutex_init(&ServeMut, NULL);
	pthread_mutex_init(&TrayCountMut, NULL);
	
	pthread_t Restaurant;
	pthread_create(&Restaurant, NULL, StartRestaurant, NULL);
	
	while(1)
	{
		OrderData temp = {.OrderNumber = ++GLOBAL_COUNT};
		enqueue(&CookBuffer, temp, &CookMut);
		sleep(1);
	}

	pthread_join(Restaurant, NULL);
	
	pthread_mutex_destroy(&CookMut);
	pthread_mutex_destroy(&ServeMut);
	pthread_mutex_destroy(&TrayCountMut);
	
	sem_destroy(&CookSem);
	sem_destroy(&ServeSem);
	sem_destroy(&_ServeSem);
	sem_destroy(&EmptySem);
	sem_destroy(&FullSem);
}
