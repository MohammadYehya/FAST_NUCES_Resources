#include<iostream>
#define n 5
using namespace std;
class date
{
	private:
		int day;
		int month;
		int year;
	public:
		date(){day = 0 ; month = 0 ; year = 0;}
		date(int x , int y , int z){day = x ; month = y ; year = z;}
		operator =(date x){day = x.day ; month = x.month ; year = x.year;}
		bool operator <(date x)
		{
			if (year < x.year)return true;
			if (month < x.month)return true;
			return false;
		}
		friend SortDate(date *arr);
		display(){cout << day << " " << month << " " << year << endl;}
};
SortDate(date *arr)
{
	int min , j;
	for (int i = 0 ; i < n -1 ; i++)
	{
		min = i;
		for (j = i + 1 ; j < n ; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			date temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}
int main()
{
	date x[5] = {date(12,12,2012) , date(8,9,2010) , date(3,1,2000) , date(11,4,1999) , date(6,9,2001)};
	cout << "Original Array: " << endl;
	for (int i = 0 ; i < n ; i++) x[i].display();
	
	SortDate(x);
	
	cout << endl << "Sorted Array: " << endl;
	for (int i = 0 ; i < n ; i++) x[i].display();
}
