#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
	MPI_Init(&argc, &argv);
	
	int size, rank;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status s;
	
	if(!rank)
	{
		printf("[Rank 0]: Hello World!\n");
		for(int i = 1; i < size; i++)
		{
			MPI_Send(&i, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			for(int j = 0; j<1000000; j++);//Acts as a delay
		}
	}
	else
	{
		int x;
		MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &s);
		printf("[Rank %d]: Hello World!\n", x);
	}
	
	MPI_Finalize();
}
