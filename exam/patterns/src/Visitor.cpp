#include <iostream>
#include <memory>

class IPhone;
class XiaomiPhone;

class Visitor
{
public:
    virtual ~Visitor() = default;
    virtual void visit(IPhone *phone) = 0;
    virtual void visit(XiaomiPhone *phone) = 0;
};

class Phone
{
public:
    virtual ~Phone() = default;
    virtual void call() = 0;
    virtual void ring() = 0;
    virtual void accept(Visitor &visitor) = 0;
};

class IPhone : public Phone
{
public:
    void call() override { std::cout << "Calling with iPhone\n"; }
    void ring() override { std::cout << "BR-BR-BR-BR\n"; }
    void accept(Visitor &visitor) override { visitor.visit(this); }
};

class XiaomiPhone : public Phone
{
public:
    void call() override { std::cout << "Calling with Xiaomi\n"; }
    void ring() override { std::cout << "DRA-DRA I'M SMARTER DRA-DRA\n"; }
    void accept(Visitor &visitor) override { visitor.visit(this); }
};

class GetNameVisitor : public Visitor
{
public:
    void visit(IPhone *) override { name = "iPhone"; }
    void visit(XiaomiPhone *phone) override { name = "Xiaomi"; }
    std::string getName() { return name; }
private:
    std::string name;
};

int main()
{
    Phone *normalPhone = new IPhone;
    Phone *makarPhone = new XiaomiPhone;

    GetNameVisitor nameReceiver;

    normalPhone->accept(nameReceiver);
    std::cout << nameReceiver.getName() << std::endl;
    makarPhone->accept(nameReceiver);
    std::cout << nameReceiver.getName() << std::endl;

    return 0;
}
