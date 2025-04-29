#include<iostream>
using namespace std;
//x is the first term in the sequence
//c is the first difference of the sequence which keeps on incrementing
bool Recur(int x , int c)
{
	if (x > 50) return true;
	else
	{
		cout << x << " ";
		x += c;
		c++;
		return Recur(x , c);
	}
}
int main()
{
	//Part a
	Recur(1,2);
	
	cout << endl;
	
	//Part b
	Recur(1,0);
}
