#include<iostream>
using namespace std;
class Sorter
{
	public:
		template<typename T>
		void Swap(T* x , T* y)
		{
			T temp = *x;
			*x = *y;
			*y = temp;
		}
		template<typename T , int n>
		void QuickSort(T (&arr)[n])
		{
			QuickSortUtil(arr , 0 , n - 1);
		}
		template<typename T , int n>
		void QuickSortUtil(T (&arr)[n] , int l , int r)
		{
			if (l >= r) return;
			int left = l , right = r;
        	T pivot = arr[(l+r)/2];
			while(left <= right)
			{
				while(arr[left] < pivot) left++;
				while(arr[right] > pivot) right--;
				if (left > right) break;
				Swap(&arr[right],&arr[left]);
				left++;
				right--;
			}
			QuickSortUtil(arr , l , right);
			QuickSortUtil(arr , left , r);
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
	cout << "Array before Quick Sort: " << endl;
	Display(a);
	Sort.QuickSort(a);
	cout << "Array after Quick Sort: " << endl;
	Display(a);
}

