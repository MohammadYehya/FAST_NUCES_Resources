#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
using namespace std;
class Person
{
	private:
		char* Name;
		int Age;
	public:
		Person(){}
		Person(char* n , int a):Age(a) {Name = n;}
		void data() {cout << "Name: " << Name << " Age: " << Age << endl;}
};
int main()
{
	Person p("Person 1" , 19);
	fstream f("MyPerson.dat" ,  ios::out | ios::binary);
	if (!f)
	{
		cout << "Error!";
		return 0;
	}
	f.write((char*)&p,sizeof(p));
	f.close();
	
	f.open("MyPerson.dat" , ios::in | ios::binary);
	Person p2;
	f.read((char*)&p2,sizeof(p2));
	p2.data();
	f.close();
	return 0;
}

