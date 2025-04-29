#include <iostream>
using namespace std;
class Animal
{
	private:
		int ID;
	public:
		friend void AnimalSort(Animal x[] , int size);
		//Constructors
		Animal(){}
		Animal(int ID){this->ID = ID;}
		//Setters
		void setID(const int ID){this->ID = ID;}
		//Getters
		const int getID(){return this->ID;}
};
void AnimalSort(Animal x[] , int size)
{
//	cout << sizeof(x)/sizeof(Animal);
	for (int i = 0 ; i < size - 1 ; i++)
	{
		for(int j = 0 ; j < size - i - 1 ; j++)
		{
			if (x[j].ID > x[j+1].ID)
			{
				int temp = x[j+1].ID;
				x[j+1].ID = x[j].ID;
				x[j].ID = temp;
			}
		}
	}
}
int main()
{
	Animal *Cat , *Lizard , *Salmon;
	
	Lizard = new Animal(45146);
	
	Salmon = new Animal(66652);
	
	Cat = new Animal[3];
	Cat->setID(54165);
	Cat[1].setID(56411);
	Cat[2].setID(41756);
	
	//For Sorting Purposes an Array was made to hold all 5 objects
	Animal *List = new Animal[5];
	List[0] = Cat[0];
	List[1] = Cat[1];
	List[2] = Cat[2];
	List[3] = *Lizard;
	List[4] = *Salmon;
	AnimalSort(List , 5);
	for(int i = 0 ; i < 5 ; i++){cout << List[i].getID() << endl;}
	
	delete[] Cat;
	delete Lizard;
	delete Salmon;
	delete[] List;
}
