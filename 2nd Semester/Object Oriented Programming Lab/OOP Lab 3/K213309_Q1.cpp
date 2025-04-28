#include <iostream>
using namespace std;
class student
{
	private:
		string name;
		int ID;
		string DepartmentName;
		string SubjectName[6];
		float marks[6];
		float total;
	public:
		void set_Name(string n)
		{name = n;}
		void set_ID(int i)
		{ID = i;}
		void set_DepartmentName(string dn)
		{DepartmentName = dn;}
		void set_SubjectName(string s[6])
		{
			for (int i = 0 ; i < 6 ; i++)
			{
				SubjectName[i] = s[i];
			}
		}
		void set_marks(float m[6])
		{
			for (int i = 0 ; i < 6 ; i++)
			{
				marks[i] = m[i];
			}
		}
		void set_total(float t)
		{total = t;}
		
		string get_Name()
		{return name;}
		int get_ID()
		{return ID;}
		string get_DepartmentName()
		{return DepartmentName;}
		string get_SubjectName(int n)
		{return SubjectName[n];}
		float get_Marks(int n)
		{return marks[n];}
		float get_total()
		{return total;}
		
		float get_per()
		{return (marks[1] + marks[2] + marks[3] + marks[4] + marks[5] + marks[0]) / total * 100;}
		
		char get_grade()
		{
			if (get_per() < 50)
			{return 'F';}
			else if (get_per() < 60)
			{return 'E';}
			else if (get_per() < 70)
			{return 'D';}
			else if (get_per() < 80)
			{return 'C';}
			else if (get_per() < 90)
			{return 'B';}
			else 
			{return 'A';}
		}
		void get_info()
		{
			cout << "Name: " << name << endl;
			cout << "ID: " << ID << endl;
			cout << "Percentage: " << get_per() << endl;
			cout << "Grade: " << get_grade() << endl;
		}
};
int main()
{
	float m[6] = {100,90,80,70,60,50};
	string su[6] = {"DLD" , "DE" , "CPS" , "PST" , "OOP" , "PF"};
	student s;
	s.set_Name("ABC");
	s.set_ID(1);
	s.set_DepartmentName("CS");
	s.set_SubjectName(su);
	s.set_marks(m);
	s.set_total(600);
	s.get_info();
}

