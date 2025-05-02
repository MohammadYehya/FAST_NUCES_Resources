/*
	Task#3: Write a program in openMP C to generate the Binomial Coefficient Series. You can
	calculate the time of finding each coefficient separately.
*/

#include <stdio.h>
#include <omp.h>

int fact(int n)
{
	if(n > 0) return n*fact(n-1);					//Calculting factorial serially
	else return 1;
}
int main(int argc, char* argv, char* envp[])
{
	int BinCoef[100] = {0};						//Creating an array to store Binomial Coefficients
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	int upper = fact(n);
	#pragma omp parallel num_threads(8)				//Start of parallel region
	{
		#pragma omp for
		for(int i = 0; i < n+1; i++)
		{
			BinCoef[i] = upper/(fact(i)*fact(n-i));		//Binomial Coefficients are given as nCr = n!/(r!(n-r)!)
		}
	}
	for(int i = 0; i < n+1; i++) printf("%d ",BinCoef[i]);		//Printing Binomial Coefficients
	printf("\n");
}
