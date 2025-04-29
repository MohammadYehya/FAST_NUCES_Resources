#include <iostream>
using namespace std;
template<typename T, int n>
class MinHeap{
    int top;
    int capacity;
    T arr[n];
	public:
		MinHeap()
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
		    while(i != 0 && arr[Parent(i)] > arr[i])
			{
		        swap(arr[i], arr[Parent(i)]);
		        i = Parent(i);
		    }
		}
	    T ExtractMin()
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
		        MinHeapify(0);
		        return root;
		    }
		}
	    void MinHeapify(int i)
	    {
	    	int l = Left(i);
		    int r = Right(i);
		    int smallest = i;
		    if((l < top) && (arr[l] < arr[smallest])) smallest = l;
			if((r < top) && (arr[r] < arr[smallest])) smallest = r;
		    if(smallest != i)
			{
		        swap(arr[i], arr[smallest]);
		        MinHeapify(smallest);
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
		void Delete(int i) {Delete(i, INT_MIN); ExtractMin();}
		void Delete(int i, T Val)
		{
			cout << "Deleting value: " << arr[i] << endl;
			arr[i] = Val;
			while(i != 0 && arr[Parent(i)] > arr[i])
			{
				swap(arr[i], arr[Parent(i)]);
				i = Parent(i);
			}
		}
		void clear() {top = 0;}
		template<int size>
		int MinOperationArrayFix(T (&array)[size])
		{
			int difference = 0, sum = 0;
			for(int i = 0 ; i < size ; i++)
			{
				if(top != 0 && arr[0] < array[i])
				{
					difference = array[i] - arr[0];
					sum += difference;
					ExtractMin();
					Insert(array[i]);
				}
				Insert(array[i]);
			}
			return sum;
		}
};
int main()
{
	int arr[] = {3,1,5,1};
	const int N = sizeof(arr)/sizeof(arr[0]);
	MinHeap<int , N> heap;
	cout << heap.MinOperationArrayFix(arr) << endl;
	heap.PrintHeap();
}
