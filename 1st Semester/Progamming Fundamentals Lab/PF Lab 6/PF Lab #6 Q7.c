#include <stdio.h>
int main()
{
	//Q7
	int num1,num2,num3;
	printf("Enter number 1: ");
	scanf("%d",&num1);
	printf("Enter number 2: ");
	scanf("%d",&num2);
	printf("Enter number 3: ");
	scanf("%d",&num3);
	if (num1 >= num2)
	{
		if (num1>=num3)
		{
			printf("%d",num1);
		}
		else 
		{
			printf("%d",num3);
		}
	}
	else
	{
		if (num2 >= num3)
		{
			printf("%d",num2);
		}
		else
		{
			printf("%d",num3);
		}
	}
}
