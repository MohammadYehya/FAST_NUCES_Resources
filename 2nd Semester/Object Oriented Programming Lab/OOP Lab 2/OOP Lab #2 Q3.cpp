#include <iostream>
using namespace std;
float regserv(float mins);
float permserv(float minsday , float minsnight);
int main()
{
	int accno;
	float mins , minsday , minsnight;
	char servcode;
	cout << "Please enter Account Number: ";
	cin >> accno;
	cout << "Please enter R for Regular Service and P for Premium Service: ";
	cin >> servcode;
	if (servcode != 'R' && servcode != 'P')
	{
		cout << "Error! Incorrect code!" << endl;
	}
	if (servcode == 'R')
	{
		cout << "Enter number of minutes the service was used: ";
		cin >> mins;
		cout << "Account Number:" << accno << endl << "Type of Service: " << servcode << endl << "Number of Minutes: " << mins << endl << "Amount due: " << regserv(mins);
	}
	if (servcode == 'P')
	{
		cout << "Enter number of minutes the service was used in the day: ";
		cin >> minsday;
		cout << "Enter number of minutes the service was used in the night: ";
		cin >> minsnight;
		cout << "Account Number:" << accno << endl << "Type of Service: " << servcode << endl << "Number of Minutes: " << minsday + minsnight << endl << "Amount due: " << permserv(minsday , minsnight);
	}
	
}
float regserv(float mins)
{	
	return (10 + (mins > 50 ?(mins - 50) * 0.2:0));
}
float permserv(float minsday , float minsnight)
{
	return (25 + (minsday > 75 ? (minsday - 75 )* 0.1 : 0) + (minsnight > 100 ? (minsnight - 100) * 0.05 : 0));
}
