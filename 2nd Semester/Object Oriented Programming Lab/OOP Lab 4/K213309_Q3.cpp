#include <iostream>
#include <conio.h>
using namespace std;
class CD
{
	private:
		string Name;
		string Producer;
		string StudioInformation;
		int countAvailable;
		int countRented;
	public:
		void setName(const string n)
		{Name = n;}
		void setProducer(const string p)
		{Producer = p;}
		void setStudioInformation(const string s)
		{StudioInformation = s;}
		void setAvailable(const int i)
		{countAvailable = i;}
		void setRented(const int i)
		{countRented = i;}
		
		const string getName()
		{return Name;}
		const string getProducer()
		{return Producer;}
		const string getStudioInformation()
		{return StudioInformation;}
		const int getAvailable()
		{return countAvailable;}
		const int getRented()
		{return countRented;}
		
		CD(){}
		CD(int a , int r)
		{
			countAvailable = a;
			countRented = r;
		}
		
		void incAvailable()
		{
			if (countRented > 0)
			{
				countAvailable++;
				countRented--;
				cout << "The movie has been returned!";
			}
			else cout << "All CD's have been returned!" << endl;
		}
		void incRented()
		{
			if (countAvailable > 0)
			{
				countAvailable--;
				countRented++;
				cout << "The movie has been rented!" << endl;
			}
			else cout << "No more CD's available!" << endl;
		}
};
int main ()
{
	int choice;
	CD LordOfTheRings(10,0);
	do
	{
		cout << "1.Number of CD's available" << endl << "2.Number of CD's rented" << endl << "3.Rent a movie" << endl << "4.Return a movie" << endl << "5.Exit" << endl;
		cout << endl << "Please enter a choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "The number of CD's available: " << LordOfTheRings.getAvailable() << endl;
				getch();
				break;
			case 2:
				cout << "The number of CD's rented: " << LordOfTheRings.getRented() << endl;
				getch();
				break;
			case 3:
				LordOfTheRings.incRented();
				getch();
				break;
			case 4:
				LordOfTheRings.incAvailable();
				getch();
				break;
		}
		system("CLS");
	}
	while (choice != 5);
}

