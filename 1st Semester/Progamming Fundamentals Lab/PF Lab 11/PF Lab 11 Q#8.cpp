#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char *ptr;
	int N;
	printf("Enter the total number of characters in your name {First Name + Last Name}: ");
	scanf("%d",&N);
	char name[N];
	printf("Enter name: ");
	getchar();
	gets(name);
	ptr = (char*)calloc(N,sizeof(char));
	strcpy(ptr,name);
	printf("The string entered dynamically is: \n");
	for (int j = 0 ; j < N ; j++)
	{
		printf("%c",*(ptr + j));
	}
}

