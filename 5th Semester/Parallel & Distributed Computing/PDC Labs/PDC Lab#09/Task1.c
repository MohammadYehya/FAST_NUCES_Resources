#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);
	
	int my_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	int total;
	MPI_Scan(&my_rank, &total, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	printf("[MPI process %d] Total = %d.\n", my_rank, total);
	MPI_Finalize();
	return EXIT_SUCCESS;
}
