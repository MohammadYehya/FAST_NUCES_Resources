#include <stdio.h>
void SortFunction(int *arr, int *size, int order);
int main()
{
	int n,ord;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[n];
	for (int i = 0 ; i < n ; i++)
	{
		printf("Enter value of element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	do
	{
		printf("Enter 1 for Asscending order and 2 for Descending order: ");
		scanf("%d",&ord);
	}
	while (ord != 1 && ord != 2);
	SortFunction(a,&n,ord);
	printf("After sorting: \n");
	for (int j = 0 ; j < n ; j++)
	{
		printf("Value at postion %d: %d\n",j+1,a[j]);
	}
}
void SortFunction(int *arr, int *size, int order)
{
	int temp;
	for (int i = 0 ; i < *size ; i++)
	{
		for (int j = i ; j < *size ; j++)
		{
			if (order == 1)
			{
				if (*(arr+j) > *(arr+j+1))	
				{
					temp = *(arr+j);
					*(arr+j) = *(arr+j+1);
					*(arr+j+1) = temp;
				}
			}
			else if (order == 2)
			{
				if (*(arr+j) < *(arr+j+1))	
				{
					temp = *(arr+j);
					*(arr+j) = *(arr+j+1);
					*(arr+j+1) = temp;
				}
			}
		}
	}
}

