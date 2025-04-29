#include <iostream>
#include <stack>
using namespace std;
typedef string equation;

int PrecendenceCalc(char c)
{
	if(c == '^')return 3;
	else if(c == '*' || c == '/') return 2;
	else if(c == '+' || c == '-') return 1;
	else return -1;
}
void InfixToPostfix(equation eq)
{
	stack<char> st;
	string Postfix;
	for (int i = 0; i < eq.length(); i++) 
	{
		char c = eq[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) Postfix += c;
		else if (c == '(') st.push('(');
		else if (c == ')') 
		{
			while (st.top() != '(')
			{
				Postfix += st.top();
				st.pop();
			}
			st.pop();
		}
		else 
		{
			while (!st.empty() && PrecendenceCalc(eq[i]) <= PrecendenceCalc(st.top())) 
			{
				Postfix += st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	while (!st.empty()) 
	{
		Postfix += st.top();
		st.pop();
	}
	cout << Postfix << endl;
}
int main()
{
	//Took Help from Sir Slides
	equation eq = "a+b*(c^d-e)^(f+g*h)-i";
	cout << "Infix Equation:\t\t" << eq;
	cout << endl << "Postfix Equation:\t";
	InfixToPostfix(eq);
}

