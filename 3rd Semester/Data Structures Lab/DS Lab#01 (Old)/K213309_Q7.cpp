#include <iostream>
using namespace std;
class Numbers
{
	private:
		int size;
		int *ptr;
	public:
		//Setters
		void setSize(const int size){this->size = size;}
		void setPtr(int *ptr){this->ptr = ptr;}
		//Getters
		int *getPtr(){return ptr;}
		//Constructors & Destructor
		Numbers()
		{
			ptr = new int;
		}
		Numbers(const Numbers &obj)
		{
			Numbers();
			ptr = obj.ptr;
		}
		~Numbers()
		{
			delete ptr;
		}
};
int main()
{
	int *arr = new int[5]{3 , 4 , 6 , 1 , 9};
	Numbers N1;
	N1.setPtr(arr);
	Numbers N2 = N1;
	
	cout << "Pointer in N1: ";for(int i = 0 ; i < 5 ; i ++)cout << *(N1.getPtr() + i);
	cout << endl << "Pointer in N2: ";for(int i = 0 ; i < 5 ; i ++)cout << *(N2.getPtr() + i);
	
	delete []arr;
}

