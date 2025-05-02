#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv)
{
	MPI_Init(NULL, NULL);
	double t1 = MPI_Wtime();
	
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	int name_len;
	MPI_Get_processor_name(processor_name, &name_len);
	
	printf("Hello World From Processor %s, rank %d out of %d processors\n", processor_name, world_rank, world_size);
	
	double t2 = MPI_Wtime();
	printf("Total time taken for processor %d: %f\n",world_rank, t2-t1);
	MPI_Finalize();
}
