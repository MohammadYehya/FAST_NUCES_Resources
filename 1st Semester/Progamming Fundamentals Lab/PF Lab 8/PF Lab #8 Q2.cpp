#include <stdio.h>
int main()
{
	int i;
	float arr[6];
	for (i = 1 ; i <= 5 ; i++)
	{
		printf("Please enter a number: ");
		scanf("%f",&arr[i]);
	}
	for (i = 5 ; i >= 1 ; i--)
	{
		printf("%0.2f\n",arr[i]);
	}
}

