#include <stdio.h>
int main()
{
	int marks=0,out=0,ex=0,good=0,avg=0,Bavg=0,adq=0,pass=0,fail=0;
	for (int i = 1 ; i<=10 ; i++)
	{
		printf("Please enter student marks: ");
		scanf("%d",&marks);
		switch (marks)
		{
			case 90 ... 100:
				out++;
				break;
			case 86 ... 89:
				ex++;
				break;
			case 75 ... 85:
				good++;
				break;
			case 70 ... 74:
				avg++;
				break;
			case 66 ... 69:
				Bavg++;
				break;
			case 62 ... 65:
				adq++;
				break;
			case 50 ... 61:
				pass++;
				break;
			case 0 ... 49:
				fail++;
				break;
			default:
				printf("Invalid Input\n");
				break;
		}
	}
	printf("The number of students that passed are %d\n",pass + out + ex + good + avg + Bavg + adq);
	printf("The number of students that failed are %d\n", fail);
	printf("The number of excellent students are %d\n", ex);
	printf("The number of above average students are %d\n",good + ex + out);
}

