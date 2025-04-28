#include <iostream>
using namespace std;
class base
{
	private:
		int privateInt;
	protected:
		int protectedInt;
	public:
		int publicInt;
		//Getters
		const int getPriInt(){return privateInt;}
		const int getProInt(){return protectedInt;}
		const int getPubInt(){return publicInt;}
		//Setters
		void setPriInt(const int i){privateInt = i;}
		void setProInt(const int i){protectedInt = i;}
		void setPubInt(const int i){publicInt = i;}
};
class publicChild : public base {};
class privateChild : private base {};
class protectedChild : protected base {};

int main()
{
	base b;
	publicChild pu;
	privateChild pri;
	protectedChild pro;
	
	b.publicInt = 10;
	pu.publicInt = 20;
	//pu.privateInt = 100; //Invalid since it is protected
	
	cout << b.publicInt << endl;
	cout << pu.publicInt << endl;
//	cout << b.privateInt << endl;  //Inaccessible since private
	//cout << pri.privateInt;  //Inaccessible since private
	//cout << b.protectedInt << endl; //Inaccessible since protected
	//cout << pro.protectedInt; //Inaccessible since protected
	
	cout << pu.getPubInt() << endl;
	//cout << pri.getPriInt() << endl;  //Inaccessible since private
	//cout << pro.getProInt() << endl;  //Inaccessible since protected
}
