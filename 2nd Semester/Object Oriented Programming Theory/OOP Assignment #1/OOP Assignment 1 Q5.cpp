#include <iostream>
using namespace std;
class Company
{
	private:
		string CompanyName;
		string OwnerName;
		string PetName;
	public:
		//Setters|Mutators for all data members
		void setCompanyName(const string cn)
		{CompanyName = cn;}
		void setName(const string n)
		{OwnerName = n;}
		void setPetName(const string pn)
		{PetName = pn;}
		
		//Getters|Accessors for all data members
		const string getCompanyName()
		{return CompanyName;}
		const string getName()
		{return OwnerName;}
		const string getPetName()
		{return PetName;}
		
		//Constructor
		Company(){}
		Company(string cn , string n , string pn)
		{
			CompanyName = cn;
			OwnerName = n;
			PetName = pn;
		}
};
class Employee
{
	private:
		string FirstName;
		string LastName;
		string EmployeeCode;
		long MonthlySalary;
		string Address;
	public:
		//Setters|Mutators for all data members
		void setFirstName(const string fn)
		{FirstName = fn;}
		void setLastName(const string ln)
		{LastName = ln;}
		void setEmployeeCode(char ec[4])
		{EmployeeCode = ec;}
		void setMonthlySalary(const long ms)
		{
			if (ms <= 100000) MonthlySalary = ms;
			else cout << "Monthly Salary can not exceed 100,000 PKR!" << endl;
		}
		void setAddress(const string a)
		{Address = a;}
		
		//Getters|Accessors for all data members
		const string getFirstName()
		{return FirstName;}
		const string getLastName()
		{return LastName;}
		const string getEmployeeCode()
		{return EmployeeCode;}
		const long getMonthlySalary()
		{return MonthlySalary;}
		const string getAddress()
		{return Address;}
		
		//Constructors
		Employee(){}
		Employee(string e)
		{
			if (e[0] != 'm') 
			{
				EmployeeCode = e;
				cout << "Employee ID set!" << endl;
			}
			else cout << "Invalid Code for regular Employee!" << endl;
		}
		Employee(string e , int i)//i is a dummy variable
		{
			if (e[0] == 'm')
			{
				EmployeeCode = e;
				cout << "Employee ID set!" << endl;
			}
			else cout << "Invalid Code for Manager!" << endl;
		}
};
class Office
{
	private:
		Employee Manager;
		string OfficeCode;
		static long Budget;
	public:
		//Setters|Mutators for all data members
		void setOfficeCode(const char c[3])
		{OfficeCode = c;}
		static void setBudget(const long b)
		{Budget = b;}
		void setManager(Employee m)
		{
			if ((m.getEmployeeCode())[0] == 'm')
			{
				Manager = m;
				cout << "Manager is set!" << endl;
			}
			else cout << "Can not set Manager! Incorrect employee ID!" << endl;
		}
		
		//Getters|Accessors for all data members
		const string getOfficeCode()
		{return OfficeCode;}
		const static long getBudget()
		{return Budget;}
		const Employee getManager()
		{return Manager;}
		
		//Constructors
		Office(){}
		Office(char oc[3] , Employee m)
		{
			OfficeCode = oc;
			Manager = m;
		}
		
		static void DecreaseBudget(const long u)
		{
			if (u <= Budget) Budget -= u;
			else cout << "Insufficient Budget!" << endl;
		}
};
long Office::Budget = 50000000;
int main()
{
	Company("MYH ltd." , "Mohammad Yehya Hayati" , "Tom");
	Office o1;
	
	Employee e1("mesf" , 1);//1 indicates that it is a manager
	Employee e2("mads");//So it gives error message in this since didn't specify that it is a manager by adding extra parameter
	Employee e3("eafd");//Regular Employee
	o1.setManager(e3);//Can't set e2 as manager since his employee code doesn't start with m
	o1.setManager(e1);
	
	e1.setMonthlySalary(100001);//Gives error message as monthly salary cant exceed 100K PKR
	return 3309;
}

