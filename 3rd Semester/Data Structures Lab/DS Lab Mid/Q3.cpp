#include<iostream>
#define n 11
using namespace std;
void FindLBSAsc(int *arr , int* subarr)
{
	int i;
	for (i = 0 ; i < n-1 ; i++)
	{
		if(arr[i] < arr[i+1])
		{
			subarr[i] = arr[i];
		}
		else 
		{
			subarr[i] = arr[i];
			break;
		}
	}
	int j;
	for (j = i+1 ; j < n-1 ; j++)//Continue in Ascending because Descending Backwards = Asc
	{
		if (arr[j] < arr[j+1])
		{
			subarr[j] = arr[j];
		}
		else
		{
			subarr[j] = arr[j];
			break;
		}
	}
}
void DisplayArray(int* arr)
{
	for (int i = 0 ; i < n ; i++) cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	int arr[n] = {3,5,8,4,5,9,10,8,5,3,4};
	int subarr[n] = {0};
	FindLBSAsc(arr , subarr);
	cout << "Original Array: ";
	DisplayArray(arr);
	cout << "Sub-Array: ";
	DisplayArray(subarr);
}
