#include <iostream>
using namespace std;
template <class T>
class SafeArray
{
	private:
		int size;
		T *arr;	
	public:
		//Constructors
		SafeArray(){}
		SafeArray(int size){this->size = size; arr = new T[size];}
		SafeArray(const SafeArray &x)
		{
			this->size = x.size;
			this->arr = new T[size];
			for(int i = 0 ; i < size ; i++) this->arr[i] = x.arr[i];
		}
		
		//Destructor
		~SafeArray(){delete[] arr;}
		
		//Overloaded Operators
		operator = (const SafeArray &x)
		{
			this->size = x.size;
			delete[] arr;
			arr = new T[size];
			for(int i = 0 ; i < size ; i++)
			{
				this->arr[i] = x.arr[i];
			}
		}
		T operator [](int x)
		{
			if(x >= size || x < 0)
			{
				cout << "Boundary Error! Exiting Sequence 3309!" << endl;
				exit(3309);
			}
			else return arr[x];
		}
};
int main()
{
	SafeArray<int> X(3);
	cout << X[6];
}

