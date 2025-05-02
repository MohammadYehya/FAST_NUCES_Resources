#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INTERVAL 1000

int main()
{
	srand(time(NULL));
	double pi, origin;
	int circle = 0, square = 0;
	#pragma omp parallel num_threads(8)
	{
		double x, y;
		#pragma omp for
		for (int i = 0; i < (INTERVAL*INTERVAL); i++)
		{
			x = (double)(rand()%(INTERVAL+1))/INTERVAL;
			y = (double)(rand()%(INTERVAL+1))/INTERVAL;
			
			#pragma omp critical
			{
				origin = x*x + y*y;
				if (origin <= 1) circle++;
				square++;
				pi = (double)(4*circle)/square;
			}
			printf("x = %f\ty = %f\tpi = %f\n\n", x, y, pi);
		}
	}
	printf("\nFinal Estimation of Pi = %f\n", pi);
}
