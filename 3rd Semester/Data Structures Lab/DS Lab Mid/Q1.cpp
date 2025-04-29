#include<iostream>
#define n 10
using namespace std;
void DisplayArray(int* arr)
{
	for (int i = 0 ; i < n ; i++) cout << arr[i] << " ";
	cout << endl;
}
int CheckSequenceAsc(int* arr , int i , int c, int* solArr)
{
	if (i >= ((n-1))) return c;
	else
	{
		if (arr[i] > arr[i+1]) //Checking Reverse Case
		{
			c++;
			solArr[i+1] = 1;
		}
		return CheckSequenceAsc(arr , i+1, c, solArr);
	}
}
int CheckSequenceDsc(int* arr , int i , int c, int* solArr)
{
	if (i >= ((n-1))) return c;
	else
	{
		if (arr[i] < arr[i+1]) //Checking Reverse Case
		{
			c++;
			solArr[i] = 1;
		}
		return CheckSequenceDsc(arr , i+1, c, solArr);
	}
}
int main()
{
	int arr[n] = {1,3,4,2,8,9,5,11,12,15};
	int solArr[n] = {0};
	cout << "Original Array: ";
	DisplayArray(arr);
	cout << endl;
	cout << CheckSequenceAsc(arr ,1 , 0, solArr);
	
	cout << " (remove ";
	for (int i = 0 ; i < n ; i++)
	{
		if (solArr[i] != 0)
		cout << arr[i] << ' ';
	}
	cout << "\b)";
}