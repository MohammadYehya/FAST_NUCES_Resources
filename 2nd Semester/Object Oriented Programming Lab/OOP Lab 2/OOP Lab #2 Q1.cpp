#include <iostream>
using namespace std;
float resbill(int p);
float busibill(int n , int p);
int main()
{
	int accno , premno , basicservconc;
	char custcode;
	cout << "Please enter account number: ";
	cin >> accno;
	do
	{
		cout << "Please enter R if you are a Residential customer and B if you are a Business customer: ";
		cin >> custcode;
	}
	while(custcode != 'R' && custcode != 'B');
	cout << "Please enter the number of premium channels: ";
	cin >> premno;
	if (custcode == 'R')
	{
		cout << "Account Number: " << accno << endl << "Billing Amount: " << resbill(premno);
	}
	else if (custcode == 'B')
	{
		cout << "Please enter number of basic service connections: ";
		cin >> basicservconc ;
		cout << "Account Number: " << accno << endl << "Billing Amount: " << busibill(basicservconc , premno);
	}
}
float resbill(int p)
{
	return (4.5 + 20.5 + 7.5 * p);
}

float busibill(int n , int p)
{
	return (15 + 75 + (n>10?(5*(n-10)):0) + 50 * p);
}
