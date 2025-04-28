#include <iostream>
#include <cmath>
#define pi 3.1416
using namespace std;
float distance(float x1 , float y1 , float x2 , float y2)
{
	return sqrt(pow(x2 - x1 , 2) + pow(y2 - y1 , 2));
}
float radius(float x1 , float x2 , float y1 , float y2)
{
	return distance(x1,y1,x2,y2);
}
float circumference(float r)
{
	return 2 * pi * r;
}
float area(float r)
{
	return pi * r * r;
}
int main()
{
	float x1 , x2 , y1 , y2 , rad;
		cout << "Enter x1: ";
		cin >> x1;
		cout << "Enter y1: ";
		cin >> y1;
		cout << "Enter x2: ";
		cin >> x2;
		cout << "Enter y2: ";
		cin >> y2;
		cout << "The distance is: " << distance(x1,y1,x2,y2) << endl;
		cout << "The radius is: " << radius(x1,y1,x2,y2) << endl;
		cout << "The circumference is: " <<  circumference(radius(x1,y1,x2,y2)) << endl;
		cout << "The area is: " << area(radius(x1,y1,x2,y2));
}
