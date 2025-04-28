#include <iostream>
using namespace std;
class Account
{
	private:
		int AccountId;
		string AccountName;
		string Branch;
		int Amount;
		int Tax;	
	public:
		void setAccountId(const int i)
		{AccountId = i;}
		void setAccountName(const string n)
		{AccountName = n;}
		void setBranch(const string b)
		{Branch = b;}
		void setAmount(const int a)
		{Amount = a;}
		void setTax(const int t)
		{Tax = t;}
		
		const int getAccountId()
		{return AccountId;}
		const string getAccountName()
		{return AccountName;}
		const string getBranch()
		{return Branch;}
		const int getAmount()
		{return Amount;}
		const int getTax()
		{return Tax;}
		
		Account(int i , string n , string b , int a , int t):Tax(t)
		{
			AccountId = i;
			AccountName = n;
			Branch = b;
			Amount = a;
		}
		
		float calc()
		{
			return Amount * Tax / 100;
		}
};
int main()
{
	Account savingsAccount(3309 , "MYH" , "FAST-KHI" , 1000 , 5); 
	Account currentAccount(3212 , "AA" , "FAST-ISL" , 5000 , 3);
	
	cout << "Savings Account" << endl << "Account Name: " << savingsAccount.getAccountName() << endl << "Account ID: " << savingsAccount.getAccountId() << endl << "Amount: " << savingsAccount.getAmount() << endl << "Tax: " << savingsAccount.getTax() << "%" << endl << "Tax Amount: " << savingsAccount.calc() << endl;
	cout << endl;
	cout << "Current Account" << endl << "Account Name: " << currentAccount.getAccountName() << endl << "Account ID: " << currentAccount.getAccountId() << endl << "Amount: " << currentAccount.getAmount() << endl << "Tax: " << currentAccount.getTax() << "%" << endl << "Tax Amount: " << currentAccount.calc() << endl;
}


