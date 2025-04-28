#include <stdio.h>
int main()
{
	//Q1
	int num;
	do
	{
	printf("Please enter a 2 digit number: ");
	scanf("%d",&num);
	}
	while (num<0 || num>100);
	if ((num/10+num%10)%9==0)
	{
		printf("%d is divisible by 9",num);
	}
	else 
	{
		printf("%d is not divisble by 9",num);
	}
}
