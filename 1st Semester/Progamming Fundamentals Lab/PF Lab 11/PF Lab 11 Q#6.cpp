#include <stdio.h>
#include <string.h>
int *WordCount(char *Text, int *size);
int count = 1;
int main()
{
	char sentence[100];
	int size,*counter;
	int *(*ptr)(char* , int*);
	ptr = WordCount;
	printf("Enter a String: ");
	gets(sentence);
	size = strlen(sentence);
	counter = ptr(sentence , &size);
	printf("You have entered %s\nTHERE ARE %d WORDS IN THE STRING",sentence,*counter);
}
int *WordCount(char *Text, int *size)
{
	for (int i = 0 ; i < *size ; i++)
	{
		if ( *(Text + i) == ' ')
		{
			count++;
		}
	}
	return &count;
}
