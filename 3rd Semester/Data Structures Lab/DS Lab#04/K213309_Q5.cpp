#include <iostream>
#define n 11
using namespace std;
void SubArrayLength(int *arr)
{
	int min, max;
	for (int i = 0 ; i < n -1 ; i++)
	{
		if (arr[i] > arr[i+1])
		{
			min = i;
			break;
		}
	}
	for (int i = n - 1 ; i >= 1 ; i--)
	{
		if (arr[i] < arr[i-1])
		{
			max = i + 1;
			break;
		}
	}
	cout << "SubArray length between " << min << " and " << max << endl;
	for (int i = min ; i < max +1 ; i++)
	{
		for (int j = min ; j < max +1 ; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main()
{
	int arr[n] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	
	cout << "Original Array: ";for (int i = 0 ; i < n ; i++) cout << arr[i] << " ";
	cout << endl;
	SubArrayLength(arr);
	cout << "Sorted Array: ";for (int i = 0 ; i < n ; i++) cout << arr[i] << " ";
}
