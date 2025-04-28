#include <iostream>
using namespace std;
class Square
{
	private:
		double Area;
		double Side;
		int NumberOfSides;
	public:
		Square()
		{
			Area = 0.00;
			Side = 0.00;
			NumberOfSides = 4;
		}
		Square(double a , double s)
		{
			Area = a;
			Side = s;
			NumberOfSides = 4;
		}
		Square operator ++(int)
		{
			Square s(Area , Side);
			Area = 200.0;
			return s ;
		}
		Square& operator ++()
		{
			Area = 400.0;
			return *this;
		}
		Square operator *(const Square &s)
		{
			Square x;
			x.Area = this->Area * s.Area;
			x.Side = this->Side * s.Side;
			x.NumberOfSides = 4;
			return x;
		}
		void display() {cout << "Area: " << Area << endl << "Side Length: " << Side << endl;}
};
int main()
{
	Square sq(100,25);
	Square sq2(200, 2);
	sq.display();
	sq++;
	sq.display();
	++sq;
	sq.display();
	Square res = sq * sq2;
	res.display();
	return 0;
}

