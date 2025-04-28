#include<iostream>
#include <fstream>
#include <conio.h>
#pragma GCC diagnostic ignored 	"-Wwrite-strings"
#define size 100
using namespace std;

class Record
{
    char* name;
    char* st_id;
    int age;
    int semester;
    char* address;
    public:
    	//Constructors
    	Record(){}
	    Record(char* a, char* b, int c, int d, char* e)
	    {
			name = a;
			st_id = b;
	        age = c;
	        semester = d;
	        address = e;
	    }
	    
	    void display()
	    {
	        cout << "Name: " << name << endl
			<< "ID: " << st_id << endl
			<< "Age: " << age << endl 
			<< "Semester: " << semester << endl 
			<< "Address: " << address << endl;
	    }
	    //Mutators
	    void setName(char Name[]){this->name = Name;}
	    void setID(char* ID){st_id = ID;}
	    void setAge(const int age){this->age = age;}
	    void setSemester(const int Semester){this->semester = Semester;}
	    void setAddress(char* address){this->address = address;}
	    
	    //All functions that are related to Filing are kept Static so that they are not binded by each object but instead by the class
	    static Record Empty()//Function to return Empty Record. Could also put in default constructor
	    {
	    	Record x;
	    	x.name = "Empty";
	    	x.st_id = "Empty";
	    	x.age = 0;
	    	x.semester = 0;
	    	x.address = "Empty";
	    	return x;
		}
	    static void StoreData(Record x[])//Function to store an object of 100 records in FILE "MyRecord.dat"
	    {
	    	ofstream f("MyRecord.dat" , ios::out | ios::binary);
	    	if(!f){cout << "Error Code#3309! \nExiting Program...";system("Pause");exit(3309);}
	    	for (int i = 0 ; i < size ; i++) {f.write((char*)&x[i] , sizeof(x[i]));}
	    	f.close();
		}
		static void GetData(Record x[])//Function to get data from FILE "MyRecord.dat" and store in Record Array
		{
			ifstream f("MyRecord.dat" , ios::in | ios::binary);
			if(!f){cout << "Error Code#3309! \nExiting Program...";system("Pause");exit(3309);}
			int i = 0;
			while(!f.eof() && i < size)
			{
				f.read((char*)&x[i] , sizeof(x[i]));
				i++;
			}
			f.close();
			while (i - 1 < size)		//Exception if File does not have enough values to fill in array. So initialize with Empty Record
			{
				x[i - 1] = Record::Empty();
				i++;
			}
		}
		static void SortFile()//Function to Sort FILE in accending order of age
		{
			fstream f("MyRecord.dat" , ios::in | ios::binary);
			if(!f){cout << "Error Code#3309! \nExiting Program...";system("Pause");exit(3309);}
			
			fstream fn("Temp.dat" , ios::out | ios::binary);
			if(!fn){cout << "Error Code#3309! \nExiting Program...";system("Pause");exit(3309);}
			int min = 9999, tmin = 0;
			Record x[size];
			Record Tmin;
			for(int i = 0 ; i < size ; i++)f.read((char*)&x[i] , sizeof(x[i]));
			for(int i = 0 ; i < size ; i++)
			{	
				for(int j = i + 1 ; j < size ; j++)
				if(x[i].age > x[j].age)
				{
					Tmin = x[i];
					x[i] = x[j];
					x[j] = Tmin;
				}
			}
			for(int i = 0 ; i < size ; i++) fn.write((char*)&x[i] , sizeof(x[i]));
			f.close();
			fn.close();
			remove("MyRecord.dat");				//Deleting the Original FILE
			rename("Temp.dat" , "MyRecord.dat");	//Renaming the Temporary FILE to Original FILE
		}
		static void SemesterCount()//Function to count Number of Students in each semester
		{
			fstream f("MyRecord.dat" , ios::in | ios::binary);
			if(!f){cout << "Error Code#3309! \nExiting Program...";system("Pause");exit(3309);}
			Record x[size];
			int Sem[8] = {0};
			for(int i = 0 ; i < size ; i++) f.read((char*)&x[i] , sizeof(x[i]));
			for(int i = 0 ; i < size ; i++) {Sem[x[i].semester - 1]++;}
			f.close();
			for(int i = 0 ; i < 8 ; i++)cout << "Semester " << i+1 << ": " << Sem[i] << endl;
		}
		static void DeleteRecord()//Function to delete a specific Record in file
		{
			fstream f("MyRecord.dat" , ios::in | ios::binary);
			if(!f){cout << "Error Code#3309! \nExiting Program...";system("Pause");exit(3309);}
			
			fstream fn("Temp.dat" , ios::out | ios::binary);
			if(!fn){cout << "Error Code#3309! \nExiting Program...";system("Pause");exit(3309);}
			Record x;
			while(1)
			{
				f.read((char*)&x , sizeof(x));
				if (f.eof()) break;
				if(x.name[0] == 'a')
				{
					cout << "DELETED:" << endl;
					x.display();
					cout << endl;
				}
				else
				{
					fn.write((char*)&x , sizeof(x));
				}
			}
			f.close();
			fn.close();
			remove("MyRecord.dat");
			rename("Temp.dat" , "MyRecord.dat");
		}
		static void UpdateStudent()//Function to Update a specific Record in FILE
		{
			char* n;
			char* i;
			int a;
			int s;
			char* ad;
			char choice;
			int flag = 0;
			string id;
			cout << "Enter ID to update: ";getline(cin.ignore() , id);
			fstream f("MyRecord.dat" , ios::in | ios::binary);
			if(!f){cout << "Error Code#3309! \nExiting Program...";system("Pause");exit(3309);}
			
			fstream fn("Temp.dat" , ios::out | ios::binary);
			if(!fn){cout << "Error Code#3309! \nExiting Program...";system("Pause");exit(3309);}
			Record x;
			f.seekg(0 , ios_base::beg);
			cout << endl << "Now Updating Student#" << id << endl;
			while(1)
			{
				f.read((char*)&x , sizeof(x));
				if(f.eof()) break;
				if(x.st_id == id)
				{
					flag = 1;
					cout << "Change Name?(Y/N)";
					cin >> choice;
					if(choice == 'Y' || choice =='y')
					{
						n = new char[100];
						cout << "Name: ";
						cin >> n;
						x.setName(n);
					}
					cout << "Change ID?(Y/N)";
					cin >> choice;
					if(choice == 'Y' || choice =='y')
					{
						i = new char[100];
						cout << "ID: ";
						cin.ignore() >> i;
						x.setID(i);
					}
					cout << "Change Age?(Y/N)";
					cin >> choice;
					if(choice == 'Y' || choice =='y')
					{
						cout << "Age: ";
						cin >> a;
						x.setAge(a);
					}
					cout << "Change Semester?(Y/N)";
					cin >> choice;
					if(choice == 'Y' || choice =='y')
					{
						cout << "Semester: ";
						cin >> s;
						x.setSemester(s);
					}
					cout << "Change Address?(Y/N)";
					cin >> choice;
					if(choice == 'Y' || choice =='y')
					{
						ad = new char[100];
						cout << "Address: ";
						cin.ignore() >> ad;
						x.setAddress(ad);
					}
					x.display();
				}
				fn.write((char*)&x , sizeof(x));
			}
			f.close();
			fn.close();
			remove("MyRecord.dat");
			rename("Temp.dat" , "MyRecord.dat");
			if(flag == 0) cout << "Record Not Found!" << endl;
		}
};


