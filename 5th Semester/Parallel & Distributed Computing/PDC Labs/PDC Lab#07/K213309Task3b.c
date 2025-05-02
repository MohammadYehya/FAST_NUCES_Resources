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
		MPI_Request R;
		int Sendarr[N];
		for(int i = 1; i < size; i++) MPI_Isend(Sendarr, N, MPI_INT, i, 0, MPI_COMM_WORLD, &R);
	}
	else
	{
		int Recvarr[N];
		MPI_Request R;
		MPI_Irecv(Recvarr, N, MPI_INT, 0, 0, MPI_COMM_WORLD, &R);
	}
	
	double t2 = MPI_Wtime();
	if(!rank) printf("Time Taken: %f\n", t2-t1);
	MPI_Finalize();
}
