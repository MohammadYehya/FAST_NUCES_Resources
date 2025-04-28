#include <iostream>
using namespace std;
class BankEmployee
{
	private:
		char *fname = new char[30];
		string lname;
		int msalary;
		int ysalary;
	public:
		void set_fname(char f[30])
		{fname = f;}
		void set_lname(string l)
		{lname = l;}
		void set_msalary(int s)
		{
			if(s < 0)
			{msalary = 0;}
			else
			{msalary = s;}
		}
		
		void inc_salary(int p)
		{
			msalary += msalary * p / 100;
		}
		char *get_fname()
		{return fname;}
		string get_lname()
		{return lname;}
		int get_msalary()
		{return msalary;}
		int get_ysalary()
		{
			ysalary = 12*msalary;
			return ysalary;
		}
};
int main()
{
	BankEmployee e[5];
	for (int i = 0 ; i < 5 ; i++)
	{
		e[i].set_msalary(100*(i+1));
		cout << "The yearly salary of employee " << i + 1 << " is: " << e[i].get_ysalary() << endl;
		e[i].inc_salary(20);
	}
	for (int i = 0 ; i < 5 ; i++)
	{
		cout << "The yearly salary of employee " << i + 1 << " after 20 percent increase is: " << e[i].get_ysalary() << endl;
	}
}

