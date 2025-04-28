#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int c = 0;
	string s;
	fstream f("STORY.txt" , ios::in);
	while(!f.eof())
	{
		getline(f , s);
		cout << s << endl;
		if (s[0] != 'A') c++;
	}
	cout << "The Number of sentences starting without \'A\' is " << c;
}
