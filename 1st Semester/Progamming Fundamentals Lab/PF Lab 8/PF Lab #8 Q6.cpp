#include <stdio.h>
int main()
{
	int num,digits[9999],sum=0;
	do
	{
		printf("Please enter a number that has 4 or more digits: ");
		scanf("%d",&num);
	}
	while(num < 1000);
	while (num > 0)
	{
		sum = sum + num%10;
		num = num/10;
	}
	printf("The sum of the individual digits is: %d",sum);
}

