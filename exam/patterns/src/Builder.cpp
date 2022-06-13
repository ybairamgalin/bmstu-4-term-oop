#include <iostream>
#include <memory>

class Car
{
public:
    void setEngine(std::string eng) { engine = eng; }
    void setBody(std::string b) { body = b; }
    void info() { std::cout << engine << std::endl << body << std::endl; }
private:
    std::string engine;
    std::string body;
};

class CarBuilder
{
public:
    virtual void buildEngine() = 0;
    virtual void buildBody() = 0;

    void createNewCar() { car = std::make_shared<Car>(); }
    std::shared_ptr<Car> getCar() { return car; }
protected:
    std::shared_ptr<Car> car;
};

class BmwCarBuilder : public CarBuilder
{
public:
    void buildEngine() override { car->setEngine("BMW engine"); }
    void buildBody() override { car->setBody("BMW body"); }
};

class MercedesCarBuilder : public CarBuilder
{
public:
    void buildEngine() override { car->setEngine("MERCEDES engine"); }
    void buildBody() override { car->setBody("MERCEDES body"); }
};

class Manufacturer
{
public:
    void setBuilder(CarBuilder *newBuilder) { builder = newBuilder; }
    std::shared_ptr<Car> buildCar() {
        if (!builder) throw;

        builder->createNewCar();
        builder->buildEngine();
        builder->buildBody();

        return builder->getCar();
    }
private:
    CarBuilder *builder;
};

int main()
{
    Manufacturer carProducer;
    carProducer.setBuilder(new MercedesCarBuilder);
    auto car = carProducer.buildCar();
    car->info();

    carProducer.setBuilder(new BmwCarBuilder);
    auto newCar = carProducer.buildCar();

    newCar->info();

    return 0;
}
