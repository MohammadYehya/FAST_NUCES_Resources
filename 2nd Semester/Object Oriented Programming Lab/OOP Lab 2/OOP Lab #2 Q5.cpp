#include <iostream>
using namespace std;
float billing();
int main()
{
	float bill;
	bill = billing();
	cout << "The total bill is: " << bill;
}
float billing()
{
	float rate , time;
	char income;
	cout << "Low income? (Please enter Y or N): ";
	cin >> income;
	cout << "Please enter consulting time in mins: ";
	cin >> time;
	cout << "Please enter hourly rate: ";
	cin >> rate;
	if (income == 'Y')
	{
		if (time <= 30)
		{
			return 0;
		}
		else if (time > 30)
		{
			return (rate * (time - 30)/60 * 0.4);
		}
	}
	else if (income == 'N')
	{
		if (time <= 20)
		{
			return 0;
		}
		else if (time > 20)
		{
			return (rate * (time - 20)/60 * 0.7);
		}
	}
	else return -1;
}
