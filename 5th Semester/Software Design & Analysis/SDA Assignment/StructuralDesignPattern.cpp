#include <iostream>
using namespace std;

class Target 
{
    public:
        virtual void request() = 0;
        virtual ~Target() {}
};

class Adaptee 
{
    public:
        void specificRequest() 
        {
            cout << "Adaptee's specific request\n";
        }
};

class Adapter : public Target 
{
    private:
        Adaptee* adaptee;
    public:
        Adapter(Adaptee* a) : adaptee(a) {}
        void request() 
        {
            adaptee->specificRequest();
        }
};

int main() 
{
    Adaptee* adaptee = new Adaptee();
    Target* adapter = new Adapter(adaptee);
    adapter->request();

    delete adaptee;
    delete adapter;

    return 0;
}