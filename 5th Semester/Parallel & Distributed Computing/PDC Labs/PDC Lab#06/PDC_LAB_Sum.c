#include <stdio.h>
#include <mpi.h>
int main(int argc, char ** argv)
{
	int myid, totalprocs;
	int sum = 0,startval,endval, accum;
	
	MPI_Status status;
	MPI_Init(&argc, &argv);
	
	MPI_Comm_size(MPI_COMM_WORLD, &totalprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	double t1 = MPI_Wtime();
	for(int i = 1; i <= 1000; i++) sum += i;
	if(myid != 0) MPI_Send(&sum,1,MPI_INT,0,1,MPI_COMM_WORLD);
	else
	{
		for(int j=1; j < totalprocs; j ++)
		{
			MPI_Recv(&accum, 1, MPI_INT, j, 1, MPI_COMM_WORLD, &status);
			sum += accum;
		}
	}
	if(myid == 0) 
	{
		double t2 = MPI_Wtime();
		printf("The sum from 1 to 1000 is : %d\n", sum);
		printf("Time Taken: %f\n", t2-t1);
	}
	MPI_Finalize();
}
