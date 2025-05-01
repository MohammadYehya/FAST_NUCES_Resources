#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char *argv[]) 
{
	if(argc != 3){printf("Argument Error! Enter two numbers! %s 1.5 10)\n",argv[0]); return -1;}
	int n = atoi(argv[2]);
	double x = atof(argv[1]);
	double r = 0.0, s = 1.0, p = 1.0, f = 1.0;

	#pragma omp parallel for reduction(+:r) reduction(*:s) reduction(*:p) reduction(*:f)
	for (int i = 0; i < n; i++) {
		r += s * p * x / f;
		s *= -1.0;
		p *= x * x;
		f *= (2 * i + 2) * (2 * i + 3);
	}
	printf("Taylor series approximation of sin(%f) with n = %d : %f\n", x, n, r);
}

