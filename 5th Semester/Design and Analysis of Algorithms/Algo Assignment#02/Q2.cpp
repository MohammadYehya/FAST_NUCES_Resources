#include <iostream>
using namespace std;

int Search(char x[], int l, int r)
{
	if(l < r)
	{
		int m = (l+r)/2;
		if(x[m] == x[m+1])
		{
			if(m%2) return (x, l, m);
			else return Search(x, m+2, r);
		}
		else
		{
			if(m%2) return Search(x, m+1, r);
			else return Search(x, l, m);
		}
	}
	return l;
}
template<int n>
int Check(char (&arr)[n])
{
	if((n-1)%2) return Search(arr, 0, sizeof(arr)-2);
	return -1;
}
int main()
{
	char x[] = "xxyyzzwwnii";
	cout << Check(x);
}
