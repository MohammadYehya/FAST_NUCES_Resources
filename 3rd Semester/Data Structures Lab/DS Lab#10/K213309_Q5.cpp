#include <iostream>
using namespace std;
template<typename T , int n>
class MaxHeap{
    int top;
    int capacity;
    T arr[n];
	public:
		MaxHeap()
		{
			top = 0;
			capacity = n;
		}
	    int Parent(int i){return (i - 1) / 2;}
	    int Left(int i){return 2 * i + 1;}
	    int Right(int i){return 2 * i + 2;}
	    void Insert(T x)
	    {
	    	cout << "Inserting value: " << x << endl;
	    	if(top == capacity) return;
		    int i = top++;
		    arr[i] = x;
		    while(i != 0 && arr[Parent(i)] < arr[i])
			{
		        swap(arr[i], arr[Parent(i)]);
		        i = Parent(i);
		    }
		}
	    T ExtractMax()
	    {
	    	if(top == 0) {}
			else if(top == 1)
			{
		        top--;
		        return arr[0];
		    }
			else{
		        T root = arr[0];
		        arr[0] = arr[top - 1];
		        top--;
		        MaxHeapify(0);
		        return root;
		    }
		}
	    void MaxHeapify(int i)
	    {
	    	int l = Left(i);
		    int r = Right(i);
		    int largest = i;
		    if((l < top) && (arr[l] > arr[largest])) largest = l;
			if((r < top) && (arr[r] > arr[largest])) largest = r;
		    if(largest != i)
			{
		        swap(arr[i], arr[largest]);
		        MaxHeapify(largest);
		    }
		}
	    void PrintHeap()
	    {
	    	int Exponent = 0;
		    int Val = 1;
		    for(int i = 0; i < top; i++)
		    {
		        if(i == Val)
				{
		            cout << endl;
		            Exponent += 1;
		            Val += (1 << Exponent);
		        }
		        cout << arr[i] << "  ";
		    }
		    cout << endl;
		}
		void Delete(int i) {Delete(i, INT_MAX); ExtractMax();}
		void Delete(int i, T Val)
		{
			cout << "Deleting value: " << arr[i] << endl;
			arr[i] = Val;
			while(i != 0 && arr[Parent(i)] < arr[i])
			{
				swap(arr[i], arr[Parent(i)]);
				i = Parent(i);
			}
		}

};
int main()
{
	int arr[] = {3,4,2,5,1,9};
	const int N = sizeof(arr)/sizeof(arr[0]);
	MaxHeap<int, N> heap;
	for (int i = 0 ; i < N ; i++) heap.Insert(arr[i]);
	heap.PrintHeap();
}
