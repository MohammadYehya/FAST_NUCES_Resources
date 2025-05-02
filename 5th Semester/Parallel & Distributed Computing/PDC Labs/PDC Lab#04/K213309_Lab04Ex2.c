#include <stdio.h>
#include <omp.h>
int main()
{
	int num_threads=0;
	
	num_threads = omp_get_num_threads();
	//omp_get_env is most probably a user defined function
	printf("Number of threads from environment variable: %d\n", num_threads);
	
	 omp_set_num_threads(4);
	 //omp_set_env is most probably a user defined function
	 printf("Number of threads set to 4\n");
	 
	 return 0;
}
