#include <iostream>
using namespace std;
class Distance
{
	private:
		double feet;
		double inches;
	public:
		void operator ++(int)
		{
			inches = inches + 1;
			if(inches > 11) {feet = feet + 1; inches = 0;}			
		}
		void operator --(int)
		{
			inches = inches - 1;
			if (inches < 0) {feet = feet - 1; inches = 11;}
			if (feet < 0) {feet = 0 ; inches = 0;}
		}
		Distance(){}
		Distance(double f ,double i) : feet(f) , inches(i){}
		void display()
		{
			cout << feet << "'" << inches << "\"" << endl;
		}
};
int main()
{
	Distance d(5,11);
	d.display();
	d++;
	d.display();
	Distance d2(5,0);
	d2.display();
	d2--;
	d2.display();
}

