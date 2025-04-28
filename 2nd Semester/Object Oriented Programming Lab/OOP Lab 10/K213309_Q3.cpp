#include <iostream>
using namespace std;
template <typename t1>
class MyContainer
{
	private:
		t1 x;
	public:
		MyContainer(){}
		MyContainer(t1 x){this->x = x;}
		void Increase(){x++;cout << x << endl;}
};

template <>
class MyContainer <char>
{
	private:
		char x;
	public:
		MyContainer(char x){this->x = x;}
		void Increase(){x=x^32;cout << x << endl;}
};

int main()
{
	MyContainer<char> m('A');
	m.Increase();
}

