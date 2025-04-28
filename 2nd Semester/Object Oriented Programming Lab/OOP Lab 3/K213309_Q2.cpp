#include <iostream>
using namespace std;
class BankInfo
{
	private:
		string name;
		int age;
		long NIC;
		string address;
		float OpeningBalance;
		float CurrentBalance;
		long contact;
		int PIN;
		
	public:
		BankInfo (){}
		//Created a constructor since there was a requirement of the PIN being unmodifiable later. 
		//Permission was already granted by the lab instructor.
		BankInfo(int p)
		{
			name = "";
			NIC = 0;
			address = "";
			OpeningBalance = 0;
			CurrentBalance = 0;
			contact = 0;
			PIN = p;
			
		}
		float get_tax()
		{
			if (age >= 60)
			{
				return CurrentBalance * 0.15 / 100;
			}
			else
			{
				return CurrentBalance * 0.25 / 100;
			}
		}
		void set_name(string s)
		{name = s;}
		void set_age(int a)
		{age = a;}
		void set_NIC(long n)
		{NIC = n;}
		void set_address(string s)
		{address = s;}
		void set_OpeningBalance(float ob)
		{OpeningBalance = ob;}
		void set_CurrentBalance(float cb)
		{CurrentBalance = cb;}
		void set_contact(long c)
		{contact = c;}
		
		string get_name()
		{return name;}
		int get_age()
		{return age;}
		long get_NIC()
		{return NIC;}
		string get_address()
		{return address;}
		float get_OpeningBalance()
		{return OpeningBalance;}
		float get_CurrentBalance()
		{return CurrentBalance;}
		long get_contact()
		{return contact;}
};
int main()
{
	BankInfo c(1214);
	c.set_name("ABC");
	c.set_age(100);
	c.set_NIC(1230235);
	c.set_address("XYZ");
	c.set_OpeningBalance(10000);
	c.set_CurrentBalance(100000);
	c.set_contact(123456789);
	cout << "The tax on the current balance is: " << c.get_tax();
}

