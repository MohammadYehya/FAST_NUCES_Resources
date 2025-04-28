#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define MaxPatientNumber 200 // MaxPatientNumber is equal to MaxBedNumber so no need to declare another constant
#define MaxDoctorNumber 40
#define MaxStaffNumber 100
using namespace std;

HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);//For Color purposes not in course

class Patient;
class Employee;
class Doctor;
class FrontDeskStaff;
class Admin;
class HospitalSystem;
class Ward;
class Bed;

class Ward
{
	private:
		char WardName;//The name of a Ward is a Capital Letter from A-T (Meaning there are 20 Wards)
	public:
		friend class Patient;
		Ward()
		{
			WardName = '\0';
		}
		const char  getWardName(){return WardName;}
		void setWardName(char s){WardName = s;}
		virtual void Status() = 0;//Pure Virtual Function Implemented to make Ward Class Abstract
};
class Bed : public Ward
{
	private:
		int BedNumber;
		int PatientID;
	public:
		friend class Patient;//Made friend class so that we can access private members in other class without the need of setters and getters
		friend class HospitalSystem;//^
		friend class FrontDeskStaff;//^
		friend class Admin;			//^
		bool IsEmpty() 
		{
			if(PatientID == 0) return true;
			return false;
		}
		Bed()
		{
			BedNumber = 0;
			PatientID = 0;
		}
		Bed EmptyBed()
		{
			Bed x;
			return x;
		}
		void setPatientID(int x){PatientID = x;}
		const int getBedNumber(){return BedNumber;}
		void setBedNumber(int x){BedNumber = x;}
		bool operator == (Bed x)
		{
			if (getWardName() == x.getWardName() && BedNumber == x.BedNumber && PatientID == x.PatientID) return true;
			return false;
		}
		void Status()//Overriden Status function in order to make Bed Class Concrete instead of Abstract
		{
			cout << "Ward Name: " << getWardName();
			cout << "  Bed Number: " << BedNumber;
			if (IsEmpty())
			{
				SetConsoleTextAttribute(color, 2);
				cout << "\tUnoccupied\t";
				SetConsoleTextAttribute(color, 15);
			}
			else
			{
				SetConsoleTextAttribute(color, 4);
				cout << "\tOccupied\t";
				SetConsoleTextAttribute(color, 15);
			}
		}
};
class Patient
{
	private:
		int ID;
		string Name;
		Bed b;//Ward Name and Bed details are stored in Bed class
		string DoctorName;
	public:
		friend class FrontDeskStaff;//Made friend class so that we can access private members in other class without the need of setters and getters
		friend class HospitalSystem;//^
		friend class Admin; 		//^
		Patient()
		{
			ID = 0;
			Name = "";
			DoctorName = "";
		}
		const char getWardName(){return b.getWardName();}
		const int getBedNumber(){return b.getBedNumber();}
		void setWardName(char s){b.WardName = s;}
		void setBedNumber(int x){b.BedNumber = x;}
		bool IsEmpty()//Function to check if all the attributes of a specific Patient Object is Empty
		{
			if(ID == 0 && Name == "" && b == b.EmptyBed() && DoctorName == "") return true;
			return false;
		}
		friend ostream& operator << (ostream& display , Patient &x);//An operator overloading done to display all attributes of a specific Patient Object
};
ostream& operator << (ostream& display , Patient &x)//Definition of global operator overloading of << 
	{
		display << "Patient Name: " << x.Name << endl;
		display << "Patient ID: " << x.ID << endl;
		display << "Ward Name: " << x.getWardName() << endl;
		display << "Bed Number: " << x.getBedNumber() << endl;
		display << "Doctor Assigned: " << x.DoctorName << endl << endl;
		return display;
	}
