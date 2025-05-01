#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define N 20
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
int main()
{
	
	int m1[N][N], m2[N][N], ans[N][N];
	double t1,t2;
	populateArray(m1);
	populateArray(m2);
	
	//Serial Section
	int i,j;
	t1 = omp_get_wtime();
	for(i = 0; i < N ; i++)
	{
		for(j = 0 ; j < N ; j++)
		{
			ans[i][j] = m1[i][j] + m2[i][j];
		}
	}
	t2 = omp_get_wtime();
	printf("Time Taken for Serial: %f\n",t2-t1);
	
	//Parallel Section
	#pragma omp parallel num_threads(N*N)
	{
		int geti = omp_get_thread_num()%N;
		int getj = omp_get_thread_num()/N;
		t1 = omp_get_wtime();
		ans[geti][getj] = m1[geti][getj] + m2[geti][getj];
		t2 = omp_get_wtime();
	}
	printf("Time Taken for Parallel: %f\n",t2-t1+0.000001);//0.000001 for overhead
}
