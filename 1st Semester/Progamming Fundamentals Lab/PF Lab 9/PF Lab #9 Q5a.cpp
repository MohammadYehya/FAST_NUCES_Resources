#include <stdio.h>
void leapyear(int _year);
int main()
{
	int year;
	printf("Enter a year: ");
	scanf("%d",&year);
	leapyear(year);
}
void leapyear(int _year)
{
	if (_year % 400 == 0)
	{
		printf("It is a leap year!");
	}
	else if (_year % 100 == 0)
	{
		printf("It is not a leap year!");
	}
	else if (_year % 4 == 0)
	{
		printf("It is a leap year!");
	}
	else 
	{
		printf("It is not a leap year!");
	}
}

