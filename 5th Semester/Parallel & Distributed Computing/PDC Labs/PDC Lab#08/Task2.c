#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

#define N 10000

int main(int argc, char** argv)
{
	MPI_Init(&argc, &argv);
	
	int rank, size;
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int arr[N];
	srand(time(NULL));
	if(!rank)
	{
		for(int i = 0; i < N; i++)
			arr[i] = rand()%100000;
	}
	MPI_Scatter(&arr, N/size, MPI_INT, &arr, N/size, MPI_INT, 0, MPI_COMM_WORLD);
	
	int localmax = 0;
	for(int i = 0; i < N/size; i++)
		if(localmax < arr[i]) localmax = arr[i];
		
	printf("Rank [%d] -> Local Max : %d\n", rank, localmax);
	MPI_Barrier(MPI_COMM_WORLD);
	int val = -1;
	MPI_Reduce(&localmax, &val, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
	
	if(!rank) printf("Max = %d.\n", val);
	
	MPI_Finalize();
}

