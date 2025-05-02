#include <stdio.h>
#include <mpi.h>
#include <time.h>
#include <stdlib.h>

#define N 630000
int main(int argc, char *argv[])
{
	srand(time(NULL));
	MPI_Status status;
	MPI_Init(&argc, &argv);
	
	int size, rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	long arr[N] = {0};
	if(!rank)		//Only Master Process will run this
	{
		for(int i = 0; i < N; i++) arr[i] = rand()%10;	//Init of arrays and sending them to slave processes
		for(int i = 0; i < size-1; i++) MPI_Send(arr, N, MPI_LONG, i+1, 0, MPI_COMM_WORLD);
	}
	else
	{
		MPI_Recv(arr, N, MPI_LONG, 0, 0, MPI_COMM_WORLD, &status);//Slave processes recieving the arrays
	}
	MPI_Barrier(MPI_COMM_WORLD);	
	int iSize = N / size;	//Chunk Size
	long localSum = 0;
	for(int i = 0; i < iSize; i++)
	{
		localSum += arr[i + iSize*rank];	//All processes calculating the local sum of array
	}
	long GlobalSum = 0;
	printf("Local Sum of Rank [%d] is: %ld\n", rank, localSum);
	MPI_Reduce(&localSum, &GlobalSum, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);//Using reduction to calculate total sum
	MPI_Barrier(MPI_COMM_WORLD);
	
	if(!rank)
	{
		printf("Global Sum is: %ld\n", GlobalSum);
	}
	MPI_Finalize();
}
