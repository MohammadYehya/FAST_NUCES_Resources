#include <iostream>
using namespace std;
int main()
{
	float **arr = new float*[5];
	int size[5] = {5,4,3,3,5};
	arr[0] = new float[5]{3.66 , 3.33 , 4.00 , 3.00 , 2.66};
	arr[1] = new float[4]{3.33 , 3.00 , 3.66 , 3.00};
	arr[2] = new float[3]{4.00 , 3.66 , 2.66};
	arr[3] = new float[3]{2.66 , 2.33 , 4.00};
	arr[4] = new float[5]{3.33 , 3.66 , 4.00 , 3.00 , 3.33};
	
	float sum[5] = {0} , GPA[5] = {0};
	for (int i = 0 ; i < 5 ; i ++)
	{
		for(int j = 0 ; j < size[i] ; j++)
		{
			sum[i] += arr[i][j];
		}
		GPA[i] = sum[i]/size[i];
	}
	for(int i = 0 ; i < 5 ; i++)
	{
		cout << "GPA of student " << i+1 << ": " << GPA[i] << endl;
	}
	
	for (int i = 0 ; i < 5 ; i++) delete[] arr[i];
	delete[] arr;
}

