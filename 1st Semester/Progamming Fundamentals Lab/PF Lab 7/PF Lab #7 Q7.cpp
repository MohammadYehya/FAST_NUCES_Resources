#include <stdio.h>
int main()
{
	char grade;
	float points;
	for ( int i = 1 ; i <= 5 ; i++)
	{
		printf("Please enter grade for Subject No.%d: ",i);
		scanf(" %c",&grade);
		switch (grade)
		{
			case 'A':
				points = points + 4;
				break;
			case 'B':
				points = points + 3;
				break;
			case 'C':
				points = points + 2;
				break;
			case 'D':
				points = points + 1;
				break;
		}
	}
	printf("The average is %f",points/5);
}

