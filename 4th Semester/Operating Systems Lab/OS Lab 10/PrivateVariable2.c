#include <stdio.h>
#include <omp.h>

int main()
{
	int i;
	const int N = 1000;
	int a = 50;
	int b = 0;
	
	#pragma omp parallel for default(shared) private(i) private(a) private(b)
	for(i = 0 ; i < N ; i++)
	{
		b = a + i;
	}
	
	printf("a=%d b=%d (expected a=50 b=1049)\n", a, b);
}
