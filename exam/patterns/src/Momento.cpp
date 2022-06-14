#include <iostream>
#include <vector>

class Memento
{
public:
    Memento(std::string state) { this->state = state; }
    std::string getState() { return state; }
private:
    std::string state;
};

class Lamp
{
public:
    void turnOn() { state = true; }
    void turnOff() { state = false; }

    std::string getState() { return state ? "ON" : "OFF"; }

    Memento* createMemento() { return new Memento(state ? "ON" : "OFF"); }
    void setMemento(Memento *memento) { }
private:
    bool state = false;
};

class CareTaker
{
public:
    void saveState(Lamp &lamp) { history.push_back(lamp.createMemento()); }
    void showHistory()
    {
        for (auto &element: history)
            std::cout << element->getState() << std::endl;
    }
private:
    std::vector<Memento*> history;
};

int main()
{
    CareTaker historySaver;

    Lamp lamp;
    historySaver.saveState(lamp);

    lamp.turnOn();
    historySaver.saveState(lamp);

    lamp.turnOn();
    historySaver.saveState(lamp);

    lamp.turnOff();
    historySaver.saveState(lamp);

    historySaver.showHistory();
}
