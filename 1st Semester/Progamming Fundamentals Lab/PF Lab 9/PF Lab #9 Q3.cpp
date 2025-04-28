#include <stdio.h>
#include <string.h>
int main()
{
	char choice1[100],choice2[100];
	printf("Enter the first string: ");
	gets(choice1);
	printf("Enter the second string: ");
	gets(choice2);
	if (strcmp(choice1,choice2) < 0)
	{
		printf("The second string is greater.");
	}
	else if (strcmp(choice1,choice2) > 0)
	{
		printf("The first string is greater.");
	}
	else 
	{
		printf("They are both equal.");
	}
}

