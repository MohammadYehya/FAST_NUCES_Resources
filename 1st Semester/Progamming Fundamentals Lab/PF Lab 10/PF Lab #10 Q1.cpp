#include <stdio.h>
float power(float _num , int _p);
int main()
{
	float num;
	int p;
	printf("Enter your number: ");
	scanf("%f",&num);
	printf("Enter the power: ");
	scanf("%d",&p);
	printf("The value of num^p = %f",power(num,p));
} 
float power(float _num , int _p)
{
	float res = 1;
	if (_p == 1)
	{
		return _num;
	}
	else
	{
		res = _num * power(_num,_p-1);
		return res;
	}
}

