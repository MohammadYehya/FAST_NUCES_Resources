#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{
	if (argc != 2) 
	{
		printf("Error! Please enter a number! %s 10\n",argv[0]);
		return -1;
	}
	else 
	{
		int n = atoi(argv[1]);
		//Without Omp
		double x = 0;
		double t1 = omp_get_wtime();
		for(double i = 1 ; i <= n; i++) x+= 1/i;
		double t2 = omp_get_wtime();
		printf("Without OMP: \t%f\nValue: \t%f\n",t2-t1,x);
		
		//With Omp
		x = 0;
		#pragma omp parallel num_threads(n) reduction(+:x)
		{
			t1 = omp_get_wtime();
			x += (float)(1/(float)(omp_get_thread_num()+1));
			t2 = omp_get_wtime();
		}
		printf("With OMP: \t%f\nValue: \t%f\n",t2-t1+0.000001,x);//0.000001 for overhead cost
	}
}
