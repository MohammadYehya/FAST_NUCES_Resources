#include <iostream>
using namespace std;

template<int n>
bool Search(int (&list)[n], int i, int m, int target)
{
	if(i > m) return false;
	else if(i == m) 
	{
		for(int j = 0; j < i; j++)
			if(list[i] + list[j] == target && j != i) 
				return true;
		return false;
	}
	else return (Search(list, i, (m+i)/2, target) || Search(list , (m+i)/2+1, m, target));
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	cout << (Search(arr, 0, sizeof(arr)/sizeof(int), 5)? "TRUE" : "FALSE");
}
