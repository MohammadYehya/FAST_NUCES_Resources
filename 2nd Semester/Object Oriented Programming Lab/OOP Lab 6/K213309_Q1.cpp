#include <iostream>
using namespace std;
class Student
{
	private:
		string Name;
		int Age;
		string Institute;
	public:
		//Constructor
		Student(){}
		Student(string s , int a , string i) : Name(s) , Age(a) , Institute(i) {}
		//Setters
		void setName(const string n) {Name = n;}
		void setAge(const int a) {Age = a;}
		void setInstitute(const string i) {Institute = i;}
		//Getters
		const string getName() {return Name;}
		const int getAge() {return Age;}
		const string getInstitute() {return Institute;}
};
class TrackAndFieldMember : public Student
{                                        
	private:
		string SportsName;
		int ShirtNumber;
	public:
		//Constructors
		TrackAndFieldMember() : SportsName("Track and field") {}
		TrackAndFieldMember(string s , int a , string i , int n) : SportsName("Track and field") , ShirtNumber(n) , Student(s , a , i) {}
		//Setters
		void setSportsName(const string s) {SportsName = s;}
		void setShirtNumber(const int i) {ShirtNumber = i;}
		//Getters
		const string getSportsName() {return SportsName;}
		const int getShirtNumber() {return ShirtNumber;}
		
		void display()
		{
			cout << "Name: " << getName() << endl;
			cout << "Age: " << getAge() << endl;
			cout << "Institute: " << getInstitute() << endl;
			cout << "Sports Name: " << SportsName << endl;
			cout << "Shirt Number: " << ShirtNumber << endl;
			cout << endl;
		}
};
class BasketBallMember : public Student
{
	private:
		string SportsName;
		int ShirtNumber;
	public:
		//Constructors
		BasketBallMember() : SportsName("Basketball") {}
		BasketBallMember(string s , int a , string i , int n) : SportsName("Basketball") , ShirtNumber(n) , Student(s , a , i) {}
		//Setters
		void setSportsName(const string s) {SportsName = s;}
		void setShirtNumber(const int i) {ShirtNumber = i;}
		//Getters
		const string getSportsName() {return SportsName;}
		const int getShirtNumber() {return ShirtNumber;}
		
		void display()
		{
			cout << "Name: " << getName() << endl;
			cout << "Age: " << getAge() << endl;
			cout << "Institute: " << getInstitute() << endl;
			cout << "Sports Name: " << SportsName << endl;
			cout << "Shirt Number: " << ShirtNumber << endl;
			cout << endl;
		}
};
class FootballMember : public Student
{
	private:
		string SportsName;
		int ShirtNumber;
	public:
		//Constructors
		FootballMember() : SportsName("Football") {}
		FootballMember(string s , int a , string i , int n) : SportsName("Football") , ShirtNumber(n) , Student(s , a , i) {}
		//Setters
		void setSportsName(const string s) {SportsName = s;}
		void setShirtNumber(const int i) {ShirtNumber = i;}
		//Getters
		const string getSportsName() {return SportsName;}
		const int getShirtNumber() {return ShirtNumber;}
		
		void display()
		{
			cout << "Name: " << getName() << endl;
			cout << "Age: " << getAge() << endl;
			cout << "Institute: " << getInstitute() << endl;
			cout << "Sports Name: " << SportsName << endl;
			cout << "Shirt Number: " << ShirtNumber << endl;
			cout << endl;
		}
};
int main()
{
	TrackAndFieldMember t1("Ahmed" , 19 , "FAST" , 43);
	BasketBallMember b1("Asad" , 18 , "HABIB" , 21);
	FootballMember f1("Shayan" , 19 , "NED" , 49);
	t1.display();
	b1.display();
	f1.display();
}
	