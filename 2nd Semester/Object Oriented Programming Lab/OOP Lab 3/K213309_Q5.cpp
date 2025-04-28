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
		BankAccount()
		{
			Balance = 0;
			NumberOfTransactions = 0;
			InterestAmount = 0;
		}
		void set_Balance(float b)
		{Balance = b;}
		void set_NumberOfTransactions(int n)
		{NumberOfTransactions = n;}
		float get_Balance()
		{return Balance;}
		int get_NumberOfTransactions()
		{return NumberOfTransactions;}
		void set_Interest(float i)
		{
			if (i <= Balance)
			{
				InterestAmount = i;
				cout  << "The amount has been added for interest!" << endl;
			}
			else 
			{
				cout << "Insufficient Balance!" << endl;
			}
		}
		
		void deposit(float d)
		{
			Balance += d;
			NumberOfTransactions++;
			cout << "The amount has been deposited!";
		}
		void withdraw(float w)
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
		float calinterest(float R , int N)
		{return InterestAmount * R * N;}
		
};
int main()
{
	int choice;
	BankAccount b;
	float x;
	do
	{
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
			b.deposit(x);
			cout << endl << "Press any key to continue";
			getch();
		}
		if (choice == 5)
		{
			cout << "Enter amount to withdraw: ";
			cin >> x;
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

