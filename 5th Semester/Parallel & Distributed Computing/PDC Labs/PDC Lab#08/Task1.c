#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) 
{
	int global_points;
	double pi_estimate;

	int rank, size;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int num_points = 10000;
	int points = 0;

	srand(rank);
	for (int i = 0; i < num_points; i++) 
	{
		double x = (double)rand() / RAND_MAX;
		double y = (double)rand() / RAND_MAX;
		double distance = x * x + y * y;
		if (distance <= 1.0) points++;
	}
	MPI_Reduce(&points, &global_points, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if (rank) printf("Rank [%d] calcualtes %d points inside circle.\n",rank,points);
	MPI_Barrier(MPI_COMM_WORLD);
	if (!rank) 
	{
		pi_estimate = 4.0 * global_points / (num_points * size);
		printf("Estimated value of Pi: %lf\n", pi_estimate);
	}

	MPI_Finalize();
}

