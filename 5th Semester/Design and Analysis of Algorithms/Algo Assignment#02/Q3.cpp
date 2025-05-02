#include <iostream>
using namespace std;
int findMax(int *arr, int i)
{
	if(arr[i] > arr[i+1] && arr[i] > arr[i+2]) return i;
	else if(arr[i+1] > arr[i] && arr[i+1] > arr[i+2]) return i+1;
	else if(arr[i+2] > arr[i] && arr[i+2] > arr[i+1]) return i+2;
}
int main()
{
	int arr[9] ={1,1,1,2,1,1,1,1,1};
	int given = 3;
	cout << "Heaviest at idx: ";
	for(int i = 0; i < 9; i+=3)
	{
		if(arr[i] + arr[i+1] + arr[i+2] > given)
		{
			cout << findMax(arr, i);
			break;
		}
	}
}

