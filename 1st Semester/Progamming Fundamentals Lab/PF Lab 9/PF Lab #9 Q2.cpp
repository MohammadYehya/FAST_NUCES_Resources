#include <stdio.h>
#include <string.h>
void printcaps(int a[1000]);
void printlows(int a[1000]);
int main()
{
	int freq[1000] = {0},i;
	char name[100],course1[100],course2[100];
	printf("Enter your name: ");
	gets(name);
	for (i = 0 ; i < strlen(name) ; i++)
	{
		freq[name[i]]++;
	}
	printf("Enter your first course: ");
	gets(course1);
	for (i = 0 ; i < strlen(course1) ; i++)
	{
		freq[course1[i]]++;
	}
	printf("Enter your second course: ");
	gets(course2);
	for (i = 0 ; i < strlen(course2) ; i++)
	{
		freq[course2[i]]++;
	}
	printcaps(freq);
	printlows(freq);
}
void printcaps(int a[1000])
{
	int j;
	for (j = 65 ; j < 91 ; j++)
	{
		if (a[j] != 0)
		{
			printf("The character %c occured %d times\n",j,a[j]);
		}
	}
}
void printlows(int a[1000])
{
	int j;
	for (j = 97 ; j < 123 ; j++)
	{
		if (a[j] != 0)
		{
			printf("The character %c occured %d times\n",j,a[j]);
		}
	}
}
