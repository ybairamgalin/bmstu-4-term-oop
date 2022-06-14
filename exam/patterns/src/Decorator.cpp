#include <iostream>
#include <memory>

class Car
{
public:
    virtual void driveForward() = 0;
    virtual ~Car() = default;
};

class MercedesCar : public Car
{
public:
    void driveForward() override { std::cout << "MERCEDES DRIVING\n"; }
};

class BmwCar : public Car
{
public:
    void driveForward() override { std::cout << "BMW DRIVING\n"; }
};

class Decorator : public Car
{
private:
    std::shared_ptr<Car> car;
public:
    Decorator(std::shared_ptr<Car> newCar) : car(newCar) { }
    Decorator &operator=(Decorator &) = default;
    void driveForward() override { car->driveForward(); }
};

class LightOnDecorator : public Decorator
{
public:
    LightOnDecorator(std::shared_ptr<Car> newCar) : Decorator(newCar) { }
    void driveForward() override
    {
        std::cout << "LIGHT IS ON\n";
        Decorator::driveForward();
    }
};

int main()
{
    std::shared_ptr<Car> car1 = std::make_shared<MercedesCar>();
    std::shared_ptr<Car> car2 = std::make_shared<BmwCar>();

    car1->driveForward();
    car2->driveForward();

    car1 = std::make_shared<LightOnDecorator>(car1);
    car1->driveForward();

    car2 = std::make_shared<LightOnDecorator>(car2);
    car2->driveForward();
}
