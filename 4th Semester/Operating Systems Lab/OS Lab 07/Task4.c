#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define SIZE 20
#define THREADSIZE (SIZE/2)
#define STEPSIZE (SIZE/THREADSIZE)

struct ArrInfo
{
	int *ptr;
	int index0;
	int indexn;
	int sum;
};

void PopulateArray(int *arr)
{
	for(int i = 0 ; i < SIZE ; i++)
	{
		arr[i] = i;
	}
}
void PrintArray(int *arr)
{
	printf("ARRAY: ");
	for(int i = 0 ; i < SIZE ; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void *ArraySum(void *val)
{
	struct ArrInfo *x = (struct ArrInfo*)val;
	for (int i = x->index0 ; i < x->indexn && i < SIZE ; i++) x->sum += x->ptr[i];
	pthread_exit(0);
}

int main(int argc, char *argv[], char *envp[])
{
	int arr[SIZE];
	int sum = 0;
	struct ArrInfo x[THREADSIZE];
	pthread_t t[THREADSIZE];
	
	PopulateArray(arr);
	PrintArray(arr);
	printf("Number of Threads: %d\n",THREADSIZE);
	
	for(int i = 0 ; i < THREADSIZE ; i++)
	{
		x[i].ptr = arr;
		x[i].index0 = i * STEPSIZE;
		x[i].indexn = (i + 1) * STEPSIZE;
		x[i].sum = 0;
		pthread_create(&t[i], NULL, (void*)ArraySum, (void*)&x[i]);
	}
	for(int i = 0 ; i < THREADSIZE ; i++)
	{
		pthread_join(t[i], NULL);
		sum += x[i].sum;
	}
	if(SIZE%2)sum += arr[SIZE-1];
	printf("The sum of the array is: %d\n",sum);
}
