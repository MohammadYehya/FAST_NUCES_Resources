#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	string s;
	fstream f1 , f2;
	f1.open("MyFile.txt" , ios::in);
	f2.open("MyCopy.txt" , ios::out);
	if (!f1)
	{
		cout << "Error!";
		return 0;
	}
	if (!f2)
	{
		cout << "Error!";
		return 0;
	}
	while(!f1.eof())
	{
		getline(f1 , s);
		f2 << s;
	}
	cout << "Copied!";
	f1.close();
	f2.close();
}

