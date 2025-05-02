#include <stdio.h>
#include <mpi.h>

#define N 100000

int main(int argc, char** argv)
{	
	MPI_Init(&argc, &argv);
	
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int sendarr[N];
	int recvarr[N];
	double t1 = MPI_Wtime();
	
	MPI_Sendrecv(sendarr, N, MPI_INT, !rank, 0, recvarr, N, MPI_INT, !rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	
	double t2 = MPI_Wtime();
	if(!rank) printf("Time Taken: %f\n", t2-t1);
	MPI_Finalize();
}
