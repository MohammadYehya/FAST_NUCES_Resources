#include <iostream>
using namespace std;
class Box
{
	private:
		int NumberOfSides;
		double Area;
	public:
		void display() {cout << "Number of Sides: " << NumberOfSides << " , Area: " << Area << endl;}
		Box operator +(Box b)
		{
			Box res;
			res.Area = Area + b.Area;
			res.NumberOfSides = NumberOfSides + b.NumberOfSides;
			return res;
		}
		void operator >(Box &b)
		{
			b.Area = Area;
			b.NumberOfSides = NumberOfSides;
		}
		void operator <(Box &b)
		{
			Area = b.Area;
			NumberOfSides = b.NumberOfSides;
		}
		Box(){}
		Box(int n, double a):NumberOfSides(n) , Area(a) {}
};
int main()
{
	Box Box1(4,100) , Box2(5,200) , ResultantBox;
	
	ResultantBox = Box1 + Box2;
	ResultantBox.display();
	
	ResultantBox < Box1;
	ResultantBox.display();
	
	ResultantBox > Box2;
	Box2.display();
}

