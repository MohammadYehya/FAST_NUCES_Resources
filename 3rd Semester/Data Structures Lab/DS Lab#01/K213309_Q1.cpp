#include <iostream>
#include <cstdlib>
using namespace std;
class Thing
{
	private:
		int *ptr;
		int size;
	public:
		//Constructors
		Thing(){this->size = 0 ; ptr = NULL;}
		Thing(const int size){this->size = size; ptr = new int[size];}
		Thing(const Thing &x)
		{
			this->size = x.size;
			this->ptr = new int[size];
			for(int i = 0 ; i < size ; i++)
			{
				this->ptr[i] = x.ptr[i];
			}
		}
		//Destructor
		~Thing(){size = 0; delete[] ptr;}
		
		//Overloaded Operators
		operator = (const Thing &x)
		{
			this->size = x.size;
			delete[] ptr;
			ptr = new int[size];
			for(int i = 0 ; i < size ; i++)
			{
				this->ptr[i] = x.ptr[i];
			}
		}
		friend ostream& operator <<(ostream &x ,const Thing &o);
		
		//Member Functions
		PopulateArray()
		{
			for(int i = 0 ; i < size ; i++)
			{
				ptr[i] = rand()%101;
			}
		}
};
ostream &operator <<(ostream &x , const Thing &o)
	{
		x << "Size: " << o.size << endl << "Elements in Array: ";
		for(int i = 0 ; i < o.size ; i++) x << o.ptr[i] << " ";
		return x;
	}

//Rule of Three requires us to explicitly create Destructors, Copy Constructors, and overloaded assignment operators 
//when the use of pointers is introduced in a class


int main()
{
	Thing x1(2);
	x1.PopulateArray();
	
	Thing x2(x1);
	Thing x3 = x2;
	
	cout << "X1" << endl << x1 << endl << endl;
	cout << "X2" << endl << x2 << endl << endl;
	cout << "X3" << endl << x3 << endl << endl;
}

