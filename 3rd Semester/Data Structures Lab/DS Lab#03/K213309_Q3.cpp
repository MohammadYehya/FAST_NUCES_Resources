#include<iostream>
#define n 6
using namespace std;
int RecurBubbleSort(int *arr , int x , int y)
{
	if (x >= n) return 1;
	else if (y >= n - x - 1) return 0;
	else if (arr[y] > arr[y+1])
	{
		int temp = arr[y];
		arr[y] = arr[y+1];
		arr[y+1] = temp;
	}
	return RecurBubbleSort(arr , x+1 , RecurBubbleSort(arr , x , y+1));
}
void DisplayArray(int *arr) {for (int i = 0 ; i < n ; i++) cout << arr[i] << " ";}
int main()
{
	int arr[n] = {12 ,11, 13, 5, 6, 7};
	cout << "Original Array:\t"; DisplayArray(arr);
	RecurBubbleSort(arr,0,0);
	cout << endl << "Sorted Array:\t"; DisplayArray(arr);
}
