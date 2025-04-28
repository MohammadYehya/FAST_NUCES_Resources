#include <iostream>
using namespace std;
class counterType
{
	private:
		int counterCurrent;
		int counterPrevious;
		int counterNext;
	public:
		void setcounterCurrent(const int i)
		{counterCurrent = i;}
		void setcounterPrevious(const int i)
		{counterPrevious = i;}
		void setcounterNext(const int i)
		{counterNext = i;}
		const int getcounterCurrent()
		{return counterCurrent;}
		const int getcounterPrevious()
		{return counterPrevious;}
		const int getcounterNext()
		{return counterNext;}
		
		void incrementCounter()
		{
			if (counterCurrent >= 0)
			{
				counterCurrent++;
				counterPrevious = counterCurrent - 1;
				counterNext = counterCurrent + 1;
			}
		}
		void decrementCounter()
		{
			if (counterCurrent > 1)
			{
				counterCurrent--;
				counterPrevious = counterCurrent - 1;
				counterNext = counterCurrent + 1;
			}
		}
		
		counterType(){};
		counterType(int c)
		{
			if (c > 0)
			{
				counterCurrent = c;
				counterPrevious = c - 1;
				counterNext = c + 1;
			}
		}
		~counterType()
		{
			counterCurrent = 0;
			counterPrevious = 0;
			counterNext = 0;
			cout << "The destructor has been called!";
		}
};
int main ()
{
	counterType c(2);
	c.incrementCounter();
	cout << c.getcounterCurrent() << endl << c.getcounterPrevious() << endl << c.getcounterNext() << endl << endl;
	c.incrementCounter();
	cout << c.getcounterCurrent() << endl << c.getcounterPrevious() << endl << c.getcounterNext() << endl << endl;
	c.decrementCounter();
	cout << c.getcounterCurrent() << endl << c.getcounterPrevious() << endl << c.getcounterNext() << endl << endl;
	c.decrementCounter();
	c.decrementCounter();
	c.decrementCounter();
	cout << c.getcounterCurrent() << endl << c.getcounterPrevious() << endl << c.getcounterNext() << endl << endl;
	
}

