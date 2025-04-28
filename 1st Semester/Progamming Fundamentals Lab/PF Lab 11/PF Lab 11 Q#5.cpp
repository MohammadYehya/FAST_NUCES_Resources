#include <stdio.h>
float add(float a, float b);
float sub(float  a, float b);
float mult(float a , float b);
float div(float a , float b);
int main()
{
	int n;
	float num1,num2;
	float (*ptr[4])(float , float);
	ptr[0] = &add;
	ptr[1] = &sub;
	ptr[2] = &mult;
	ptr[3] = &div;
	do
	{
		printf("Enter 1(To add) 2(To Subtract) 3(To Multiply) 4(Divide): ");
		scanf("%d",&n);
	}
	while (n < 0 && n > 3);
	n--;
	printf("Enter Num1: ");
	scanf("%f",&num1);
	printf("Enter Num2: ");
	scanf("%f",&num2);
	printf("%.2f",ptr[n](num1,num2));
}
float add(float a, float b)
{
	return a+b;
}
float sub(float  a, float b)
{
	return a-b;
}
float mult(float a , float b)
{
	return a*b;
}
float div(float a , float b)
{
	return a/b;
}
