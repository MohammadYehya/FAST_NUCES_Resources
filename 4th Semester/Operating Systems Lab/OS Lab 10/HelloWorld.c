#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
	printf("OpenMP running with %d threads\n",omp_get_max_threads());
	#pragma omp parallel
	{
		printf("Hello World from thread %d\n",omp_get_thread_num());
	}
}
