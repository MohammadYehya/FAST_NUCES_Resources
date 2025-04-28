#include <stdio.h>
int main()
{
	int arr[10],pos=0,neg=0,zero=0;
	for (int i = 1 ; i <= 10 ; i++)
	{
		printf("Please enter a number %d: ",i);
		scanf("%d",&arr[i]);
		if (arr[i] > 0)
		{
			pos++;
		}
		else if (arr[i] < 0)
		{
			neg++;
		}
		else zero++;
	}
	printf("The number of positive numbers is: %d\n",pos);
	printf("The number of negative numbers is: %d\n",neg);
	printf("The number of zeros is: %d",zero);
}

