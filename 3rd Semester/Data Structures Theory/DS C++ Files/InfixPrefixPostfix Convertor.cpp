#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Convertor
{
	public:
		int prec(char c)
		{
			if (c == '^') return 3;
			else if (c == '/' || c == '*') return 2;
			else if (c == '+' || c == '-') return 1;
			else return 0;
		}
		string StringRev(string s)
		{
			int n = s.size();
			for (int i = 0 ; i < n/2 ; i++)
			{
				char temp = s[i];
				s[i] = s[n-i-1];
				s[n-i-1] = temp;
			}
			return s;
		}
		string InfixToPostfix(string s)
		{
			stack<char> st;
			string result;
			for (int i = 0; i < s.length(); i++)
			{
				char c = s[i];
				if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) result += c;
		        else if (c == '(') st.push('(');
		        else if (c == ')') 
				{
					while (st.top() != '(')
					{
					    result += st.top();
					    st.pop();
					}
					st.pop();
				}
				else 
				{
					while (!st.empty() && prec(s[i]) <= prec(st.top())) 
					{
						result += st.top();
						st.pop();
					}
					st.push(c);
				}
			}
			while (!st.empty()) 
			{
				result += st.top();
				st.pop();
			}
			return result;
		}
		string InfixToPrefix(string s)
		{
			stack<char> st;
			s = StringRev(s);
			int n = s.size();
			for (int i = 0 ; i < n ; i++)
			{
				if(s[i] == '(') s[i] = ')';
				else if (s[i] == ')') s[i] = '(';
			}
			s = InfixToPostfix(s);
			return StringRev(s);
		}
		string PostfixToInfix(string s)
		{
			stack<string> st;
			for (int i = 0 ; i < s.length() ; i++)
			{
				char c = s[i];
				if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
				{
					string op(1, c);
					st.push(op);
				}
				else
				{
					string op1 = st.top();
					st.pop();
					string op2 = st.top();
					st.pop();
					st.push("(" + op2 + c + op1 + ")");
				}
			}
			return st.top();
		}
		string PostfixToPrefix(string s)
		{
			stack<string> st;
			for(int i = 0 ; i < s.size() ; i++)
			{
				char c = s[i];
				if(prec(c))
				{
					string op1 = st.top();
					st.pop();
					string op2 = st.top();
					st.pop();
					st.push(c + op2  + op1);
				}
				else
				{
					st.push(string(1,c));
				}
			}
			string ans = "";
			while(!st.empty())
			{
				ans+=st.top();
				st.pop();
			}
			return ans;
		}
		string PrefixToPostfix(string s)
		{
			stack<string> st;
			for(int i = s.size()-1 ; i >= 0 ; i--)
			{
				char c = s[i];
				if(prec(c))
				{
					string op1 = st.top();
					st.pop();
					string op2 = st.top();
					st.pop();
					st.push(op1  + op2 + c);
				}
				else st.push(string(1,c));
			}
			return st.top();
		}
		string PrefixToInfix(string s)
		{
			stack<string> st;
			for(int i = s.size()-1 ; i >= 0 ; i--)
			{
				char c = s[i];
				if(prec(c))
				{
					string op1 = st.top();
					st.pop();
					string op2 = st.top();
					st.pop();
					st.push("(" + op1 + c + op2 + ")");
				}
				else st.push(string(1,c));
			}
			return st.top();
		}
};
int main()
{
	Convertor C;
	cout << C.InfixToPostfix("(A*B)+C") << endl;//AB*C+
	cout << C.InfixToPrefix("(A*B)+C") << endl;//+*ABC
	cout << C.PostfixToInfix("AB*C+") << endl;//((A*B)+C)
	cout << C.PostfixToPrefix("AB*C+") << endl;
	cout << C.PrefixToPostfix("+*ABC") << endl;
	cout << C.PrefixToInfix("+*ABC") << endl;
}
