#include <stdio.h>
#include <omp.h>

#define N 1000

int main()
{
	int i; float a[N], b[N], c[N];
	for(i = 0; i < N; i++) a[i] = b[i] = i;
	#pragma omp parallel shared(a, b, c) private(i)
	{
		#pragma omp sections
		{
			#pragma omp section
			{
				for(i = 0; i < N/2; i++) c[i] = a[i] + b[i];
			}
			#pragma omp section
			{
				for(i = N/2; i < N; i++) c[i] = a[i] + b[i];
			}
		}
	}
	for(i = 0; i < N; i++) printf("%f\n", c[i]);
}
