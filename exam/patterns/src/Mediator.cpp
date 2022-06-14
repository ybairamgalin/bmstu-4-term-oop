#include <iostream>

class Colleague;

class Mediator
{
public:
    virtual void sendMessage(const std::string &message, Colleague *sender) = 0;
};

class Colleague
{
public:
    explicit Colleague(Mediator *mediator) : mediator(mediator) { }

    virtual void receiveMessage(const std::string &message)
    {
        std::cout << message << std::endl;
    }

    virtual void sendMessage(const std::string &message)
    {
        mediator->sendMessage(message, this);
    }
protected:
    Mediator *mediator;
};

class Bob : public Colleague
{
public:
    Bob(Mediator *mediator) : Colleague(mediator) { }

    void receiveMessage(const std::string &message) override
    {
        std::cout << "Bob received message";
        Colleague::receiveMessage(message);
    }
    void sendMessage(const std::string &message) override
    {
        std::cout << "Bob sent message: " << message << std::endl;
        Colleague::sendMessage(message);
    }
};

class John : public Colleague
{
public:
    John(Mediator *mediator) : Colleague(mediator) { }

    void receiveMessage(const std::string &message) override
    {
        std::cout << "John received message: ";
        Colleague::receiveMessage(message);
    }
    void sendMessage(const std::string &message) override
    {
        std::cout << "John sent message:" << message << std::endl;
        Colleague::sendMessage(message);
    }
};

class ConcreteMediator : public Mediator
{
public:
    void setColleagues(Colleague *colleague1, Colleague *colleague2)
    {
        c1 = colleague1;
        c2 = colleague2;
    }

    void sendMessage(const std::string &message, Colleague *sender) override
    {
        if (c1 == sender)
            c2->receiveMessage(message);
        else if (c2 == sender)
            c1->receiveMessage(message);
        else
            throw;
    }
private:
    Colleague* c1;
    Colleague* c2;
};

int main()
{
    ConcreteMediator *mediator = new ConcreteMediator();

    Bob *bob = new Bob(mediator);
    John *john = new John(mediator);

    mediator->setColleagues(bob, john);

    bob->sendMessage("HEY THERE!, I'M BOB");
    john->sendMessage("LA LA LA");

    return 0;
}
