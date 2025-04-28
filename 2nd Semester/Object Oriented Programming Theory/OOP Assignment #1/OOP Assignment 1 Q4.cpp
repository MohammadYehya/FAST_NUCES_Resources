#include <iostream>
#include <conio.h>
using namespace std;
class BankAccount
{
	private:
		float Balance;
		int NumberOfTransactions;
		float InterestAmount;
	public:
		//Setters|Mutators for all data members
		void set_Balance(const float b)
		{Balance = b;}
		void set_NumberOfTransactions(const int n)
		{NumberOfTransactions = n;}
		void set_Interest(const float i)
		{
			if (i <= Balance)//Cannot add an amount that is less than your balance
			{
				InterestAmount = i;
				Balance -= i;
				cout  << "The amount has been added for interest!" << endl;
			}
			else 
			{
				cout << "Insufficient Balance!" << endl;
			}
		}
		
		//Getters|Accessors for all data members
		const float get_Balance()
		{return Balance;}
		const int get_NumberOfTransactions()
		{return NumberOfTransactions;}
		
		//Default Constructor
		BankAccount()
		{
			Balance = 0;
			NumberOfTransactions = 0;
			InterestAmount = 0;
		}
		
		
		void deposit(const float d)//Function to deposit an amount to the bank
		{
			Balance += d;
			NumberOfTransactions++;
			cout << "The amount has been deposited!";
		}
		void withdraw(const float w)//Function to withdraw an amount from the bank and cannot be greater than the current balance
		{
			if (Balance < w)
			{cout << "Insufficient Balance!" << endl;}
			else
			{
				Balance -= w;
				NumberOfTransactions++;
				cout << "The amount has been withdrawn!";
			}
		}
		float calinterest(const float R , const int N)//Function to calculate interest for a given period of time
		{return InterestAmount * R * N;}
		
};
int main()
{
	int choice;
	BankAccount b;
	float x;
	do
	{
		cout << "\t\tStandard Charted Bank" << endl;
		cout << "1.Display the account Balance" << endl << "2.Display the number of transactions" << endl;
		cout << "3.Display interest earned for this period" << endl << "4.Make a deposit" << endl << "5.Make a withdrawal" << endl;
		cout << "6.Add interest for this period" << endl << "7.Exit the program" << endl ;
		cout << endl << "Please pick a choice: ";
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{
			cout << "The account Balance is: " << b.get_Balance() << endl << "Press any key to continue";
			getch();
		}
		if (choice == 2)
		{
			cout << "The Number of Transactions is: " << b.get_NumberOfTransactions() << endl << "Press any key to continue";
			getch();
		}
		if (choice == 3)
		{
			cout << "The interest after a year at the rate of 2% per annum is: " << b.calinterest(0.02 , 1) << endl << "Press any key to continue";
			getch();
		}
		if (choice == 4)
		{
			cout << "Enter amount to deposit: ";
			cin >> x;
			if (x < 0)
			{
				cout << "Invalid Amount!" << endl;
				getch();
				system("CLS");
				continue;
			}
			b.deposit(x);
			cout << endl << "Press any key to continue";
			getch();
		}
		if (choice == 5)
		{
			cout << "Enter amount to withdraw: ";
			cin >> x;
			if (x < 0)
			{
				cout << "Invalid Amount!" << endl;
				getch();
				system("CLS");
				continue;
			}
			b.withdraw(x);
			cout << endl << "Press any key to continue";
			getch();
		}
		if (choice == 6)
		{
			cout << "Enter amount to add for interest: ";
			cin >> x;
			b.set_Interest(x);
			cout << endl << "Press any key to continue";
			getch();
		}
		system("CLS");
	}
	while (choice != 7);
}

