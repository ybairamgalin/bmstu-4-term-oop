# Лекции ООП

* __Лекция 11__
  
    Приведение типов с помощью `static_cast, dynamic_cast, ...`,
    шаблон фабричный метод

## Шаблоны
Шаблон (паттерн) - готовое решение, но его приходится адаптировать под 
конкретную задачу. При использовании паттернов код становится более читаемый 
-> проще взаимодействовать с коллегами.

UML диаграмма классов - диаграмма сущностей и связей между сущностями.

|<имя>|
|---|
|- <поля> |
|+ <методы>|
 
Связи можем разделить на 4 вида.
1. Зависимость - - -> (одна сущность зависит от другой (изменение одной сущности
   может влиять на другую))
2. Ассоциация  -----> (делится на несколько вариантов: 
   агрегация < >--->(), композиция (<->--->) (один объект создает в себе
   элементы другого)
3. Наследование (делится на обощение ------<> и реализацию , - - - -<>)

Можно разделить паттерны на
- Архитектурные
- Пораждающие
- Поведения
- Структурные

### Фабричный метод

#### Проблема
При модификации программы при необходимости подмены один оббъект на другой 
при импользовани стандартного способа 

```A *p = new B``` 

необходимо найти все места создания объекта (изменять много кода)
#### Идея
Делегировать создание объекта вспомогательному классу, тем самым сможем
расширять функционал без изменения уже написанного кода.

Кроме того, добавим также класс который будет принимать решение о создании
объекта во время выполнения программы.
#### UML 
![img.png](patterns/uml/FactoryMethod.png)

#### Реализация
Самая простая реализация, но лучше использовать `unique_ptr/shared_ptr`
```c++
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

```

#### Особенности
- Стоит отметить, что при использовании фабричного метода появляется 
  необходимость в сущности, которая решает какой объект создавать.
  На UML это можно отметить как еще один класс `Solution`, использующий 
  `Creator`.
- В `Solution` может быть добавлена таблица на основе данных в которой может 
  приниматься решение (не особо понял)

### Абстрактная фабрика
#### Проблема
Допустим мы используем библиотеку для отрисовки графиков, но в один момент 
ее надо заменить на другую. Хотелось бы делать это не изменяя написанный код 
и не выискивая все применения одной библиотеки
#### Идея
Выделить абстрактного создателя, который по запросу `Solution` будет 
создавать нужную сущность (при этом сущности могут быть не родственными)
но должны быть объеденены общим интерфейсом. 
#### UML
![img.png](patterns/uml/AbstractFactory.png)
#### Реализация
```c++
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
    CarSolution(std::string config) { this->config = config; }
    AbstractCarFactory *getCreator()
    {
        if (config == "BMW") return new BmwCarFactory;
        if (config == "MERCEDES") return new MercedesCarFactory;

        throw;
    }

private:
    std::string config;
};

int main()
{
    CarSolution solver = CarSolution("BMW");

    Engine *eng = solver.getCreator()->createEngine();
    Wheel* wheel = solver.getCreator()->createWheel();

    eng->info();
    wheel->info();

    CarSolution newSolver = CarSolution("MERCEDES");

    eng = newSolver.getCreator()->createEngine();
    wheel = newSolver.getCreator()->createWheel();

    eng->info();
    wheel->info();

    return 0;
}
```

## Проектирование

При проетировании системы стоит четко выделять сущности, которые отвечают
за создание объектов

