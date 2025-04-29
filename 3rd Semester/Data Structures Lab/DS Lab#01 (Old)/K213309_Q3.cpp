#include <iostream>
#define MAX 10
using namespace std;
void Sort(int arr[] , bool asc)
{
	for(int i = 0 ; i < MAX ; i++)
	{
		for(int j = 0 ; j < MAX - 1 ; j++)
		{
			if(asc)
			{
				if(arr[j] > arr[j+1])
				{
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
			else 
			{
				if(arr[j] < arr[j+1])
				{
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
	}
}
int main()
{
	int *arr = new int[MAX];
	for (int i = 0 ; i < MAX ; i++)
	{
		cout << "Enter Integer#" << i << ": "; cin >> arr[i];
	}
	
	Sort(arr,true);
	cout << "After Ascending Sort: ";for(int i = 0 ; i < MAX ; i++)cout << arr[i] << " ";
	Sort(arr,false);
	cout << endl << "After Descending Sort: ";for(int i = 0 ; i < MAX ; i++)cout << arr[i] << " ";
	
	delete []arr;
}

