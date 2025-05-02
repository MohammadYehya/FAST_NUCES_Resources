#include <stdio.h>
#include <mpi.h>

#define N 100
int main(int argc, char** argv)
{
	int rank, size;
	int fact;
	int lower,upper;
	int i;
	double local_result = 1.0;
	double total;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	double t1, t2;
	if(!rank)
	{
		fact = N;
		t1 = MPI_Wtime();
	}

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Bcast(&fact, 1, MPI_INT, 0,MPI_COMM_WORLD); 

	if(!rank) lower = 1;
	else lower = rank * (fact / size) + 1;
	if(rank==(size-1)) upper = fact;
	else upper = (rank + 1) * (fact / size);

	for(i=lower;i<=upper;i++) local_result = local_result * (double)i;

	MPI_Reduce(&local_result, &total, 1, MPI_DOUBLE, MPI_PROD, 0, MPI_COMM_WORLD);
	t2 = MPI_Wtime();

	if(!rank) printf("%d! = %lf\n%d processes used!\nTime Taken = %f\n", fact, total, size, t2-t1);

	MPI_Finalize();
	
	return 0;
}
