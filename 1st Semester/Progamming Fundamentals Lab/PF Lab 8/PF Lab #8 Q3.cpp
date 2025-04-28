#include <stdio.h>
int main()
{
	int posisum=0,negsum=0,n[6],i;
	for (i = 1 ; i<= 6 ; i++)
	{
		printf("Please enter a number: ");
		scanf("%d",&n[i]);
		if (n[i] > 0)
		{
			posisum = posisum + n[i];
		}
		else if (n[i] < 0)
		{
			negsum = negsum + n[i];
		}
	}
	printf("The sum of all postive numbers is: %d\n",posisum);
	printf("The sum of all negative numbers is: %d\n",negsum);
	printf("The sum of all numbers is: %d",posisum+negsum);
}

