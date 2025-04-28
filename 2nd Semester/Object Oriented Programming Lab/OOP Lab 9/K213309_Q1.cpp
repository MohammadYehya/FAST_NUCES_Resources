#include <iostream>
using namespace std;
class Animal
{
	private:
		string Name;
	public:
		foundIn() {cout << "An animal can be found in many places" << endl;}
		void setName(string _name) {Name = _name;}
		string getName() {return Name;}
		Animal(){}
		Animal(string Name){this->Name = Name;}
};
class Mammal : virtual public Animal
{
	public:
		foundIn() {cout << "A mammal can be found in water or on land" << endl;}
		Mammal(){}
		Mammal(string Name) : Animal (Name){}
};
class MarineAnimal : virtual public Animal
{
	public:
		foundIn() {cout << "A marine animal can only be found in bodies of water" << endl;}
		MarineAnimal(){}
		MarineAnimal(string Name) : Animal(Name){}
};
class Whales : public MarineAnimal , public Mammal
{
	private:
		string WhaleType;
	public:
		foundIn() {cout << "A " << WhaleType << getName() << " can only be found in the ocean." << endl;}
		Whales(string Name , string Type) : Animal(Name) , Mammal(Name) , MarineAnimal(Name) {WhaleType = Type;}
};
int main()
{
	Whales whaleBaleen("Whale" , "Baleen");
	whaleBaleen.Animal::foundIn();
	whaleBaleen.Mammal::foundIn();
	whaleBaleen.MarineAnimal::foundIn();
	whaleBaleen.foundIn();
}

