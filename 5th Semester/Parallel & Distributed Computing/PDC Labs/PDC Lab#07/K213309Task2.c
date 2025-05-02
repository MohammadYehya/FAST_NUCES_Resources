#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv)
{
	MPI_Init(&argc, &argv);
	
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	double t1,t2;
	if(size == 2)
	{
		t1 = MPI_Wtime();
		if(!rank)
		{
			char str[] = "K213309";
			MPI_Send(str, sizeof(str), MPI_CHAR, 1, 3309, MPI_COMM_WORLD);
		}
		else
		{
			char str[10];
			MPI_Recv(str, sizeof(str), MPI_CHAR, 0, 3309, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("%s\n", str);
		}
		
	}
	else printf("Error: [Size != 2]\n");
	
	t2 = MPI_Wtime();
	printf("Rank %d Time Taken: %f\n", rank, t2-t1);
	MPI_Finalize();
}
