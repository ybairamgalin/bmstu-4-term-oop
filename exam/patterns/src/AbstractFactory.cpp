#include <iostream>

class Engine
{
public:
    virtual void info() = 0;
    virtual ~Engine() = default;
};
class BmwEngine : public Engine
{
public:
    void info() override { std::cout << "BMW ENGINE\n"; }
};
class MercedesEngine : public Engine
{
public:
    void info() override { std::cout << "MERCEDES ENGINE\n"; }
};

class Wheel
{
public:
    virtual void info() = 0;
    virtual ~Wheel() = default;
};

class BmwWheel : public Wheel
{
public:
    void info() override { std::cout << "BMW WHEEL\n"; }
};

class MercedesWheel : public Wheel
{
public:
    void info() override { std::cout << "MERCEDES WHEEL\n"; }
};

class AbstractCarFactory
{
public:
    virtual Engine* createEngine() = 0;
    virtual Wheel* createWheel() = 0;
    virtual ~AbstractCarFactory() = default;
};

class MercedesCarFactory : public AbstractCarFactory
{
public:
    Engine* createEngine() override { return new MercedesEngine; }
    Wheel* createWheel() override { return new MercedesWheel; }
};

class BmwCarFactory : public AbstractCarFactory
{
public:
    Engine* createEngine() override { return new BmwEngine; }
    Wheel* createWheel() override { return new BmwWheel; }
};

class CarSolution
{
public:
    CarSolution(std::string config)
    {
        if (config == "BMW") creator = new BmwCarFactory;
        else if (config == "MERCEDES") creator = new MercedesCarFactory;
        else throw;
    }
    ~CarSolution() { delete creator; };

    AbstractCarFactory *getCreator() { return creator; }

private:
    AbstractCarFactory *creator;
};

int main()
{
    CarSolution solver = CarSolution("BMW");

    Engine *eng = solver.getCreator()->createEngine();
    Wheel* wheel = solver.getCreator()->createWheel();

    eng->info();
    wheel->info();

    delete eng;
    delete wheel;

    CarSolution newSolver = CarSolution("MERCEDES");

    eng = newSolver.getCreator()->createEngine();
    wheel = newSolver.getCreator()->createWheel();

    eng->info();
    wheel->info();

    delete eng;
    delete wheel;

    return 0;
}