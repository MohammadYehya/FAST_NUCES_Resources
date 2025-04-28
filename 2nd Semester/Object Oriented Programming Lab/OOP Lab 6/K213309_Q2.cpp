#include <iostream>
using namespace std;
class Vehicle 
{
	public:
		int EngineNumber;
		string DateOfCreation;
};
class Automobile : public Vehicle 
{	
	public:
		float WheelSize;
};
class PulledVehicle : public Vehicle 
{
	public:
		float weight;
};
class Car : public Automobile 
{
	public:
		string Owner;
};
class SuzukiAlto : public Car {};
class SuzukiMehran : public Car {};
int main()
{
	//Made all data members|attributes for the ease of demonstration(NO setters and getters)
	SuzukiAlto SA;
	SuzukiMehran SM;
	
//	SA.weight = 10; //Can not access weight as SuzukiAlto does not inherit PulledVehicle
	SA.WheelSize = 10; //Is accessible since it inherits AutoMobile
	
	SM.EngineNumber = 10;//Works since it inherits vehicle
	cout << SM.EngineNumber;
}

