#include <stdio.h>
#include <string.h>
int prime3(int i);
int main()
{
	char c[100];
	printf("Enter a string: ");
	gets(c);
	for (int i = 3 ; i < strlen(c) ; i++)
	{
		if (prime3(i) == 1)
		{
			c[i] = '$';
		}
	}
	printf("%s",c);
}
int prime3(int i)
{
	int c = 0;
	if(i%10 == 3)
	{
		for (int j = i ; j > 1 ; j--)
		{
			if (j%i == 0)
			{
				c++;
			}
		}
		if(c > 2){return 0;}
		else {return 1;}
	}
}
