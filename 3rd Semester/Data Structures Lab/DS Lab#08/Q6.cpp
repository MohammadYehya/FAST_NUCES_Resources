#include <iostream>
#include <conio.h>
using namespace std;
template<int size>
class Stack
{
	int top;
	string a[size];
	public:
	Stack() {top = -1;}
	bool Push(string x)
	{
		if (top >= (size - 1))
		{
			return false;
		}
		else 
		{
			a[++top] = x;
			return true;
		}
	}
	string Pop()
	{
		if (top < 0)
		{
			return "";
		}
		else 
		{
			string x = a[top--];
			return x;
		}
	}
	string Peek()
	{
		if (top < 0) 
		{
			return "";
		}
		else 
		{
			string x = a[top];
			return x;
		}
	}
	bool isEmpty()
	{
		return (top < 0);
	}
	void Display()
	{
		for (int i = 0 ; i <= top ; i++) cout << a[i];
		cout << endl;
	}
};
int main()
{
	Stack<10> st1;//Created stacks for Strings
	Stack<10> st2;
	string s = "";
	char prompt = 0;
	cout << "Enter String: ";
	while(prompt != 13)//Check for Enter Key
	{
		prompt = getch();
		s += prompt;
		cout << prompt;
		if (prompt == 32)//Check for Space Key
		{
			st1.Push(s);
			s = "";
		}
	}
	st1.Push(s);
	int choice = 0;
	while(choice != 4)
	{
		system("cls");
		cout << "1.Undo" << endl << "2.Redo" << endl << "3.Print String" << endl << "4.Exit" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				s = st1.Pop();
				if (s != "") st2.Push(s);
				break;
			case 2:
				s = st2.Pop();
				if (s != "") st1.Push(s);
				break;
			case 3:
				st1.Display();
			    getch();
				break;
		}
	}
}

