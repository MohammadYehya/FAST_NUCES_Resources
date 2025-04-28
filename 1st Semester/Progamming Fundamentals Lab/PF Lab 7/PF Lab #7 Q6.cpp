#include <stdio.h>
int main()
{
	int marks;
	char ans;
	while(true)
	{
	printf("Q1. What is 1+1=?\nA)1\nB)2\nC)3\nD)4\n");
	scanf(" %c",&ans);
	if (ans == 'B')
	{
		marks = marks + 4;
	}
	else marks--;
	
	printf("Q2. What is the value of pi?\nA)3.14\nB)2.71\nC)8.99\nD)8.01\n");
	scanf(" %c",&ans);
	if (ans == 'A')
	{
		marks = marks + 4;
	}
	else marks--;
	
	printf("Q3. What is the value of e?\nA)3.14\nB)2.71\nC)8.99\nD)8.01\n");
	scanf(" %c",&ans);
	if (ans == 'B')
	{
		marks = marks + 4;
	}
	else marks--;
	
	printf("Q4. What is the value of G?\nA)6.67*10^-11\nB)2.71\nC)8.99\nD)8.01\n");
	scanf(" %c",&ans);
	if (ans == 'A')
	{
		marks = marks + 4;
	}
	else marks--;
	
	if (marks == -4)
	{
		printf("Sorry,you did not qualify for the admission.");
		break;
	}
	
	printf("Q5. What is the value of Sin(90)?\nA)3\nB)2\nC)1\nD)0\n");
	scanf(" %c",&ans);
	if (ans == 'C')
	{
		marks = marks + 4;
	}
	else marks--;
	
	if (marks == 20)
	{
		printf("Congratulations, you have qualified for the admission!");
		break;
	}
	printf("Please await further decision.");
	break;
	}
}

