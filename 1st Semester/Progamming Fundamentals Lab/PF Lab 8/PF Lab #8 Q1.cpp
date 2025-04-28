#include <stdio.h>
int main()
{
	int n,i,a[10],count=0;
	for (i = 1 ; i <= 10 ; i++)
	{
		printf("Please enter a number to store in the array at position No.%d: ",i);
		scanf("%d",&a[i]);
	}
	printf("Please enter a number to search in the array: ");
	scanf("%d",&n);
	for (i = 1 ; i <= 10 ; i++)
	{
		if (a[i]==n)
		{
			count++;
		}
	}
	if (count == 0)
	{
		printf("Number not found!");
	}
	else
	{
		printf("The number %d has occured %d times.",n,count);
	}
}

