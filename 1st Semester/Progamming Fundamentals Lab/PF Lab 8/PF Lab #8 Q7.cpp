#include <stdio.h>
int main()
{
	int n,even=0,odd=0,sum=0;
	printf("Enter array size[1-100]: ");
	scanf("%d",&n);
	int arr[n];
	for (int i = 1 ; i <= n ; i++)
	{
		printf("Enter element %d: ",i);
		scanf("%d",&arr[i]);
		sum = sum + arr[i];
		if (arr[i]%2==0)
		{
			even++;
		}
		else odd++;
	}
	printf("Total Sum: %d\n",sum);
	printf("Even numbers: %d\n",even);
	printf("Odd numbers: %d\n",odd);
}

