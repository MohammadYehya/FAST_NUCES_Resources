#include <stdio.h>
int main()
{
	//Q1
	int num,count=0;
	printf("Please enter any number: ");
	scanf("%d",&num);
	printf("The Factors are: ");
	for (int i = 1 ; i <= num ; i++)
	{
		if (num%i == 0 )
		{
			printf("%d ",i);
			count++;
		}
	}
	if (count == 2)
	{
		printf("\nIt is a prime number!");
	}
}

