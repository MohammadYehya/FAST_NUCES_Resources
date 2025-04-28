#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	char (*ptr)[4][25]= (char*)malloc(1*sizeof(char));
	for (i = 0 ; i < 5 ; i++)
	{
		printf("Enter the name of student %d: ",i+1);
		scanf("%s",ptr[i]);
	}
	for (i = 0 ; i < 5 ; i++)
	{
		printf("The name of student no.%d: %s\n",i+1,ptr[i]);
	}
}

