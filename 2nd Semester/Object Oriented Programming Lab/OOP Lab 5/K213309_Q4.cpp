#include <iostream>
using namespace std;
class dayType
{
	private:
		string day;
		int count;
	public:
		void setDay(const string n)
		{day = n;}
		const string getDay()
		{return day;}
		const void printDay()
		{cout << day << endl;}
		const string NextDay()
		{return update(count + 1);}
		const string prevDay()
		{return update(count - 1);}
		const string calcDay(int i)
		{return update(count + i);}
		
		const string update(int i)
		{
			switch(i%7)
			{
				case 0:
					return "Mon";
				case 1:
					return "Tue";
				case 2:
					return "Wed";
				case 3:
					return "Thu";
				case 4:
					return "Fri";
				case 5:
					return "Sat";
				case 6:
					return "Sun";
			}
		}
		
		dayType()
		{count = 7;}
		dayType(string d, int c)
		{
			day = d;
			count = c + 7;
		}
};
int main()
{
	dayType d("Mon" , 0);
	cout << d.calcDay(4);
}
