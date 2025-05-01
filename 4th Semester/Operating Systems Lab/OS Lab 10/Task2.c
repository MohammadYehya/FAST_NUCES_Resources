#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 4

void populateArray(int m[N][N])
{
	int i,j;
	for(i = 0 ; i < N; i++)
	{
		for(j = 0 ; j < N ; j++)
		{
			m[i][j] = rand()%10;
		}
	}
	return;
} 
void printArray(int m[N][N])
{
	int i,j;
	for(i = 0 ; i < N; i++)
	{
		printf("|");
		for(j = 0 ; j < N ; j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("|\n");
	}
	printf("\n");
}
int main(int argc, char *argv[])
{
	srand(time(NULL));
	
	int m1[N][N], m2[N][N], ans[N][N] = {0};
	
	populateArray(m1);
	printArray(m1);
	populateArray(m2);
	printArray(m2);
		
	#pragma omp parallel num_threads(N*N)
	{
		for(int i = 0 ; i < N ; i++)
		{
			ans[omp_get_thread_num()%N][omp_get_thread_num()/N] += m1[omp_get_thread_num()%N][i] * m2[i][omp_get_thread_num()/N];
		}
	}
	printArray(ans);
}
