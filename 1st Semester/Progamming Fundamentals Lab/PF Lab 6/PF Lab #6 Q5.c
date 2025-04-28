#include <stdio.h>
int main()
{
	int num1=0,num2=0;
	if(!num1 && !num2)
	{
		printf("True");
	}
	if (!num1 && num2){}
	else
	{
		printf("\nFalse");
	}
	if (num1 || !num2)
	{
		printf("\nTrue");
	}
	
}
