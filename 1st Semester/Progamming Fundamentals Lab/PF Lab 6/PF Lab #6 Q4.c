#include <stdio.h>
int main()
{
	//Q4
	int score,deduction;
	printf("Please enter your score: ");
	scanf("%d",&score);
	switch(score)
	{
		case 95 ... 100:
			deduction = 15;
			printf("Your fee is reduced by %d percent.",deduction);
			break;
		case 90 ... 94:
			deduction = 10;
			printf("Your fee is reduced by %d percent.",deduction);
			break;
		case 80 ... 89:
			deduction = 8;
			printf("Your fee is reduced by %d percent.",deduction);
			break;
		case 70 ... 79:
			deduction = 4;
			printf("Your fee is reduced by %d percent.",deduction);
			break;
		default:
			printf("You have no deduction in fees.");
	}
}
