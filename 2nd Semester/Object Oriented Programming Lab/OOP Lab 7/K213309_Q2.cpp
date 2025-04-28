#include <iostream>
using namespace std;
class StorehouseItems
{
	private:
		int quantityOfBoxes;
		int quantityPerBox;
	public:
		StorehouseItems(){}
		StorehouseItems(int x , int y) : quantityOfBoxes(x) , quantityPerBox(y){}
		const int getquantityOfBoxes(){return quantityOfBoxes;}
		const int getquantityPerBox(){return quantityPerBox;}
		void setquantityOfBoxes(const int x){quantityOfBoxes = x;}
		void setquantityPerBox(const int x){quantityPerBox = x;}
};
class SchoolBooks : private StorehouseItems
{
	public:
		SchoolBooks(){}
		SchoolBooks(int x , int y) : StorehouseItems(x , y){}
		int displayTotal(){return getquantityOfBoxes()*getquantityPerBox();}
};
class Pencils : public StorehouseItems
{
	public:
		Pencils(){}
		Pencils(int x , int y) : StorehouseItems(x , y){}
		int displayTotal(){return getquantityOfBoxes()*getquantityPerBox();}
};
class Sharpeners : public StorehouseItems
{
	public:
		Sharpeners(){}
		Sharpeners(int x , int y) : StorehouseItems(x , y){}
		int displayTotal(){return getquantityOfBoxes()*getquantityPerBox();}
};
class Erasers : public StorehouseItems
{
	public:
		Erasers(){}
		Erasers(int x , int y) : StorehouseItems(x , y){}
		int displayTotal(){return getquantityOfBoxes()*getquantityPerBox();}
};
class ColorPencils : public Pencils
{
	public:
		ColorPencils(){}
		ColorPencils(int x , int y) : Pencils(x , y){}
		int displayTotal(){return getquantityOfBoxes()*getquantityPerBox();}
};
int main()
{
	SchoolBooks SchoolBook1(10 , 100);
	Pencils Pencil1(5 , 1000);
	ColorPencils ColorPencil1(5 , 1000);
	Sharpeners Sharpener1(2 , 500);
	Erasers Eraser1(10 , 1000);
	
	cout << SchoolBook1.displayTotal() << " is the total amount of School Books!" << endl;
	cout << Pencil1.displayTotal() << " is the total amount of Pencils!" << endl;
	cout << ColorPencil1.displayTotal() << " is the total amount of Color Pencils!" << endl;
	cout << Sharpener1.displayTotal() << " is the total amount of Sharpeners!" << endl;
	cout << Eraser1.displayTotal() << " is the total amount of Erasers!" << endl;
}

