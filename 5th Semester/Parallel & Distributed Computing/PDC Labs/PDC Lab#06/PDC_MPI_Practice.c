#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv)
{
	int rank, size;
	MPI_Init(&argc, &argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	/*
		1.Barrier
			Definition:	Acts like a wall for all nodes to get to one same point and then releases all nodes.
			Command:	int MPI_Barrier(MPI_Comm comm)
	*/
	if(rank != 0) printf("Rank %d before barrier\n", rank);
	MPI_Barrier(MPI_COMM_WORLD);
	if(rank == 0) printf("Rank 0 after barrier\n");
	MPI_Barrier(MPI_COMM_WORLD);
	
	
	
	/*
		2.Broadcast
			Definition:	Broadcasts a message from the root process to all other processes of the same communicator.
			Command:	int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
	*/
	MPI_Barrier(MPI_COMM_WORLD);
	char sendstring[100] = "";
	if(rank == 0)
	{
		strcpy(sendstring, "[Parallel and Distributed Computing] this is being broadcasted!");
	}
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Bcast(&sendstring, 100, MPI_CHAR, 0, MPI_COMM_WORLD);
	printf("Rank %d: %s\n", rank, sendstring);
	MPI_Barrier(MPI_COMM_WORLD);
	
	
	/*
		3.Reduction
			Definition:	Reduces values on all processes to a single value 
			Command:	int MPI_Reduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm)
	*/
	MPI_Barrier(MPI_COMM_WORLD);
	int sum = 0;
	MPI_Reduce(&rank, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if(rank == 0) printf("Sum: %d\n", sum);
	MPI_Barrier(MPI_COMM_WORLD);
	
	
	
	/*
		4.Prefix
			Definition:	Performs a prefix reduction across all MPI processes in the given communicator
			Command:	int MPI_Scan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
	*/
	MPI_Barrier(MPI_COMM_WORLD);
	sum = 0;
	MPI_Scan(&rank, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	printf("Rank %d Sum: %d\n", rank, sum);
	MPI_Barrier(MPI_COMM_WORLD);
	
	
	
	/*
		5.Gather
			Definition:	Gathers together values from a group of processes
			Command:	int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
	*/
	MPI_Barrier(MPI_COMM_WORLD);
	sum = rank*10;
	int buffer[size];
	if(rank == 0)
	{
		MPI_Gather(&sum, 1, MPI_INT, buffer, 1, MPI_INT, 0, MPI_COMM_WORLD);
		for(int i = 0; i < size; i++) printf("Buffer[%d] = %d\n", i, buffer[i]);
	}
	else
	{
		MPI_Gather(&sum, 1, MPI_INT, NULL, 0, MPI_INT, 0, MPI_COMM_WORLD);
	}
	MPI_Barrier(MPI_COMM_WORLD);
	
	
	
	/*
		6.Scatter
			Definition:	Sends data from one process to all other processes in a communicator
			Command:	int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
	*/
	MPI_Barrier(MPI_COMM_WORLD);
	if(rank == 0)
	{
		int buffer[size];
		for(int i = 0; i < size; i++) buffer[i] = i*10;
		MPI_Scatter(&buffer, 1, MPI_INT, &sum, 1, MPI_INT, 0, MPI_COMM_WORLD);
	}
	else
	{
		MPI_Scatter(NULL, 1, MPI_INT, &sum, 1, MPI_INT, 0, MPI_COMM_WORLD);
	}
	printf("Rank %d: Scatter_Value: %d\n", rank, sum);
	MPI_Barrier(MPI_COMM_WORLD);
	
	
	
	/*
		7.Alltoall
			Definition:	Sends data from all to all processes 
			Command:	int MPI_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
	*/
	MPI_Barrier(MPI_COMM_WORLD);
	int myvalues[size*3];
	for(int i = 0; i < size*3; i++) myvalues[i] = rank * 3 + i;
	
	int recvbuffer[size];
	
	MPI_Alltoall(&myvalues, 1, MPI_INT, recvbuffer, 1, MPI_INT, MPI_COMM_WORLD);
	
	printf("Rank %d : ", rank);
	for(int i = 0; i < size; i++) printf("%d ", recvbuffer[i]); printf("\n");
	
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
}
