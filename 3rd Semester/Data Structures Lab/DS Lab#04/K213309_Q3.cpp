#include<iostream>
#define n 10
using namespace std;
void SortInsertion(int *arr) 
{ 
    int temp, j;
    for (int i = 1; i < n; i++)
    { 
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        { 
            arr[j + 1] = arr[j]; 
            j--;
        } 
        arr[j + 1] = temp; 
    } 
} 
int main()
{
	int arr[n] = {3,2,6,8,0,16,7,4,11,9};
	cout << "Original Array: " << endl;
	for (int i = 0 ; i < n ; i++) cout << arr[i] << " ";
	
	SortInsertion(arr);
	
	cout << endl << "Sorted Array: " << endl;
	for (int i = 0 ; i < n ; i++) cout << arr[i] << " ";
}
