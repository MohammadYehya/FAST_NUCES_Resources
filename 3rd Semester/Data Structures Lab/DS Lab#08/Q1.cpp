#include <iostream>
#define MAX 10
using namespace std;
class Stack {
	int top;
	public:
	int a[MAX];
	Stack() {top = -1;}
	bool Push(int x)
	{
		if (top >= (MAX - 1))
		{
			cout << "Stack Overflow" << endl;
			return false;
		}
		else 
		{
			a[++top] = x;
			cout << "Value Pushed in Stack" << endl;
			return true;
		}
	}
	int Pop()
	{
		if (top < 0)
		{
			cout << "Stack Underflow" << endl;
			return 0;
		}
		else 
		{
			int x = a[top--];
			cout << "Value Popped from Stack" << endl;
			return x;
		}
	}
	int Peek()
	{
		if (top < 0) 
		{
			cout << "Stack is Empty" << endl;
			return 0;
		}
		else 
		{
			int x = a[top];
			return x;
		}
	}
	bool isEmpty()
	{
		return (top < 0);
	}
};
int main()
{
	Stack st;
	for(int i = 0 ; i < MAX+1 ; i++)st.Push(i);
	for(int i = 0 ; i < MAX+1 ; i++)st.Pop();
}
