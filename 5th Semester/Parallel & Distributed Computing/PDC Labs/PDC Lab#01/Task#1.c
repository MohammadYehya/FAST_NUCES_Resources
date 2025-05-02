/*Task#1: You need to increase the array size from 1000, 3000, 5000.....10000 in Example#1. 
You need to create two threads, three threads and four threads to divide the task. 
Calculate the time increasing the size of an array. Construct a table to show your result.*/

#include <stdio.h>
#include <omp.h>

int SIZE;
	
void initArray(int *arr, int mul)
{
	for(int i = 0; i < SIZE; i++) arr[i] = mul * i;
}
void printArray(int *arr)
{
	for(int i = 0; i < SIZE; i++) printf("%d\t", arr[i]);
	printf("\n\n");
}

int main(int argc, char* argv[], char* env[])
{
	//Making sure that user has entered a command line argument. i.e. an integer that represents the size of an array.
	if(!(argc-1))
	{
		printf("Please enter an Argument!{In the format ./T ArraySize}\n");
		return 1;
	}	
	
	//Converting the command line argument from a string to an integer via sscanf function
	sscanf(argv[1], "%d", &SIZE);
	
	//Validating size of arrays
	if(SIZE <= 0)
	{
		printf("Invalid Number Entered! Number entered must be greater than 0!\n");
		return 2;
	}
	
	//Declaring Arrays of size "SIZE" which was provided by user in command line argument
	int arr1[SIZE];
	int arr2[SIZE];
	int res[SIZE];
	
	//Initializing arrays
	initArray(arr1, 1);
	initArray(arr2, 2);
	initArray(res, 0);
	
	//Performing experiment to calculate time taken for parallel execution 
	double t1 = omp_get_wtime();
	#pragma omp parallel for num_threads(4)		//threads performing in parallel 
	for(int i = 0; i < SIZE; i++)
	{
		res[i] = arr1[i] + arr2[i];
	}
	double t2 = omp_get_wtime();
	
	//Printing Arrays & results after execution of experiment
	printf("Array1:\n");printArray(arr1);
	printf("Array2:\n");printArray(arr2);
	printf("Res:\n");printArray(res);
	
	printf("Total Time Taken: %f Seconds\n",t2-t1);
	return 0;
}
