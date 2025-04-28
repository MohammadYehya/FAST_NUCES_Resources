#include <stdio.h>
#include <math.h>
int main()
{
	float interest, principle, rate, years, times_year;
	for (int i=1 ; i<=10 ; i++)
	{
		printf("Entry number %d\n",i);
		printf("Please enter the principle amount: ");
		scanf("%f",&principle);
		printf("Please enter the rate of the interest: ");
		scanf("%f",&rate);
		printf("Please enter the number of years: ");
		scanf("%f",&years);
		printf("Please enter the times per year: ");
		scanf("%f",&times_year);
		interest = principle * pow((1+0.01*rate/times_year),years*times_year);
		printf("The interest after compounding is: %f\n\n",interest);
	}
}

