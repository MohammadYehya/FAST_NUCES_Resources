#include <iostream>
using namespace std;
class counterType
{
	private:
		int counterCurrent;
		int counterPrevious;
		int counterNext;
	public:
		//Setters|Mutators for all data members but they are not needed as they will be incremented or decremented
		void setcounterCurrent(const int i)
		{if (i > 0) counterCurrent = i;}
		void setcounterPrevious(const int i)
		{if (i > 0) counterPrevious = i;}
		void setcounterNext(const int i)
		{if (i > 0) counterNext = i;}
		
		//Getters|Accessors for all data members
		const int getcounterCurrent()
		{return counterCurrent;}
		const int getcounterPrevious()
		{return counterPrevious;}
		const int getcounterNext()
		{return counterNext;}
		
		
		void incrementCounter() //Function used to increment currentCounter and automatically updates the other counters
		{
			if (counterCurrent >= 0)
			{
				counterCurrent++;
				counterPrevious = counterCurrent - 1;
				counterNext = counterCurrent + 1;
			}
			else cout << "Can not increment counter any further!" << endl;
		}
		void decrementCounter() //Function used to decrement currentCounter and automatically updates the other counters
		{
			if (counterCurrent > 1)
			{
				counterCurrent--;
				counterPrevious = counterCurrent - 1;
				counterNext = counterCurrent + 1;
			}
			else cout << "Can not decrement counter any further!" << endl;
		}
		
		//Constructors
		counterType()//Default Constructor
		{
				counterCurrent = 0;
				counterPrevious = 0;
				counterNext = 0;
		};
		counterType(int c)//Parameterized Constructor
		{
			if (c > 0)
			{
				counterCurrent = c;
				counterPrevious = c - 1;
				counterNext = c + 1;
			}
		}
		~counterType()//Destructor
		{
			counterCurrent = 0;
			counterPrevious = 0;
			counterNext = 0;
			cout << "The destructor has been called and reset the values to zero!" << endl;//Message to alert user that the destructor has been called
			cout << "counterCurrent = " << counterCurrent << endl << "counterPrevious = " << counterPrevious << endl << "counterNext = " << counterNext << endl;
		}
};
int main ()
{
	counterType c(1);//Setting currentCounter to 2
	c.incrementCounter();
	cout << c.getcounterCurrent() << endl << c.getcounterPrevious() << endl << c.getcounterNext() << endl << endl;//Output after increment
	c.incrementCounter();
	cout << c.getcounterCurrent() << endl << c.getcounterPrevious() << endl << c.getcounterNext() << endl << endl;//Output after increment
	c.decrementCounter();
	cout << c.getcounterCurrent() << endl << c.getcounterPrevious() << endl << c.getcounterNext() << endl << endl;//Output after decrement
	c.decrementCounter();
	c.decrementCounter();
	c.decrementCounter();
	cout << c.getcounterCurrent() << endl << c.getcounterPrevious() << endl << c.getcounterNext() << endl << endl;//Shows that cannot be negative
	
}
