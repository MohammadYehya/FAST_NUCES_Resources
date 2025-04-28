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
		float price;
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
		void setPrice(const float p)
		{price = p;}
		
		const float getPrice()
		{return price;}
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
		CD(string n , string p , string s , int a , int r , float pr)
		{
			Name = n;
			Producer = p;
			StudioInformation = s;
			countAvailable = a;
			countRented = r;
			price = pr;
		}
		
		int incAvailable()
		{
			if (countRented > 0)
			{
				countAvailable++;
				countRented--;
				cout << "The movie has been returned!";
				return 1;
			}
			else 
			{
				cout << "You don't own that CD!" << endl;
				return 0;
			}
		}
		int incRented()
		{
			if (countAvailable > 0)
			{
				countAvailable--;
				countRented++;
				cout << "The movie has been rented!" << endl;
				return 1;
			}
			else 
			{
				cout << "No more CD's available!" << endl;
				return 0;
			}
		}
};
class Member
{
	private:
		string name;
		int ID;
		int count;
		float amount;
		string C[100];
	public:
		void setName(const string n)//Sets the name
		{name = n;}
		void setCount(const int c)//Sets the count
		{if (c >= 0) count = c;}
		void setAmount(const float f)//Sets the amount
		{if (f >= 0) amount = f;}
		void setCDName(const string c)
		{
			C[count++] = c;
		}
		
		const string getName()//Returns the name
		{return name;}
		const int getCount()//Returns the count
		{return count;}
		const int getAmount()//Returns the amount
		{return amount;}
		const int getID()//Returns the ID
		{return ID;}
		const string getCDName(int i)
		{return C[i];}
		
		Member(){}
		Member(int i , int c , float a)
		{
			ID = i;
			count = c;
			amount = a;
		}
};
int main()
{
	int choice , pick;
	float newpr;
	char mem;
	string newname;
	Member m1(3309,0,0);
	m1.setName("Mohammad Yehya");
	CD c[2] = {CD("Lord of The Rings" , "Peter Jackson" , "New Line Cinema" , 1 , 0 , 100) , 
			   CD("Jumanji" , "William Teitler" , "Radar Pictures" ,10 ,0 , 50)};
	do
	{
		cout << "\t\t\tMovie Rental Store" << endl << "1.Rent a Movie" << endl << "2.Manage CD Details" << endl << "3.Exit" << endl;
		cout << endl << "Please enter an option: " ;
		cin >> choice;
		cout << endl;
		switch(choice)
		{
			case 1:
				cout << "Please pick a movie: " << endl;
				for (int i = 0 ; i < 2 ; i++) cout << " " << i << "." << c[i].getName() << endl;
				cout << endl;
				do
				{
					cout << "Please pick in the range: ";
					cin >> pick;
				}
				while (pick < 0 || pick >= 2);
				cout << "Is a member?(Y/N)";
				do
				{
					cin >> mem;
					if (mem == 'Y')
					{
						if (c[pick].incRented() == 1)
						{
							m1.setCDName(c[pick].getName());
							if (m1.getCount()%5 == 0) cout << "Total Bill: " << (c[pick].getPrice() - 20) * 0.95 << endl;
							else cout << "Total Bill: " << c[pick].getPrice() * 0.95;
						}
					}
					else if (mem == 'N')
					{
						if (c[pick].incRented() == 1)
						{
							cout << "Total Bill: " << c[pick].getPrice() << endl;
						}
					}
				}
				while(mem != 'Y' && mem != 'N');
				getch();
				break;
			case 2:
				cout << "Please choose a movie to manage: " << endl;
				for (int i = 0 ; i < 2 ; i++) cout << " " << i << "." << c[i].getName() << endl;
				cout << endl;
				do
				{
					cout << "Please pick in the range: ";
					cin >> choice;
				}
				while (choice < 0 || choice >= 2);
				cout << "Please choose an option: " << endl << "1.Change Price" << endl << "2.Change Name" << endl;
				do
				{
					cout << "Enter in the range: ";
					cin >> pick;
				}
				while (pick <= 0 || pick > 2);
				switch(pick)
				{
					case 1:
						cout << "Enter new price: ";
						cin >> newpr;
						c[choice].setPrice(newpr);
						cout << "The price has been updated!";
						break;
					case 2:
						cout << "Enter new name: ";
						cin >> newname;
						c[choice].setName(newname);
						cout << "The name has been updated!";
						break;
				}
				getch();
				break;
		}
		system("CLS");
	}
	while(choice != 3);
}

