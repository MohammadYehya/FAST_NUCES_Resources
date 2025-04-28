#include <stdio.h>
int main()
{
	int n,i,j,k = 1;
	printf("Enter number of rows: ");
	scanf("%d",&n);
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= i ; j++)
		{
			printf("%d ",k++);
		}
		printf("\n");
	}
	printf("Enter number of rows: ");
	scanf("%d",&n);
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= i ; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	printf("Enter number of rows: ");
	scanf("%d",&n);
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= n ; j++)
		{
			printf("%d ",i);
		}
		printf("\n");
	}
}

