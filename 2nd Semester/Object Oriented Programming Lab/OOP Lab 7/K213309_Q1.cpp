#include <iostream>
using namespace std;
class Car
{
	private:
		string numberPlate;
		string ownerName;
	public:
		Car(){}
		Car(string s , string n) : numberPlate(s) , ownerName(n){}
		const string getNumPlate(){return numberPlate;}
		const string getOwnerName(){return ownerName;}
		void setNumPlate(const string n){numberPlate = n;}
		void setOwnerName(const string n){ownerName = n;}
};
class Swift : public Car
{
	protected:
		bool hasCoolant;
	public:
		Swift(){}
		Swift(string s , string n , bool b) : hasCoolant(b) , Car(s,n) {}
		void move(string direction){}
		const bool getHasCoolant (){return hasCoolant;}
		void setHasCoolant(const bool b){hasCoolant = b;}
		void addCoolant()
		{
			if(hasCoolant == false) hasCoolant = true;
			cout << "Coolant has been added for " << getNumPlate() << endl;
		}
};
int main()
{
	Swift S1("ABC-123" , "Ahmed" , true);
	Swift S2("XYZ-789" , "Bilal" , false);
	if (S1.getHasCoolant()) cout << S1.getOwnerName() << ", Owner of " << S1.getNumPlate() << " has a coolant!" << endl;
	else 
	{
		cout << S1.getOwnerName() << ", Owner of " << S1.getNumPlate() << " does not have a coolant!" << endl;
		S1.addCoolant();
	}
	if (S2.getHasCoolant()) cout << S2.getOwnerName() << ", Owner of " << S2.getNumPlate() << " has a coolant!" << endl;
	else 
	{
		cout << S2.getOwnerName() << ", Owner of " << S2.getNumPlate() << " does not have a coolant!" << endl;
		S2.addCoolant();
	}
}

