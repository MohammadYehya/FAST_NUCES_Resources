#include <iostream>
using namespace std;
class Shape
{
	private:
		int numberOfSides;
		float area;
	public:
		Shape(){}
		Shape(int s) : numberOfSides(s){}
		const int getnumberOfSides(){return numberOfSides;}
		const float getArea(){return area;}
		void setnumberOfSides(const int s){numberOfSides = s;}
		void setArea(const float a){area = a;}
};
class Rectangle : public Shape
{
	private:
		float length;
		float width;
	public:
		Rectangle(){}
		Rectangle(float l , float w) : length(l) , width(w) , Shape(4) {generateArea();}
		void generateArea() {setArea(length * width);}
		const float getlength(){return length;}
		const float getwidth(){return width;}
};
class Circle : public Shape
{
	private:
		float radius;
	public:
		Circle(){}
		Circle(float r) : radius(r) , Shape(0){generateArea();}
		void generateArea() {setArea(3.142 * radius * radius);}
};
class Triangle : public Shape
{
	private:
		float height;
		float base;
	public:
		Triangle(){}
		Triangle(float h , float b) : height(h) , base(b) , Shape(3){generateArea();}
		void generateArea() {setArea(0.5 * height * base);}
};
class Square : public Rectangle
{
	public:
		Square(){}
		Square(float s) : Rectangle(s , s){generateArea();}
		void generateArea() {Rectangle::generateArea();}
		bool checkSides(){if (getlength() == getwidth()) return 1; else return 0;}
};
int main()
{
	Rectangle R1(10 , 3);
	Circle C1(10);
	Triangle T1(4 , 6);
	Square S1(2);
	
	cout << "The area is : " << R1.getArea() << endl;
	cout << "The area is : " << C1.getArea() << endl;
	cout << "The area is : " << T1.getArea() << endl;
	cout << "The area is : " << S1.getArea() << endl;
}

