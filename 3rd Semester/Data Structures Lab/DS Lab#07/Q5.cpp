#include<iostream>
using namespace std;
class Searcher
{
	public:
		int NoOfIterations;
		template<typename T , int n>
		int InterpolationSearch(T (&arr)[n], int x)
		{
			NoOfIterations = 0;
		    int l = 0, r = (n - 1);
		    while (l <= r && x >= arr[l] && x <= arr[r])
		    {
		    	NoOfIterations++;
		    	cout << "Value of arr[" << l << "] = " << arr[l] << " and value of arr[" << r << "] = " << arr[r] << endl;
		        if (l == r)
		        {
		            if (arr[l] == x) return l;
		            return -1;
		        }
		        int pos = l + (((double)(r - l) / (arr[r] - arr[l])) * (x - arr[l]));
		        cout << "Value of arr[" << pos << "] = " << arr[pos] << endl;
		        if (arr[pos] == x) return pos;
		        if (arr[pos] < x) l = pos + 1;
		        else r = pos - 1;
		    }
		    return -1;
		}
		template<typename T , int n>
		int BinarySearch(T (&arr)[n] , int x)
		{
			NoOfIterations = 0;
			int l = 0 , r = n-1;
			while (l <= r)
			{
				NoOfIterations++;
				cout << "Value of arr[" << l << "] = " << arr[l] << " and value of arr[" << r << "] = " << arr[r] << endl;
				int m = l + (r - l) / 2;
				if (arr[m] == x) return m;
				if (arr[m] < x) l = m + 1;
				else r = m - 1;
	    	}
	    	return -1;
		}
};
int main()
{
	int arr[21] = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100};
	Searcher Search;
	int x;
	int toFind = 100;
	x = Search.BinarySearch(arr , toFind);
	if (x != -1) cout << "BinarySearch:\t\tNumber found at index " << x << " with " << Search.NoOfIterations << " number of iterations." << endl;
	else cout << "Item Not Found!" << endl;
	cout << endl;
	x = Search.InterpolationSearch(arr , toFind);
	if (x != -1) cout << "InterpolationSearch:\tNumber found at index " << x << " with " << Search.NoOfIterations << " number of iterations." << endl;
	else cout << "Item Not Found!" << endl;
}

