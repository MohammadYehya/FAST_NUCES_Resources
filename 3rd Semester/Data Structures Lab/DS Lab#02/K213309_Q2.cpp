#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;
int main()
{
	int *arr = new int[MAX];
	int *ptr = NULL;
	int *Ascending[10];
	int *Descending[10];
	for (int i = 0 ; i < MAX ; i++) {arr[i] = rand()%98;}
	
	for (int i = 0 ; i < MAX ; i++)
	{
		Ascending[i] = &arr[i];
		Descending[i] = &arr[i];
	}
	
	for (int i = 0 ; i < MAX ; i++)
	{
		for (int j = 0 ; j < MAX - i - 1 ; j++)
		{
			if (*Ascending[j] > *Ascending[j+1])
			{
				ptr = Ascending[j+1];
				Ascending[j+1] = Ascending[j];
				Ascending[j] = ptr;
			}
			if (*Descending[j] < *Descending[j+1])
			{
				ptr = Descending[j+1];
				Descending[j+1] = Descending[j];
				Descending[j] = ptr;
			}
		}
	}
	cout << "Original Array: \t\t"; for (int i = 0 ; i < MAX ; i++) cout << arr[i] << " ";
	cout << endl << "Ascending Array: \t\t"; for (int i = 0 ; i < MAX ; i++) cout << *Ascending[i] << " ";
	cout << endl << "Descending Array: \t\t"; for (int i = 0 ; i < MAX ; i++) cout << *Descending[i] << " ";
	cout << endl << "Original Array after Sorting: \t"; for (int i = 0 ; i < MAX ; i++) cout << arr[i] << " ";
	
	for (int i = 0 ; i < MAX ; i++)
	{
		Ascending[i] = NULL;
		Descending[i] = NULL;
	}
	ptr = NULL;
	delete[] arr;
}

