#include <iostream>
using namespace std;
template <typename t1 , typename t2>
Swap(t1 &x , t2 &y)
{
		t1 temp;
		temp = x;
		x = y;
		y = temp;
}
int main()
{
	int x = 65;
	char y= 'Z';
	cout << x << " " << y << endl;
	Swap<int ,char>(x,y);
	cout << x << " " << y << endl;
}

