#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char** argv)
{
	MPI_Init(&argc, &argv);
	
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	long long num_points = 1000000, local_points = num_points/ size, local_inside = 0;
	double t1 = MPI_Wtime();
	
	srand(time(NULL) + rank);
	
	for(long long i = 0; i < local_points; i++)
	{
		double x = (double)rand()/RAND_MAX;
		double y = (double)rand()/RAND_MAX;
		double distance = sqrt(x*x + y*y);
		if(distance <= 1.0) 
		{
			local_inside++;
			//printf("X: %f Y: %f\n", x, y);
		}
	}
	
	long long global_inside;
	MPI_Reduce(&local_inside, &global_inside, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
	if(rank == 0)
	{
		double pi_estimate = 4.0 * global_inside/num_points;
		double t2 = MPI_Wtime();
		printf("Estimated Pi: %f\nEstimated in %f time\n", pi_estimate, t2-t1);
	}
	MPI_Finalize();
	return 0;
}
