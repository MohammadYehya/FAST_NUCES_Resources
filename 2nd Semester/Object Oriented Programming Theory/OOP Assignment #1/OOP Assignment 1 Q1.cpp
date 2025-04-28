#include <iostream>
#define eventNumber 2
using namespace std;
class StudentSociety
{
	private:
		string SocietyName;
		string FacultyHead;
		string President;
		string GeneralSecretary;
		int Budget;
		string Events[eventNumber];//Number of events defined as constant
	public:
//		Setters|Mutators for all data members
		void setSocietyName(const string sn)
		{SocietyName = sn;}
		void setFacultyHead(const string fh)
		{FacultyHead = fh;}
		void setPresident(const string p)
		{President = p;}
		void setGeneralSecretary(const string gs)
		{GeneralSecretary = gs;}
		void setBudget(const int b)
		{Budget = b;}
		void setEvents(const string e[eventNumber])
		{for (int i = 0 ; i < eventNumber ; i++) Events[i] = e[i];}
		
//		Getters|Accessors for all data members
		const string getSocietyName()
		{return SocietyName;}
		const string getFacultyHead()
		{return FacultyHead;}
		const string getPresident()
		{return President;}
		const string getGeneralSecretary()
		{return GeneralSecretary;}
		const int getBudget()
		{return Budget;}
		const string *getEvents()
		{return Events;}
		
		//Constructors
		StudentSociety() //Default Constructor
		{
			int i;
			cout << "SocietyName: " ; cin >> SocietyName;
			cout << "FacultyHead: " ; cin >> FacultyHead;
			cout << "President: " ; cin >> President;
			cout << "GeneralSecretary: " ; cin >> GeneralSecretary;
			cout << "Budget: " ; cin >> Budget;
			for (i = 0 ; i < eventNumber ; i++)
			{cout << "Event " << i << ": "; cin >> Events[i];}
		}
		StudentSociety(string sn , string fh , string p , string gs , int b , string e[]) //Parameterized Constructor
		{
			SocietyName = sn;
			FacultyHead = fh;
			President = p;
			GeneralSecretary = gs;
			Budget = b;
			for (int i = 0 ; i < eventNumber ; i++) Events[i] = e[i];
		}
		StudentSociety(int x) //Default Constructor with Poll function
		{
			string *z;
			int i;
			cout << "SocietyName: " ; cin >> SocietyName;
			cout << "FacultyHead: " ; cin >> FacultyHead;
			z = poll();
			President = z[0];
			GeneralSecretary = z[1];
			cout << "Budget: " ; cin >> Budget;
			for (i = 0 ; i < eventNumber ; i++) 
			{cout << "Event " << i << ": "; cin >> Events[i];}
		}
		string *poll() // Poll function is made a pointer since it is returning an array
		{
			string *a = new string[2];
			//Created a Dynamic Memory since after the end of the poll function, local variables would destroy
			//and the memory location would cease to exist. However with DMA, we can resolve that problem.
			int i;
			cout << "President(Poll): " ; cin >> a[0];//Put President(Poll) to incdicate that the poll function was called
			cout << "General Secretary(Poll): " ; cin >> a[1];//Put General Secretary(Poll) to incdicate that the poll function was called
			return a;
		}
		const void display()
		{
			cout << "Society Name: " << SocietyName << endl;
			cout << "Faculty Head: " << FacultyHead << endl;
			cout << "President: " << President << endl;
			cout << "General Secretary: " << GeneralSecretary << endl;
			cout << "Budget: " << Budget << endl;
			cout << "Events: " << endl;for (int i = 0 ; i < eventNumber ; i++) cout << *(Events + i) << endl;
			cout << endl;
		}
};
int main()
{
	string event[eventNumber] = {"Squid Games" , "Coder's Cup"};
	StudentSociety s1("ACM" , "Someone" , "President" , "General Secretary" , 1000 , event);//Example of Parameterized Constructor
	s1.display();
	
	StudentSociety s2(1);//Example of usage of Poll function
	cout << endl;
	s2.display();
	
	StudentSociety s3;//Example of Default Constructor
	cout << endl;
	s3.display();
	return 3309;
}

