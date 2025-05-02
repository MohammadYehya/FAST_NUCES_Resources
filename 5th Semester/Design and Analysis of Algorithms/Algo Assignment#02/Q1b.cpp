#include <iostream>
using namespace std;
template<int n>
bool Search(int* list1, int (&list2)[n], int i, int m, int target)
{
	if(i > m) return false;
	else if(i == m) 
	{
		for(int j = 0; j < n; j++)
			if(list1[i] + list2[j] == target)
				return true;
		return false;
	}
	else return (Search(list1, list2, i, (m+i)/2, target) || Search(list1, list2, (m+i)/2+1, m, target));
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int arr2[] = {11,12,13,14,15,16,17,18,19,20};
	cout << (Search(arr, arr2, 0, sizeof(arr)/sizeof(int), 30)? "TRUE" : "FALSE");
}
