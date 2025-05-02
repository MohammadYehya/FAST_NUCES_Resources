#include <stdio.h>
#include <mpi.h>

#define N 100000

int main(int argc, char** argv)
{	
	MPI_Init(&argc, &argv);
	
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	double t1 = MPI_Wtime();
	if(!rank)
	{
		int Sendarr[N];
		for(int i = 1; i < size; i++) MPI_Send(Sendarr, N, MPI_INT, i, 0, MPI_COMM_WORLD);
	}
	else
	{
		int Recvarr[N];
		MPI_Recv(Recvarr, N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}
	
	double t2 = MPI_Wtime();
	if(!rank) printf("Time Taken: %f\n", t2-t1);
	MPI_Finalize();
}
