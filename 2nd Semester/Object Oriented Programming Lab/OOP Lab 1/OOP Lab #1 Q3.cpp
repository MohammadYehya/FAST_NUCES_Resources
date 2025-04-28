#include <iostream>
using namespace std;
float Addition (float a , float b)
{
	return a + b;
}
float Multiplication (float a , float b)
{
	return a * b;
}
float Division (float a , float b)
{
	return a / b;
}
float Subtraction (float a , float b)
{
	return a - b;
}
int main()
{
	float a , b;
	cout << "Please enter two numbers: ";
	cin >> a >> b;
	cout << "a + b = " << Addition(a , b) << endl;
	cout << "a - b = " << Subtraction(a , b) << endl;
	cout << "a * b = " << Multiplication(a , b) << endl;
	cout << "a / b = " << Division(a , b) << endl;
}
