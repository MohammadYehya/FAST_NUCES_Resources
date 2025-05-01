#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define N 20

int m1[N][N], m2[N][N], ans[N][N];
sem_t Mut;
void populateArray(int m[N][N])
{
	int i,j;
	for(i = 0 ; i < N; i++)
	{
		for(j = 0 ; j < N ; j++) m[i][j] = rand()%10;
	}
	return;
} 
void *func(void *args)
{
	long geti = (long)args%N;
	long getj = (long)args/N;
	sem_wait(&Mut);
	printf("In Critical Section!\n");
	ans[geti][getj] = m1[geti][getj] + m2[geti][getj];
	printf("Timer Started!\n");
	alarm(5);
}
void Timer()
{
	printf("Timer Ended!\n");
	sem_post(&Mut);
}
int main()
{
	populateArray(m1);
	populateArray(m2);
	
	signal(SIGALRM, Timer);
	
	sem_init(&Mut, 0, 1);
	pthread_t t[N];
	
	for(long i = 0 ; i < N ; i++) pthread_create(&t[i], NULL, func, (void*)i);
	for(long i = 0 ; i < N ; i++) pthread_join(t[i], NULL);
	return 0;
}
