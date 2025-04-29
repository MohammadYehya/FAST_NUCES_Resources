#include <iostream>
#define n 10
using namespace std;
int main()
{
	cout << "The clerk should use selection sorting." << endl;
	cout << "This is because comparisions are required to find the departure time of crates." << endl;
	cout << "Selection Sort code is given in code as a function.";
}
SelectionSort(int time[n])
{
	int min , j;
	for (int i = 0 ; i < n -1 ; i++)
	{
		min = i;
		for (j = i + 1 ; j < n ; j++)
		{
			if (time[j] < time[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = time[min];
			time[min] = time[i];
			time[i] = temp;
		}
	}
}
