#include <stdio.h>
#include <math.h>
int main()
{
	printf("The special number(s) is/are : ");
	for (int i = 100; i<=170; i++)
	{
		if (i == pow(i/100,3)+pow(i%100/10,3)+pow(i%10,3))
		{
			printf("%d ",i);
		}
	}
}

