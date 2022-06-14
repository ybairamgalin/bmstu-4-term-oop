#include <iostream>

class Phone
{
public:
    virtual void call() = 0;
    virtual Phone *clone() = 0;
    virtual ~Phone() = default;
};

class ApplePhone : public Phone
{
public:
    void call() override { std::cout << "CALLING\n"; }
    Phone* clone() override { return new ApplePhone(*this); }
};

int main()
{
    Phone *phone = new ApplePhone();
    phone->call();

    Phone *newPhone = phone->clone();
    newPhone->call();

    return 0;
}
