#include <stdio.h>
#include <omp.h>

#define N 800000
#define ThreadAmount 8

int main()
{
	long arr[N], totsum = 0;
	long sum[ThreadAmount] = {0};
	for(int i = 0 ; i < N; i++)
		arr[i] = i;
	#pragma omp parallel num_threads(ThreadAmount) reduction(+:totsum)
	{
		#pragma omp for
		for(int i = 0; i < N; i++)
		{
			sum[omp_get_thread_num()] += arr[i];
		}
		printf("THREAD[%d] Sum: %ld\n", omp_get_thread_num(), sum[omp_get_thread_num()]);
		
		totsum += sum[omp_get_thread_num()];
	}
	printf("Total Sum: %ld\n",totsum);		
}