int main()
{
	/*
		Made an Array of Record Objects just incase FILE gets lost or Corrupted.
		Group:
			Mohammad Yehya Hayati , K21-3309
			Asad Noor Khan , K21-4678
			Deepak Chawla , K21-4931
		Questions:
			Q1: Store the data in file in ascending order of age
			Q2: Display the count of student based on semester by reading from the file. For instace Semester 1: 40, Semester 2: 30 etc
			Q3: Delete the records whose name start with 'a'
			Q4: Define the function that could update the record of any student
	*/
	Record r[size] = {
	Record("Yehya" , "3309" , 18 , 2 , "North Nazimabad") ,	Record("Rafed" , "3385" , 18 , 2 , "USA") , Record("Ahmed" , "3212" , 20 , 2 , "France"),//1
	Record("Hasan" , "3297" , 18 , 2 , "Malir") ,	Record("Taha" , "4680" , 17 , 2 , "North Karachi") , Record("Asad" , "4678" , 20 , 2 , "Gilgit"),//2
	Record("Ali" , "3567" , 20 , 3 , "Jauhar") ,	Record("Farhan" , "3215" , 22 , 4 , "Kashmir") , Record("aaliyan" , "4821" , 25 , 6 , "India"),//3
	Record("Raplh" , "5211" , 18 , 1 , "Gulshan") ,	Record("Usman" , "1234" , 21 , 3 , "Balochistan") , Record("Haris" , "4561" , 22 , 5 , "Turkey"),//4
	Record("Sarim" , "7421" , 21 , 4 , "Defense") ,	Record("Janita " , "1529" , 23 , 4 , "Jamaica") , Record("Tyrell " , "1124" , 24 , 3 , "Sweden"),//5
	Record("Henry" , "1569" , 23 , 4 , "Wales") ,	Record("Brian" , "7999" , 20 , 2 , "USA") , Record("Louis " , "6160" , 20 , 2 , "Mexico"),//6
	Record("Bobby " , "2254" , 22 , 3 , "India") ,	Record("Steven " , "6437" , 19 , 1 , "USA") , Record("Randy " , "8342" , 18 , 1 , "UK"),//7
	Record("David " , "3622" , 19 , 2 , "Australia") ,	Record("Scott " , "3416" , 18 , 3 , "Iceland") , Record("Kevin " , "5698" , 22 , 4 , "UK"),//8
	Record("Jeremy" , "6085" , 24 , 6 , "UK") ,	Record("William" , "7544" , 17 , 1 , "UK") , Record("Shawn" , "9949" , 18 , 1 , "USA"),//9
	Record("Stephen " , "6433" , 22 , 5 , "USA") ,	Record("George " , "4572" , 22 , 7 , "USA") , Record("Dennis " , "2389" , 22 , 4 , "Russia"),//10
	Record("Ronald " , "8963" , 22 , 4 , "Brazil") , Record("Jeffrey " , "7308" , 23 , 5 , "USA") , Record("Charles " , "4361" , 21 , 3 , "UK"),//11
	Record("Walter " , "2672" , 25 , 5 , "USA") ,	Record("Philip " , "4522" , 22 , 4 , "Germany") , Record("Fred " , "8273" , 20 , 2 , "Brazil"),//12
	Record("Russell " , "1874" , 28 , 8 , "China") ,	Record("Daniel " , "6833" , 21 , 7 , "UAE") , Record("Lawrence " , "1343" , 25 , 4 , "Turkey"),//13
	Record("Steve " , "7811" , 26 , 5 , "USA") ,	Record("Donald " , "6486" , 21 , 4 , "Australia") , Record("Harold" , "2024" , 27 , 6 , "UK"),//14
	Record("arthur " , "5983" , 22 , 7 , "UK") ,	Record("andrew " , "6137" , 20 , 7 , "France") , Record("Carl " , "7264" , 19 , 1 , "Estonia"),//15
	Record("aaron " , "9744" , 19 , 4 , "Finland") ,	Record("Billy" , "2793" , 22 , 2 , "West Indies") , Record("Joseph " , "9330" , 20 , 4 , "Chile"),//16
	Record("Gerald " , "1059" , 34 , 8 , "Peru") ,	Record("Joe " , "3352" , 22 , 6 , "Mama") , Record("Clarence" , "9120" , 20 , 3 , "Portugal"),//17
	Record("Jerry " , "7232" , 20 , 2 , "Argentina") ,	Record("Craig " , "1245" , 31 , 8 , "Egypt") , Record("Walter" , "7055" , 20 , 2 , "Canada"),//18
	Record("Justin " , "1153" , 32 , 8 , "Beiber") ,	Record("alan " , "4872" , 20 , 3 , "Pakistan") , Record("Lopez" , "6019" , 21 , 4 , "India"),//19
	Record("Frank " , "7845" , 20 , 4 , "Indonesia") ,	Record("Martin " , "4909" , 21 , 5 , "Russia") , Record("Patrick " , "5136" , 19 , 1 , "Spongebob"),//20
	Record("George " , "1482" , 29 , 5 , "China") ,	Record("Jesse " , "2517" , 24 , 6 , "Ireland") , Record("Raymond " , "5378" , 21 , 3 , "Malaysia"),//21
	Record("Linda " , "4259" , 20 , 2 , "South Africa") ,	Record("Keith " , "6194" , 21 , 3 , "Somaliya") , Record("Wanda " , "4261" , 27 , 7 , "Kenya"),//22
	Record("Melinda " , "6972" , 20 , 2 , "Italy") , Record("Jeannie " , "1870" , 24 , 4 , "In a bottle") , Record("Ian" , "2678" , 24 , 4 , "Crotia"),//23
	Record("Emanuel " , "1788" , 21 , 2 , "Spain") , Record("Hannah " , "6351" , 21 , 2 , "USA") , Record("Edith " , "4983" , 21 , 1 , "Macedonia"),//24
	Record("Lola " , "2258" , 23 , 3 , "Uganda") , Record("Rosa " , "9513" , 19 , 1 , "USA") , Record("Bessie " , "6521" , 20 , 1 , "Nigeria"),//25
	Record("Jody " , "8056" , 21 , 2 , "Maldives") , Record("Sabrina" , "6958" , 21 , 3 , "Hawaii") , Record("annette " , "7194" , 21 , 3 , "Mexico"),//26
	Record("Gladys " , "6418" , 21 , 2 , "Not You") , Record("amos " , "8094" , 21 , 4 , "Spain") , Record("Rochelle " , "3883" , 21 , 4 , "France"),//27
	Record("Vicky " , "7490" , 23 , 3 , "India") , Record("Castro" , "1873" , 27 , 6 , "Mexico") , Record("Jacqueline " , "9678" , 24 , 4 , "China"),//28
	Record("Marguerite " , "9543" , 20 , 7 , "Japan") , Record("Pat " , "4045" , 21 , 8 , "On the Back") , Record("Tracy " , "6261" , 22 , 3 , "Antarctica"),//29
	Record("Sylvester" , "8933" , 21 , 4 , "North Pole") , Record("Darrin " , "5814" , 21 , 2 , "South Pole") , Record("Nettie " , "4995" , 21 , 1 , "Bangladesh"),//30
	Record("Julio " , "2247" , 20 , 2 , "Bangladesh") , Record("Kiara " , "9435" , 23 , 5 , "Afghanistan") , Record("Babara " , "3392" , 33 , 6 , "China"),//31
	Record("Jaclyn " , "5069" , 21 , 4 , "Nrth Korea") , Record("Kyle " , "5546" , 21 , 4 , "South Korea") , Record("Loreen" , "7767" , 27 , 8 , "Jumanji"),//32
	Record("Mariella" , "4250" , 24 , 4 , "Disco") , Record("Dorthey " , "2621" , 26 , 6 , "UK") , Record("Oliva " , "4794" , 25 , 5 , "Wales"),//33
	Record("avery " , "3933" , 21 , 5 , "USA")};//34
	
	
	int choice;
	while(1)
	{
		cout << "File Handling Task (Assignment #3)" << endl << endl;
		cout << "1.Store Data" << endl
		<< "2.Display Semester Count" << endl
		<< "3.Delete Records starting with \'a\'" << endl
		<< "4.Update Specific Record" << endl 
		<< "5.Exit" << endl
		<< "Enter Choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				Record::StoreData(r);
				Record::SortFile();
				cout << "Records have successfully been stored!";
				getch();
				break;
			case 2:
				Record::SemesterCount();
				getch();
				break;
			case 3:
				Record::DeleteRecord();
				getch();
				break;
			case 4:
				Record::UpdateStudent();
				getch();
				break;
			case 5:
				exit(0);
		}
		system("CLS");
	}
}

