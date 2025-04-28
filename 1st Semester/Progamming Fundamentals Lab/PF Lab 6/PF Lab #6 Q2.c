#include <stdio.h>
int main()
{
	//Q2
	float s1,s2,s3;
	printf("Please enter the sides of the triangle.");
	printf("\nSide1: ");
	scanf("%f",&s1);
	printf("Side2: ");
	scanf("%f",&s2);
	printf("Side3: ");
	scanf("%f",&s3);
	if (s1 == s2 && s2 == s3 && s1 == s3)
	{
		printf("It is an equilateral triangle!");
	}
	else if ((s1 == s2 && s2 != s3) || (s1 == s3 && s3 != s2) || (s2 == s3 && s1 != s2))
	{
		printf("It is an isosceles triangle!");
	}
	else
	{
		printf("It is a scalene triangle!");
	}
}
