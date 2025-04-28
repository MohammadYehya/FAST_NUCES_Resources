#include <iostream>
#include <conio.h>
using namespace std;
class Item
{
	private:
		string Name;
		int Quantity;
	public:
		//Getters
		const string getName(){return Name;}
		const int getQuantity(){return Quantity;}
		//Setters
		void setName(const string s){Name = s;}
		void setQuantity(const int i){if (i > 0) Quantity = i;}
		//Constructors
		Item(){}
		Item(string s) : Name(s) , Quantity(0) {}
};
class PakistaniFoods : public Item
{
	private:
		float discount;
	public:
		//Constructors
		PakistaniFoods(){discount = 10;}
		PakistaniFoods(string s) : Item(s)
		{discount = 10;}
		//Getters
		const float getDiscount(){return discount;}
};
class Karahi : public PakistaniFoods
{
	private:
		float Price;
	public:
		//Constructors
		Karahi(){Price = 600;}
		Karahi(string s) : PakistaniFoods(s)
		{Price = 600;}
		//Getters
		const float getPrice(){return Price;}
};
class Biryani : public PakistaniFoods
{
	private:
		float Price;
	public:
		//Constructors
		Biryani(){Price = 200;}
		Biryani(string s) : PakistaniFoods(s)
		{Price = 200;}
		//Getters
		const float getPrice(){return Price;}
};
class NonPakistaniFoods : public Item
{
	private:
		float discount;
	public:
		//Constructors
		NonPakistaniFoods(){discount = 7;}
		NonPakistaniFoods(string s) : Item(s)
		{discount = 7;}
		//Getters
		const float getDiscount(){return discount;}
};
class Pasta : public NonPakistaniFoods
{
	private:
		float Price;
	public:
		//Constructors
		Pasta(){Price = 800;}
		Pasta(string s) : NonPakistaniFoods(s)
		{Price = 800;}
		//Getters
		const float getPrice(){return Price;}
};
class Drinks : public Item
{
	private:
		float discount;
		float Price;
	public:
		//Constructors
		Drinks(){discount = 5 ; Price = 100;}
		Drinks(string s) : Item(s)
		{discount = 5 ; Price = 100;}
		//Getters
		const float getDiscount(){return discount;}
		const float getPrice(){return Price;}
};
int main()
{
	Karahi k[2] = {Karahi("Mutton Karahi") , Karahi("Chicken Karahi")};
	Biryani b[2] = {Biryani("Mutton Biryani") , Biryani("Chicken Biryani")};
	Pasta p[2] = {Pasta("Spaghetti") , Pasta("Tortellini")};
	Drinks d[2] = {Drinks("Pepsi") , Drinks("Sprite")};
	int choice;
	int quantity;
	float bill = 0;
	do
	{
		cout << "\t\t\tThe FAST Restaurant" << endl;
		cout << "1.Karahi" << endl << "2.Biryani" << endl << "3.Pasta" << endl << "4.Drinks" << endl << "5.Calculate Bill" << endl << endl;
		cout << "Please enter a choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "1." << k[0].getName() << endl << "2." << k[1].getName() << endl;
				do{cout << "Please enter a choice: ";cin >> choice;}
				while (choice < 0 || choice > 2);
				do{cout << "Please enter quantity: ";cin >> quantity;}
				while (quantity < 0);
				k[choice - 1].setQuantity(quantity);
				bill += k[choice - 1].getPrice() * k[choice - 1].getQuantity() * (100 - k[choice - 1].getDiscount())/100;
				break;
			case 2:
				cout << "1." << b[0].getName() << endl << "2." << b[1].getName() << endl;
				do{cout << "Please enter a choice: ";cin >> choice;}
				while (choice < 0 && choice > 2);
				do{cout << "Please enter quantity: ";cin >> quantity;}
				while (quantity < 0);
				b[choice - 1].setQuantity(quantity);
				bill += b[choice - 1].getPrice() * b[choice - 1].getQuantity() * (100 - b[choice - 1].getDiscount())/100;
				break;
			case 3:
				cout << "1." << p[0].getName() << endl << "2." << p[1].getName() << endl;
				do{cout << "Please enter a choice: ";cin >> choice;}
				while (choice < 0 && choice > 2);
				do{cout << "Please enter quantity: ";cin >> quantity;}
				while (quantity < 0);
				p[choice - 1].setQuantity(quantity);
				bill += p[choice - 1].getPrice() * p[choice - 1].getQuantity() * (100 - p[choice - 1].getDiscount())/100;
				break;
			case 4:
				cout << "1." << d[0].getName() << endl << "2." << d[1].getName() << endl;
				do{cout << "Please enter a choice: ";cin >> choice;}
				while (choice < 0 && choice > 2);
				do{cout << "Please enter quantity: ";cin >> quantity;}
				while (quantity < 0);
				d[choice - 1].setQuantity(quantity);
				bill += d[choice - 1].getPrice() * d[choice - 1].getQuantity() * (100 - d[choice - 1].getDiscount())/100;
				break;
			case 5:
				cout << "Total Bill: " << bill << endl << "Thank You For Shopping!";
				getch();
				break;
			default:
				cout << "Invalid Input!";
				getch();
		}
		system("CLS");
	}
	while(choice != 5);
}

