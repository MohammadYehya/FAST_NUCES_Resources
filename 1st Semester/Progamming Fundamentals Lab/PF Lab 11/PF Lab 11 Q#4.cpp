#include <stdio.h>
int main()
{
	int n;
	printf("Enter how many numbers you want to enter: ");
	scanf("%d",&n);
	int arr[n],*ptr = arr , min = 9999 ,max = -9999;
	for (int i = 0 ; i < n ; i++)
	{
		printf("Enter value at postion %d: ",i+1);
		scanf("%d",ptr + i);
		if (*(ptr + i) > max)
		{
			max = *(ptr + i);
		}
		if (*(ptr + i) < min)
		{
			min = *(ptr + i);
		}
	}
	printf("The Min is: %d\nThe Max is: %d",min,max);
}

