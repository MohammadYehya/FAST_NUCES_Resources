#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	MPI_Init(&argc, &argv);
	
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	long NumberOfPoints = 1000000, local_points = NumberOfPoints/size, localInside = 0;
	
	srand(time(NULL) + rank);
	for(long i = 0; i < local_points; i++)
	{
		double x = (double)rand()/RAND_MAX;
		double y = (double)rand()/RAND_MAX;
		double dist = sqrt(x*x + y*y);
		
		if(dist <= 1) localInside++;
	}
	
	long GlobalInside = 0;
	MPI_Reduce(	&localInside,		//sendbuf
	 		&GlobalInside, 		//recvbuf
	 		1, 			//count of values in sendbuf
	 		MPI_LONG, 		//MPI_DATATYPE of sendbuf
	 		MPI_SUM, 		//MPI_OP operator
	 		0, 			//Rank of Root process
	 		MPI_COMM_WORLD		//Communicator
	 	);
	/*
		MPI_Reduce Operators(MPI_OP):
			-> MPI_MAX	- Returns the maximum element.
			-> MPI_MIN	- Returns the minimum element.
			-> MPI_SUM	- Sums the elements.
			-> MPI_PROD	- Multiplies all elements.
			-> MPI_LAND	- Performs a logical and across the elements.
			-> MPI_LOR	- Performs a logical or across the elements.
			-> MPI_BAND	- Performs a bitwise and across the bits of the elements.
			-> MPI_BOR	- Performs a bitwise or across the bits of the elements.
			-> MPI_MAXLOC	- Returns the maximum value and the rank of the process that owns it.
			-> MPI_MINLOC	- Returns the minimum value and the rank of the process that owns it.
	*/
	if(rank == 0)
	{
		double pi = 4 * ((double)(GlobalInside))/NumberOfPoints;
		printf("Estimated Pi: %f\n", pi);
	}
	MPI_Finalize();
}
