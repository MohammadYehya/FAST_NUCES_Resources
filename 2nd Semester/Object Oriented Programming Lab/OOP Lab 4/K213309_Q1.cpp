#include <iostream>
using namespace std;
class triangle
{
	private:
		float base;
		float height;
	public:
		void setBase(const float b)
		{base = b;}
		void setHeight(const float h)
		{height = h;}
		const float getBase()
		{return base;}
		const float getHeight()
		{return height;}
		
		triangle(){}
		triangle(float b , float h)
		{
			base = b;
			height = h;
		}
		triangle(const triangle &t)
		{
			height = t.height;
			base = t.base;
		}
		float calcArea()
		{return base * height * 0.5;}
};
int main ()
{
	triangle t1(10,5);
	cout << "The area of the triangle is: " << t1.calcArea() << endl;
	triangle t2 = t1;
	cout << "The area of the copied triangle is: " << t2.calcArea() << endl;
}
