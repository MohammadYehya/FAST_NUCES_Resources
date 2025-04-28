#include <stdio.h>
int main()
{
	int n;
	printf("Enter how many numbers you want to enter: ");
	scanf("%d",&n);
	int arr[n],*ptr = arr , sum;
	for (int i = 0 ; i < n ; i++)
	{
		printf("Enter value at postion %d: ",i+1);
		scanf("%d",&arr[i]);
		sum += *(ptr + i);
	}
	printf("The Sum is: %d",sum);
}

