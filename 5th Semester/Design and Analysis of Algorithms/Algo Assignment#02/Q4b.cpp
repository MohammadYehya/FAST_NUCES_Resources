#include <iostream>
#include <cmath>
using namespace std;

template<int n>
int MetaBinarySearch(int (&arr)[n], int key, int lg, int p)
{
	if(lg < 0) return p;
	else 
	{
		int x = p | (1 << lg);
		return MetaBinarySearch(arr, key, lg-1, (x < n && arr[x] <= key)? x : p);
	}
}
template<int n>
int MBS(int (&arr)[n], int key)
{
	int val = (MetaBinarySearch(arr, key, log2(n-1), 0));
	return (arr[val] == key)? val : -1;
}
int main()
{
	int arr[] = {1,3,5,8,15,21,37,59,77,89};
	cout << MBS(arr, 37);
}
