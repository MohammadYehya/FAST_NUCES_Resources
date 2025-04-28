#include <iostream>
using namespace std;
class Person
{
	private:
		string name;
		int age;
		string DOB;
		const int CNIC;
	public:
		void setName(const string n)
		{name = n;}
		void setAge(const int a)
		{age = a;}
		void setDOB(const string d)
		{DOB = d;}
		//No setter for CNIC as it is constant
		
		const string getName()
		{return name;}
		const int getAge()
		{return age;}
		const string getDOB()
		{return DOB;}
		const int getCNIC()
		{return CNIC;}
		Person(string n , int a , string d , int c) : CNIC(c)
		{
			name = n;
			age = a;
			DOB = d;
		}
};
int main()
{
	Person p1("Mohammad Yehya Hayati" , 18 , "15 May 2003" , 42101000);
	Person p2("Ahmed Ali" , 25 , "1 Jan 1997" , 42101141);
	
	cout << "Name: " << p1.getName() << endl << "Age: " << p1.getAge() << endl << "Date of Birth: " << p1.getDOB() << endl << "CNIC: " << p1.getCNIC() << endl;
	cout << endl;
	cout << "Name: " << p2.getName() << endl << "Age: " << p2.getAge() << endl << "Date of Birth: " << p2.getDOB() << endl << "CNIC: " << p2.getCNIC() << endl;
}


