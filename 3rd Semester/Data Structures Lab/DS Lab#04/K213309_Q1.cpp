#include<iostream>
#define n 5
using namespace std;
void BubbleSort(string *arr)
{
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n -1 -i ; j++)
		{
			if(arr[j] > arr[j+1])//Sorting according to ASCII number of strings
			{
				string temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main()
{
	string arr[n] = {"my" , "name" , "is" , "Mohammad" , "Yehya"};
	cout << "Original Array: " << endl;
	for (int i = 0 ; i < n ; i++) cout << arr[i] << " ";
	
	BubbleSort(arr);
	
	cout << endl << "Sorted Array: " << endl;
	for (int i = 0 ; i < n ; i++) cout << arr[i] << " ";
}