class Employee//Class made for all staff which include Doctors, FrontDeskStaff, and Admin, but is primarily used for other 
//staff members as aforementioned occupations have defined classes
{
	protected:
		string ID;
		string Name;
	public:
		friend class Admin;//Made friend class so that we can access private members in other class without the need of setters and getters
		bool IsEmpty()//Function to check if the attributess of a specific Employee Object is Empty
		{
			if(ID == "" && Name == "") return true;
			return false;
		}
};
class Doctor : public Employee
{
	private:
		string Username;
		string Password;
	public:
		friend class HospitalSystem;
		friend class FrontDeskStaff;
		bool IsEmpty() //Overriding the IsEmpty function to better suit the Doctor Class
		{
			if(ID == "" && Name == "" && Username == "" && Password == "") return true;
			return false;
		}
};
class HospitalSystem//Class made to store all people associated in a Hospital
{
	private:
		Patient *p;//All patients
		Doctor *d;//All doctors
		Employee *s;//All employees (for staff members other than doctors) (upcasting will be used if we want to store objects of FrontDeskStaff or Admin)
		Bed *b;//AlL beds where each patient will occupy a single bed
	public:
		HospitalSystem()
		{
			int i;
			p = new Patient[MaxPatientNumber];//Assume hospital can hold 200 Patients at once
			d = new Doctor[MaxDoctorNumber];//Assume hospital can have 40 Doctors at once
			s = new Employee[MaxStaffNumber];//Assume hospital can have 100 Staff Members at once
			b = new Bed[MaxPatientNumber];//Assume that each Ward has 10 Beds so there will be 20 Wards and 200 beds total|Can be altered at will
			//It is advised to keep the number of beds in a ward as a multiple of 20 to stay consistent with the code
			
			//All constants are defined in line 3-5
			for (i = 0 ; i < MaxPatientNumber ; i++)
			{
				b[i].setWardName((char)('A' + (i/10)));//To define that there are 20 Wards (from A-T) and each ward has 10 beds 
				b[i].setBedNumber(i%10 + 1);//Can be better visualized in BedsAvaible Function when called
			}
		}
		~HospitalSystem()
		{
			p = NULL;
			d = NULL;
			s = NULL;
			b = NULL;
			delete p;
			delete d;
			delete s;
			delete b;
		}
		friend class FrontDeskStaff;//Made friend class so that we can access private members in other class without the need of setters and getters
		friend class Admin;			//^
		void BedAvailability()
		{
			int i;
			for (i = 0 ; i < MaxPatientNumber ; i++)
			{
				b[i].Status();
				if(i%2 == 1) cout << endl;
				if(i%10 == 9) cout << endl;
			}
		}
		void DisplayInfo()//A function used to display all the attributes of a specific Patient using Linear Search of the Patient's ID
		{
			int _ID;
			int i;
			cout << "Enter ID to display: "; cin >> _ID;
			for(i = 0 ; i < MaxPatientNumber ; i++)
			{
				if (p[i].ID == _ID)
				{
					cout << p[i];
					break;
				}
			}
			if (i == MaxPatientNumber) cout << "Patient with ID(" << _ID << ") was not found !" << endl;
		}
};
class FrontDeskStaff : public Employee //A class that manages most of the Patients Data
{
	private:
		Patient *p;
		Doctor *d;
		Bed *b;
		static int _ID;
	public:
		FrontDeskStaff(){}
		~FrontDeskStaff()
		{
			p = NULL;
			d = NULL;
			delete p;
			delete d;
		}
		CalibratePatient(HospitalSystem x)//All calibrate functions used to sync classes to the main storage in the HospitalSystem Class
		{
			this->p = x.p;
		}
		CalibrateDoctor(HospitalSystem x)
		{
			this->d = x.d;
		}
		CalibrateBed(HospitalSystem x)
		{
			this->b = x.b;
		}
		void AddPatient()
		{
			int i,j,n;
			int flag;
			Patient x;
			char s;
			for(i = 0 ; i < MaxPatientNumber ; i++)
			{
				flag = 0;
				if(p[i].IsEmpty() == true) 
				{
					cout << "Enter Patient's Name: ";
					getline(cin.ignore() , x.Name);//getline() is a function that is used to take input of white spaces as well (works like gets())
					do
					{
						cout << "Enter Patient's Ward(From A to T, Capital): "; cin >> s;
					}
					while((int)s < 65 || (int)s >= 85);
					for (j = 0 ; j < MaxPatientNumber ; j++)
					{
						if (b[j].getWardName() == s)
						{
							if(b[j].IsEmpty() == true)
							{
								flag = 1;
								break;
							}
						}
					}
					if (flag == 0)
					{
						cout << "No more Space in Ward " << s << endl;
						break; 
					}
					do
					{
						flag = 0;
						cout << "Enter Patient's Bed Number(1 to 10): "; cin >> n;
						for (j = 0 ; j < MaxPatientNumber ; j++)
						{
							if(b[j].getWardName() == s && b[j].getBedNumber() == n)
							{
								if (b[j].IsEmpty() == true)
								{
									flag = 1;
									break;
								}
							}
						}
					}
					while(n < 1 || n > 10);
					if (flag == 0)
					{
						cout << "Bed is already occupied!" << endl;
						break;
					}
					x.setWardName(s);
					x.setBedNumber(n);
					p[i] = x;
					cout << "Patient Entered Successfully!" << endl << endl;
					break;
				}
			}
			if(i == MaxPatientNumber) cout << "No more Bed Available!" << endl << endl;
		}
		void AddDoctor()
		{
			int i;
			Doctor x;
			for(i = 0 ; i < MaxDoctorNumber ; i++)
			{
				if(d[i].IsEmpty() == true)
				{
					cout << "Enter Doctor's Name: "; getline(cin.ignore() , x.Name);
					cout << "Enter Doctor's ID: "; cin >> x.ID;
					d[i] = x;
					cout << "Doctor Entered Successfully!" << endl << endl;
					break;
				}
			}
			if (i == MaxDoctorNumber) cout << "No more Doctors can be entered!" << endl << endl;
		}
		void AssignPatientID()
		{
			int i,j;
			int flag = 0;
			for (i = 0 ; i < MaxPatientNumber ; i++)
			{
				if (p[i].ID == 0 && p[i].Name != "")
				{
					p[i].ID = _ID;
					cout << "Assigned ID(" << _ID << ") to Patient: " << p[i].Name << endl;
					flag = 1;
					for(j = 0 ; j < MaxPatientNumber ; j++)//Assigning PatientID to Beds
					{
						if(p[i].getWardName() == b[j].getWardName() && p[i].getBedNumber() == b[j].getBedNumber())
						{
							b[j].PatientID = p[i].ID;
						}
					}
					_ID++;
				}
			}
			if (flag == 0) cout << "No new Patients were entered!" << endl;
		}
		void AssignUsernamePassword()
		{
			int i;
			string u,p,__ID;
			cout << "Enter relevant Doctor ID to assign Username and Password: "; cin >> __ID;
			for (i = 0 ; i < MaxDoctorNumber ; i++)
			{
				if (d[i].ID == __ID)
				{
					cout << "Enter Doctor's Username: "; getline(cin.ignore() , u);
					cout << "Enter Doctor's Password: "; getline(cin.ignore() , p);
					d[i].Username = u;
					d[i].Password = p;
					cout << "Username and Password have successfully been assigned!" << endl;
					break;
				}
			}
			if (i == MaxDoctorNumber) cout << "No doctor of ID(" << __ID << ") was found!" << endl;
		}
		void AssignDoctor()
		{
			int i,j,a;
			string x;
			int __ID;
			cout << "Enter Patient ID to assign doctor: " ; cin >> __ID;
			for (i = 0 ; i < MaxPatientNumber ; i++)
			{
				if (p[i].ID == __ID)
				{
					cout << "Patient Details" << endl;
					cout << p[i];
					a = 0;
					cout << "Assign Doctor ID: ";
					cin >> x;
					for (j = 0 ; j < MaxDoctorNumber ; j++)
					{
						if (d[j].ID == x)
						{
							a = 1;
							p[i].DoctorName = d[j].Name;
							cout << "Doctor Assigned Successfully!" << endl;
							break;
						}
					}
					if (a == 0) cout << "No doctor with ID(" << x << "). Please try again!" << endl;
					break;
				}
			}
			if(i == MaxPatientNumber) cout << "No Patient with ID(" << __ID << ")" << endl << endl;
		}
};
class Admin : public Employee
{
	private:
		Patient *p;
		Bed *b;
		Employee *s;
	public:
		Admin(){}
		~Admin()
		{
			p = NULL;
			s = NULL;
			delete p;
			delete s;
		}
		CalibrateStaff(HospitalSystem x)
		{
			this->s = x.s;
		}
		CalibratePatient(HospitalSystem x)
		{
			this->p = x.p;
		}
		CalibrateBed(HospitalSystem x)
		{
			this->b = x.b;
		}
		void AddStaff()
		{
			int i;
			Employee x;
			cout << "Enter Staff Member's Name: "; getline(cin.ignore() , x.Name);
			cout << "Enter Staff Member's ID: "; cin >> x.ID;
			for(i = 0 ; i < MaxStaffNumber ; i++)
			{
				if(s[i].IsEmpty() == true)
				{
					s[i] = x;
					cout << "Staff Member Entered Successfully!" << endl << endl;
					break;
				}
			}
			if(i == MaxStaffNumber) cout << "No more Space Available!" << endl << endl;
		}
		void RemovePatient()
		{
			int _ID;
			int i;
			cout << "Enter Patient ID to remove: " ; cin >> _ID;
			for(i = 0 ; i < MaxPatientNumber ; i++)
			{
				if (p[i].ID == _ID)
				{
					p[i].ID = 0;
					p[i].setWardName('\0');
					p[i].Name = "";
					p[i].setBedNumber(0);
					p[i].DoctorName = "";
					cout << "Patient removed Successfully!" << endl << endl;
					break;
				}
			}
			if (i == MaxPatientNumber) cout << "Patient with ID(" << _ID << ") was not found!" << endl << endl; 
		}
		void AddToBedsAvailableList()
		{
			int i,j;
			int flag,notfound = 0;
			for(i = 0 ; i < MaxPatientNumber ; i++)
			{
				flag = 0;
				for (j = 0 ; j < MaxPatientNumber ; j++)
				{
					if(b[i].PatientID == p[j].ID)
					{
						flag = 1;
						break;
					}
				}
				if(flag == 0) 
				{
					b[i].setPatientID(0);
					notfound = 1;
					cout << "Bed of Number(" << b[i].getBedNumber() << ") in Ward(" << b[i].getWardName() << ") is now Unocccupied!" << endl;
				}
			}
			if(notfound == 0) cout << "No Patients have checked out yet!" << endl;
		}
};
int FrontDeskStaff::_ID = 1;
int main()
{
	SetConsoleTextAttribute(color, 15);
	int x,y;
	HospitalSystem h;//Main class used to store details
	FrontDeskStaff fds;//Class that manages most of the entering of details as mentioned in the functional requirements
	Admin a;//Class that manages most of the managerial/staff details as mentioned in the functional requirements
	fds.CalibratePatient(h);//All calibrate functions used to sync classes to the main storage in the HospitalSystem Class
	fds.CalibrateDoctor(h);	//^
	fds.CalibrateBed(h);	//^
	a.CalibrateStaff(h);	//^
	a.CalibratePatient(h);	//^
	a.CalibrateBed(h);		//^
	do//Menu
	{
		cout << "\t____FAST NUCES Hospital____" << endl << endl;
		cout << "1.FrontDeskStaff" << endl;
		cout << "2.Admin" << endl;
		cout << "3.Exit" << endl;
		cin >> x;
		system("CLS");
		switch(x)
		{
			case 1:
				do
				{
					cout << "\t____FAST NUCES Hospital____" << endl << endl;
					cout << "1.Add Patient" << endl;
					cout << "2.Add Doctor" << endl;
					cout << "3.Assign ID to all Patients" << endl;
					cout << "4.Assign Username & Password to Doctor" << endl;
					cout << "5.Assign Doctor to Patient" << endl;
					cout << "6.Display Bed Availablitiy" << endl;
					cout << "7.Display Patient Information" << endl;
					cout << "8.Exit" << endl;
					cin >> y;
					switch(y)
					{
						case 1:
							fds.AddPatient();
							getch();
							break;
						case 2:
							fds.AddDoctor();
							getch();
							break;
						case 3:
							fds.AssignPatientID();
							getch();
							break;
						case 4:
							fds.AssignUsernamePassword();
							getch();
							break;
						case 5:
							fds.AssignDoctor();
							getch();
							break;
						case 6:
							h.BedAvailability();
							getch();
							break;
						case 7:
							h.DisplayInfo();
							getch();
							break;
					}
					system("CLS");
				}
				while(y != 8);
				break;
			case 2:
				do
				{
					cout << "\t____FAST NUCES Hospital____" << endl << endl;
					cout << "1.Add Staff" << endl;
					cout << "2.Remove Patient" << endl;
					cout << "3.Add to Beds Available List" << endl;
					cout << "4.Exit" << endl;
					cin >> y;
					switch(y)
					{
						case 1:
							a.AddStaff();
							getch();
							break;
						case 2:
							a.RemovePatient();
							getch();
							break;
						case 3:
							a.AddToBedsAvailableList();
							getch();
							break;
					}
					system("CLS");
				}
				while(y != 4);
		}
	}
	while(x != 3);
	return 0;
}

