#include<iostream>
using namespace std;
class Sorter
{
	public:
		template<int n>
		int FindMax(int (&arr)[n])
		{
			int max = -999999;
			for (int i = 0 ; i < n ; i++)
			{
				if (max < arr[i]) max =arr[i];
			}
			return max;
		}
		template<int n>
		void MergeSort(int (&arr)[n]) 
		{
			int max = FindMax(arr) + 1;
			MergeSortUtil(arr , 0 , n-1, max);
		}
		template<int n>
		void MergeSortUtil(int (&arr)[n] , int l , int r , int max)
		{
			if (l >= r) return;
			int m = (l + r) / 2;
			MergeSortUtil(arr , l , m , max);
			MergeSortUtil(arr , m + 1 , r , max);
			Merge(arr , l , m , r , max);
		}
		template<int n>
		void Merge(int (&arr)[n] , int l , int m , int r , int max)
		{
			int i = l , j = m + 1 , k = l;
			while (i <= m && j <= r)
			{
				if (arr[i] % max <= arr[j] % max)
				{
					arr[k] += (arr[i] % max) * max;
					i++;
				}
				else
				{
					arr[k] += (arr[j] % max) * max;
					j++;
				}
				k++;
			}
			while(i <= m)
			{
				arr[k] += (arr[i] % max) * max;
				i++;
				k++;
			}
			while(j <= r)
			{
				arr[k] += (arr[j] % max) * max;
				j++;
				k++;
			}
			for (int i = l; i <= r; i++) arr[i] /= max;
		}
};
template<typename T , int n>
void Display(T (&arr)[n])
{
	for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	int a[10] = {0,9,1,8,2,7,3,6,5,4};
	Sorter Sort;
	cout << "Array before Merge Sort: " << endl;
	Display(a);
	Sort.MergeSort(a);
	cout << "Array after Merge Sort: " << endl;
	Display(a);
}

