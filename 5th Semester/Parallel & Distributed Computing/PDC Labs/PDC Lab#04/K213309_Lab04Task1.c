#include <stdio.h>
#include <omp.h>
#include <stdlib.h>	//For rand() function
#include <time.h>	//For time based seed for pseudo-random generation

#define N 128
void printArr(int arr[][N])
{
	for(int i = 0; i < N; i++) {for(int j = 0; j < N; j++) printf("%d ", arr[i][j]); printf("\n");}
}
int main()
{
	srand(time(NULL));
	int a[N][N], b[N][N], c[N][N] = {0};			//Creating arrays a, b, c where c = a*b
	#pragma omp parallel shared(a, b, c)			//Start of parallel region
	{
		#pragma omp sections				//Start of parallel sections
		{
			#pragma omp section
			{
								//For loop in serial due to nested directives not allowed
								//To solve issue set environment variable OMP_NESTED to true
				for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) a[i][j] = rand()%10;
			}
			#pragma omp section
			{
								//For loop in serial due to nested directives not allowed
								//To solve issue set environment variable OMP_NESTED to true
				for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) b[i][j] = rand()%10;
			}
		}
		
		#pragma omp barrier				//Wait for all threads and go when arrays are initialized
		
		#pragma omp for collapse(3)			//Start of Multiplication, 3 parallel for loops(since collapse in used)
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				for(int k = 0; k < N; k++)
				{
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
	}
	printArr(a);printf("\n");
	printArr(b);printf("\n");
	printArr(c);
}
