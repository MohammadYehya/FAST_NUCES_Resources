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
		//Setters|Mutators for all data members
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
		
		//Getters|Accessors for all data members
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
		
		//Constructors
		CD(){}//Default Constructor
		CD(int a , int r)//Parametarized Constructor
		{
			countAvailable = a;
			countRented = r;
		}
		
		void incAvailable()//Function to check if a all the CD's of a movie have been returned or not, if not then increment countAvailable
		{
			if (countRented > 0)
			{
				countAvailable++;
				countRented--;
				cout << "The movie has been returned!";
			}
			else cout << "All CD's have already been returned!" << endl;
		}
		void incRented()//Function to check if a all the CD's of a movie have been rented or not, if not then increment countRented
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
	CD StarWars(10,0);//Create Star Wars movie CD object with 10 available CD's and zero rented CS's
	do //Menu with simple do-while and switch statement
	{
		cout << "\t\t\tMovie Rental Store" << endl;
		cout << "1.Number of CD's available" << endl << "2.Number of CD's rented" << endl << "3.Rent a movie" << endl << "4.Return a movie" << endl << "5.Exit" << endl;
		cout << endl << "Please enter a choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "The number of CD's available: " << StarWars.getAvailable() << endl;
				getch();//Used to show output to user. Used from conio.h header file
				break;
			case 2:
				cout << "The number of CD's rented: " << StarWars.getRented() << endl;
				getch();
				break;
			case 3:
				StarWars.incRented();
				getch();
				break;
			case 4:
				StarWars.incAvailable();
				getch();
				break;
			case 5:
				break;
			default:
				cout << "Invalid Input!" << endl;
				getch();
				break;
		}
		system("CLS");//Used to clear screen
	}
	while (choice != 5);
}
