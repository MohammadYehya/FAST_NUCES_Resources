#include <iostream>
using namespace std;

class Product 
{
    public:
        virtual void display() = 0;
        virtual ~Product() {}
};

class ProductA : public Product 
{
    public:
        void display() {
            cout << "Product A\n";
        }
};


class ProductB : public Product 
{
    public:
        void display() {
            cout << "Product B\n";
        }
};

class Creator 
{
    public:
        virtual Product* createProduct() = 0;
        virtual ~Creator() {}
};

class CreatorA : public Creator 
{
    public:
        Product* createProduct() 
        {
            return new ProductA();
        }
};

class CreatorB : public Creator 
{
    public:
        Product* createProduct() 
        {
            return new ProductB();
        }
};

int main() 
{
    Creator* creatorA = new CreatorA();
    Product* productA = creatorA->createProduct();
    productA->display();

    Creator* creatorB = new CreatorB();
    Product* productB = creatorB->createProduct();
    productB->display();

    delete creatorA;
    delete productA;
    delete creatorB;
    delete productB;

    return 0;
}