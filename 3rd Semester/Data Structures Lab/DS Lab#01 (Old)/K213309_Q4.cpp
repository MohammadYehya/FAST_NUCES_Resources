#include <iostream>
#define size 10
using namespace std;
int main()
{
	int *arr = new int[size]{51,15,84,21,87,35,48,35,49,12};
	cout << "Old Array: \t\t";for(int i = 0 ; i < size ; i++)cout << arr[i] << " ";
	cout << endl;
	
	//Sorting the entire array
	for(int i = 0 ; i < size ; i++)
	{
		for(int j = 0 ; j < size - i - 1 ; j++)
		{
			if(arr[j] < arr[j+1])
			{
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	cout << "Ascending Sorted Array:\t";for(int i = 0 ; i < size ; i++)cout << arr[i] << " ";
	cout << endl;
	
	int *reqarr = new int[size];
	for (int i = 0 , j = 0 ; i < size ; i+=2 , j++)
	{
		reqarr[i] = arr[j];
		reqarr[i+1] = arr[size-j-1];
	}
	
	cout << "Required Array: \t";for(int i = 0 ; i < size ; i++)cout << reqarr[i] << " ";
	
	delete []arr;
	delete []reqarr;
}

