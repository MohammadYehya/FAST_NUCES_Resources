#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>

#define N 100
int main(int argc, char* argv[])
{
	MPI_Status status;
	MPI_Init(&argc, &argv);
	
	int size, rank;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int A[N][N] = {0}, B[N][N] = {0}, C[N][N] = {0};
	if(!rank)//Only Master process will run this {i.e. Initialization of arrays and sending the arrays to the Slave Processes}
	{
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) A[i][j] = rand()%10;
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) B[i][j] = rand()%10;
		for(int i = 0; i < size-1; i++) MPI_Send(A, N*N, MPI_INT, i+1, 0, MPI_COMM_WORLD);
		for(int i = 0; i < size-1; i++) MPI_Send(B, N*N, MPI_INT, i+1, 0, MPI_COMM_WORLD);
	}
	else
	{
		MPI_Recv(A, N*N, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);//Slave processes recieving arrays
		MPI_Recv(B, N*N, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
	}
	MPI_Barrier(MPI_COMM_WORLD);
	
	int iSize = N / size;		//Chunk Size
	for(int i = 0; i < iSize; i++)
	{
		int idx = i + iSize*rank;
		for(int j = 0; j < N; j++)
		{
			for(int k = 0; k < N; k++)
			{
				C[idx][j] += A[idx][k] * B[k][j];
			}
		}
	}
	
	for(int i = 0; i < iSize; i++)	//All processes send their calculated values to Master Process{Node 0}
	{
		for(int j = 0; j < N; j++)
		{
			MPI_Send(&C[i + iSize*rank][j], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		}
	}
	
	if(!rank)
	{
		for(int i = iSize; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				MPI_Recv(&C[i][j], 1, MPI_INT, i/iSize, 0, MPI_COMM_WORLD, &status);//Master Process recieves values and stores them
			}
		}
	}
	MPI_Barrier(MPI_COMM_WORLD);
	if(!rank)
	{
		printf("A:\n");for(int i = 0; i < N; i++) {for(int j = 0; j < N; j++) printf("%d ", A[i][j]); printf("\n");}
		printf("B:\n");for(int i = 0; i < N; i++) {for(int j = 0; j < N; j++) printf("%d ", B[i][j]); printf("\n");}
		printf("C:\n");for(int i = 0; i < N; i++) {for(int j = 0; j < N; j++) printf("%d ", C[i][j]); printf("\n");}
	}
	MPI_Finalize();
}
