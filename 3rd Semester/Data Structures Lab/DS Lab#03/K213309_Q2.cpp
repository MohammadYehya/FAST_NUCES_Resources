#include<iostream>
using namespace std;
//x is the first term in the sequence
//c is the first difference of the sequence which keeps on incrementing
bool Recur2(int x , int c);
bool Recur1(int x , int c)
{
	if (x > 50)return true;
	cout << x << " ";
	return Recur2(x+c,c);
}
bool Recur2(int x , int c)
{
	c++;
	return Recur1(x,c);
}
int main()
{
	//Part a
	Recur1(1,2);
	
	cout << endl;
	
	//Part b
	Recur1(1,0);
}
