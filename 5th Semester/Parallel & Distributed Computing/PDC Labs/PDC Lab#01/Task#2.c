/*Task#2: Write a program in openMP C to increase the array size from 1000, 3000,
5000.....10000 in Example#2 with increasing chunk size in static and dynamic scheduling.
Calculate the time of both scheduling with chunk size 1 and 2 and compare their performance.*/

#include <stdio.h>
#include <omp.h>
#include <string.h>

int SIZE;
int chunk;

int main(int argc, char* argv[], char* envp[]) 
{
	//Making sure that user has entered a command line argument. i.e. an integer that represents the size of an array.
	if(argc != 4)
	{
		printf("Please Enter 3 Arguments!{In the format ./T ArraySize ScheduleChunk ScheduleType}!\n");
		return 1;
	}	
	
	//Converting the command line argument from a string to an integer via sscanf function
	sscanf(argv[1], "%d", &SIZE);
	
	//Validating size of arrays
	if(SIZE <= 0)
	{
		printf("Invalid Size Entered! Size entered must be greater than 0!\n");
		return 2;
	}
	
	//Converting the command line argument from a string to an integer via sscanf function
	sscanf(argv[2], "%d", &chunk);
	
	//Validating parallel chunk size
	if(chunk <= 0)
	{
		printf("Invalid Chunk Size Entered! Chunk Size entered must be greater than 0!\n");
		return 3;
	}
	
	//Validating the Schedule Type to either b STATIC or DYNAMIC
	if(strcmp(argv[3], "STATIC") && strcmp(argv[3], "DYNAMIC"))
	{
		printf("Invalid Schedule Type! Please enter either STATIC or DYNAMIC! {Make sure capitalized}\n");
		return 4;
	}
	
	int arr[SIZE];
	int sum = 0;
	printf("Array:\n");
	for(int i = 0; i < SIZE; i++) {arr[i] = i+1;}// printf("%d\t",arr[i]);}
	printf("\n");
	
	double t1, t2;
	
	//User choice to pick either STATIC or DYNAMIC
	if(strcmp(argv[3], "STATIC"))
	{
		t1 = omp_get_wtime();
		#pragma omp parallel for schedule(static,chunk) reduction(+:sum)
		for(int i = 0; i < SIZE; i++) sum += arr[i];
		t2 = omp_get_wtime();
	}
	else if(strcmp(argv[3], "DYNAMIC"))
	{
		t1 = omp_get_wtime();
		#pragma omp parallel for schedule(dynamic,chunk) reduction(+:sum)
		for(int i = 0; i < SIZE; i++) sum += arr[i];
		t2 = omp_get_wtime();
	}
	
	//Display of results
	printf("Sum: %d\nTime Taken to Calculate: %f\n", sum, t2-t1);
	return 0;
}
