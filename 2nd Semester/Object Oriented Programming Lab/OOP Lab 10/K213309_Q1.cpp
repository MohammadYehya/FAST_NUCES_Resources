#include <iostream>
using namespace std;
template <typename t1, typename t2>
class Calculator
{
	public:
		float Add(t1 x , t2 y)
		{
			return x+y;
		}
		float Subtract(t1 x , t2 y)
		{
			return x-y;
		}
		float Divide(t1 x , t2 y)
		{
			return x/y;
		}
		float Multiply(t1 x , t2 y)
		{
			return x*y;
		}
	
};
int main()
{
	Calculator <int,int>c1;
	cout << c1.Divide(10.5,1) << endl;
	
	Calculator <int,float>c2;
	cout << c2.Multiply(5,2.5) << endl;
}

