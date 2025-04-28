#include <iostream>
#include <fstream>
using namespace std;
string Input()
{
	string s;
	cout << "Input String: "; getline(cin , s);
	return s;
}
int getLength(string s)
{
	int count = 0;
	for (int i = 0 ; s[i]!='\0' ; i++) {count++;}
	return count;
}
void StoreInFile(fstream &f , string s)
{
	f.open("MyFile.txt" , ios::out);
	if (!f)
	{
		cout << "Error!";
		return;
	}
	f << s;
	f.close();
}
void GetFromFile(fstream &f)
{
	char c;
	f.open("MyFile.txt" , ios::in);
	if (!f)
	{
		cout << "Error!";
		return;
	}
	while(1)
	{
		f >> c;
		if(f.eof()) break;
		cout << c;
	}
	f.close();
}
int main()
{
	fstream f;
	StoreInFile(f , Input());
	GetFromFile(f);
}
