
SRCS := FactoryMethod.exe AbstractFactory.exe Prototype.exe Builder.exe Adapter.exe Decorator.exe Mediator.exe Visitor.exe

.PHONY : all clean
all : $(SRCS)

%.exe : %.cpp
	g++ $< -Wall -Werror -std=c++14 -O0 -o $@

clean :
	rm *exe
