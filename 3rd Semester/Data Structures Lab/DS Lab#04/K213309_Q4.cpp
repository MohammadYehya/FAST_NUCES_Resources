#include<iostream>
#define n 7
using namespace std;
void BubbleSort(int *arr)
{
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n -1 -i ; j++)
		{
			if(arr[j] > arr[j+1])
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
	int K = 50;
	int arr[n] = {1, 12, 5, 111, 200, 1000, 10};
	BubbleSort(arr);
	
	for (int i = 0 ; i < n ; i++)
	{
		K -= arr[i];
		if(K < 0)
		{
			cout << "The maximum number of toys you can buy is " << i << endl << "Prices: ";
			for (int j = 0 ; j < i ; j ++) cout << arr[j] << " ";
			break;
		}
	}
}

