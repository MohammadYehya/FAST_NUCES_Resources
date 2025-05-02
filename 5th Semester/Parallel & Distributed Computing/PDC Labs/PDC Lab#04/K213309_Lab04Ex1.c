#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

const int dim = 2;
void print(int arr[dim][dim])
{
	for(int i =0 ; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
	printf("\n\n");
}
void populate(int arr[dim][dim])
{
	for(int i =0 ; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
			arr[i][j] = rand()%10;
	}
}
int main()
{
	srand(time(NULL));
	int i, k ,j, a[dim][dim], b[dim][dim], c[dim][dim];
	populate(a);
	populate(b);
	#pragma omp parallel for shared(a, b, c, dim) num_threads(2)
	for(i = 0; i < dim; i++)
	{
		#pragma omp parallel for shared(a, b, c, dim) num_threads(2)
		for(j = 0; j < dim; j++)
		{
			#pragma omp parallel for shared (a, b, c, dim) num_threads(2)
			for(k = 0; k < dim; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	print(a);
	print(b);
	print(c);
}
