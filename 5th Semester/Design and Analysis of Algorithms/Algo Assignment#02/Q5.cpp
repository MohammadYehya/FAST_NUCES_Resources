#include <iostream>
using namespace std;

template<int n, int k>
int Counting(int (&arr)[n], int (&arr2)[k])
{
	for(int i = 0; i < n; i++) arr2[arr[i]]++;
	for(int i = 1; i < k; i++) arr2[i] += arr2[i-1];
}
int main()
{
	int arr[] = {3,1,5,9,6,4,3,4,2,6,9,0,1,5};
	int arr2[9+1] = {0};
	Counting(arr, arr2);
	
	int a = 1, b = 9;
	cout << arr2[b] - arr2[a-1];
}
