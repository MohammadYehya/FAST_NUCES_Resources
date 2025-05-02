#include <stdio.h>
#include <omp.h>

#define N 20

int main()
{
	int Fib[N] = {0};
	Fib[0] = 0;
	Fib[1] = 1;
	
	#pragma omp parallel for
	for(int i = 2 ; i < N; i++)
	{
		while((!Fib[i-1] || !Fib[i-2]) && i != 2);	//Lock used similarly to Peterson's Lock to wait until array populated at i-1 & i-2
		Fib[i] = Fib[i-1] + Fib[i-2];			//Calculating Fib[i]
	}
	
	printf("%d", Fib[0]);
	for(int i = 1 ; i < N; i++)
		printf(", %d", Fib[i]);
	printf("\n");
}
