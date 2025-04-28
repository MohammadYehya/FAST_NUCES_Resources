#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
using namespace std;
class Participant
{
	private:
		int ID;
		int score;
		char* Name;
	public:
		Participant(){}
		Participant(int i , char* n , int s):ID(i) , score(s){Name = n;}
		void Input()
		{
			fstream f("Participant.dat" , ios::out | ios::app | ios::binary );
			if(!f){cout << "Error Code#3309! \nExiting Program...";exit(3309);}
			f.write((char*)this , sizeof(*this));
			f.close();
		}
		void Output(int id)
		{
			ifstream f("Participant.dat" , ios::in | ios::binary);
			if(!f){cout << "Error Code#3309! \nExiting Program...";exit(3309);}
			int x;
			Participant p1;
			while(!f.eof())
			{
				f.read((char*)&p1,sizeof(p1));
				if (p1.ID == id)
				{
					p1.display();
					f.close();
					x++;
					break;
				}
			}
			if(x == 0) cout << "Participant Not Found!" << endl;
		}
		static Participant Max()
		{
			fstream f("Participant.dat" , ios::in | ios::binary);
			Participant p1;
			Participant PMax;
			int max = 0;
			while(!f.eof())
			{
				f.read((char*)&p1,sizeof(p1));
				if (p1.score > max)
				{
					max = p1.score;
					PMax = p1;
				}
			}
			f.close();
			return PMax;
		}
		void display()
		{
			cout << "Name: " << Name << ", ID: " << ID << ", Score: " << score << endl;
		}
};
int main()
{
	Participant p1(1,"Yehya",100);
	Participant p2(2,"Taha",85);
	Participant p3(3,"Rafed",95);
	p1.Input();
	p2.Input();
	p3.Input();
	p1.Output(3);
	cout << endl << "Person With Highest Score is:" << endl;
	Participant::Max().display();
}

