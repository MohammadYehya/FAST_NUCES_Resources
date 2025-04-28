#include <stdio.h>
int main()
{
	int marks[10],i,fail[10]={0},pass[10]={0},failcount=0,passcount=0,avgfail=0,avgpass=0;
	for (i = 1 ; i <= 10 ; i++)
	{
		printf("Enter the marks of student %d: ",i);
		scanf("%d",&marks[i]);
		if (marks[i] == -1)
		{
			break;
		}
		if (marks[i] > 0 && marks[i] < 5)
		{
			fail[i] = marks[i];
			failcount++;
		}
		else if (marks[i] < 10 && marks[i] > 5)
		{
			pass[i] = marks[i];
			passcount++;
		}
	}
	for (i = 1 ;  i <= 10 ; i++)
	{
		avgfail += fail[i];
		avgpass += pass[i];
		printf("The marks of student %d is: %d\n",i,marks[i]);
	}
	printf("The average of the fail students is: %d\n",avgfail/failcount);
	printf("The average of the pass students is : %d",avgpass/passcount);
}

