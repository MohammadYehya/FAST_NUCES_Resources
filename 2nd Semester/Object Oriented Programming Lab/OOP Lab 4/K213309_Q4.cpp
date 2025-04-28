#include <iostream>
using namespace std;
class Member
{
	private:
		string name;
		int ID;
		int count;
		float amount;
	public:
		void setName(const string n)//Sets the name
		{name = n;}
		void setCount(const int c)//Sets the count
		{if (c >= 0) count = c;}
		void setAmount(const float f)//Sets the amount
		{if (f >= 0) amount = f;}
		
		const string getName()//Returns the name
		{return name;}
		const int getCount()//Returns the count
		{return count;}
		const int getAmount()//Returns the amount
		{return amount;}
		const int getID()//Returns the ID
		{return ID;}
		
		Member(){}
		Member(int i , int c , float a)
		{
			ID = i;
			count = c;
			amount = a;
		}
	
};
int main ()
{
	Member m1(3309,10,7500);
	m1.setName("Mohammad Yehya");
	cout << "Name: " << m1.getName() << endl << "ID: " << m1.getID() << endl << "Number of CDs Rented: " << m1.getCount() << endl << "Amount Spent: " << m1.getAmount() << endl;
	
}
