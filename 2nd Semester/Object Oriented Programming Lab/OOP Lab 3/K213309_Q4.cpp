#include <iostream>
using namespace std;
class CounterType
{
	private:
		int count;
	public:
		void set_Count(int c)//If statements are added to remove the chances of a negative number.
		{if (c >= 0)count = c;}
		void inc_Count()
		{if (count >= 0)count++;}
		void dec_Count()
		{if (count > 0)count--;}
		int get_Count()
		{return count;}
		void display()
		{cout << "The count is: " << count << endl;}
};
int main()
{
	CounterType c;
	
	c.set_Count(2);
	c.inc_Count();
	c.display();
	c.dec_Count();
	c.display();
	c.set_Count(0);
	cout << "The count after setting is: " << c.get_Count() << endl;
	c.dec_Count();
	c.display();
}

