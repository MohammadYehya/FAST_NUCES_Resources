#include <stdio.h>
int main()
{
	int a,b,c;
	for (a = -10 ; a <= 10 ; a++)
	{
		for (b = -10 ; b <= 10 ; b++)
		{
			for (c = -10 ; c <= 10 ; c++)
			{
				if (3*a+7*b-5*c == 10)
				{
					printf("Solution: %d %d %d\n",a,b,c);
				}
			}
		}
	}
	
}

