#include <iostream>

class Product
{
public:
    virtual void doSomething() = 0;
    virtual ~Product() = default;
};

class ConcreteProduct : public Product
{
public:
    void doSomething() override { std::cout << "Something concrete is done\n"; }
};

class Creator
{
public:
    virtual Product* create() = 0;
    virtual ~Creator() = default;
};

class ConcreteCreator : public Creator
{
public:
    Product* create() override { return new ConcreteProduct(); }
};

int main()
{
    ConcreteCreator cr = ConcreteCreator();
    Product *prod = cr.create();

    prod->doSomething();
}
