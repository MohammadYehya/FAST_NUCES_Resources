#include <stdio.h>
int main()
{
	int num;
	printf("Enter the number to find the multipacation table: ");
	scanf("%d",&num);
	for (int i=1 ; i<=10 ; i++)
	{
		printf("%d * %d = %d\n",num,i,num*i);
	}
}

