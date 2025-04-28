#include <iostream>
#include <cmath>
using namespace std;
void showChoices(int &c)
{
	do
	{
		cout << "Please choose a conversion:" << endl<< "0.Exit" << endl << "1.Feet and Inches to Meter and Centimeter." << endl;
		cout << "2.Meter and Centimeter to Feet and Inches." << endl;
		cin >> c;
	}
	while (c != 1 && c != 2 && c!= 0);
}
void feetAndInchesToMetersAndCent(float feet , float inch)
{
	float total;
	total = feet + inch/12;
	total *= 0.3048;
	cout << "After conversion:" << endl << "Meters: " << floor(total) << endl << "Centimeters: " << (total - floor(total))*100 << endl;
}
void metersAndCentTofeetAndInches(float meter , float cmeter)
{
	float total;
	total = meter + cmeter / 100;
	total *= 3.28;
	cout << "After conversion:" << endl << "Feet: " << floor(total) << endl << "Inch: " << (total - floor(total))*12 << endl;
}
int main()
{
	int choice;
	do 
	{
		float meter , cmeter , feet , inch;
		showChoices(choice);
		if (choice == 1)
		{
			cout << "Enter feet: ";
			cin >> feet;
			cout << "Enter inches: ";
			cin >> inch;
			feetAndInchesToMetersAndCent(feet , inch);
		}
		else if (choice == 2)
		{
			cout << "Enter meter: ";
			cin >> meter;
			cout << "Enter centimeters: ";
			cin >> cmeter;
			metersAndCentTofeetAndInches(meter , cmeter);
		}
		cout << endl;
	}
	while (choice != 0);
}
