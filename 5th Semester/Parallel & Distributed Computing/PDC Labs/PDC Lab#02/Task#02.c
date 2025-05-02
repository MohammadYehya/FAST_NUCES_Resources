/*
	Task#2: Write a program in openMP C to solve the matrix addition. You can have two large
	number of matrices A and B say 16 x 16. You can divide them in 2x2 matrices and add them and
	place the answer in the resultant Matrix C. Each of 2x2 matrices will be solved by separate thread
	and their result storing in the resultant will be only saved via critical section.
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 16

void PopulateArray(int arr[][N])					//Function to populate an array with random values
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			arr[i][j] = rand()%100;
}
void PrintArray(int arr[][N])						//Function to print an array
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
	printf("\n\n");
}
int main(int agc, char* argv[], char* envp[])
{
	int A[N][N], B[N][N], C[N][N] = {0};
	PopulateArray(A);
	PopulateArray(B);
	
	PrintArray(A);
	PrintArray(B);
	PrintArray(C);
	
	#pragma omp parallel num_threads(8)				//Starting parallel region
	{
		#pragma omp for
		for(int i = 0; i < N/2; i++)				//Dividing rows by 2
		{
			for(int j = 0; j < N/2; j++)			//Dividing columns by 2
			{
				for(int k = 0 ; k < 4; k++)		//Since rows and columns are divided into 2 this creates the effect of a NxN matrix being divided into 2x2 matrices
				{
					#pragma omp critical		
					{
						C[2*i+k/2][2*j+k%2] = A[2*i+k/2][2*j+k%2] + B[2*i+k/2][2*j+k%2];
					}
				}
			}
		}
	}
	PrintArray(A);
	PrintArray(B);
	PrintArray(C);
}
