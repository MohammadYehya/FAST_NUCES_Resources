#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> stack;
string literal;

void Grammar_E();
void Grammar_T();
void Grammar_F();

void CheckIfEqual(char c)
{
    if (literal[0] == c) literal.erase(0, 1);
	else 
	{
        cout << "Invalid Syntax" << endl;
        exit(0);
    }
}

void Grammar_E()
{  
	Grammar_T();
    stack.push_back("E");
    while (literal.length() > 0 && literal[0] == '+')
	{
        CheckIfEqual('+');
        Grammar_T();
        stack.push_back("E+T");
    }
}

void Grammar_T()
{
    Grammar_F();
    stack.push_back("T");
    while (literal.length() > 0 && literal[0] == '*')
	{
        CheckIfEqual('*');
        Grammar_F();
        stack.push_back("T*F");
    }
}

void Grammar_F() 
{
    if (literal[0] == '(') 
	{
        CheckIfEqual('(');
        Grammar_E();
        CheckIfEqual(')');
        stack.push_back("(E)");
        stack.push_back("F");
    }
	else if (literal[0] == 'a') 
	{
        CheckIfEqual('a');
        stack.push_back("a");
        stack.push_back("F");
    }
	else
	{
        cout << "Invalid Syntax" << endl;
        exit(0);
    }
}

int main(int argc, char *argv[]) 
{
	getline(cin, literal, '\n');
    Grammar_E();
    if (literal.length() == 0)
	{
        while(!stack.empty())
        {
        	cout << stack.back() << '\n';
        	stack.pop_back();
		}
        cout << "Valid Syntax" << endl;
    } 
	else cout << "Invalid Syntax" << endl;
    return 0;
}
