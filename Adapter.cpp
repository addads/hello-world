/*
ADAPTER
Convert the interface of a class into another interface clients expects. 

#include <iostream>

{
public:
	virtual void print() = 0;
};

class Adaptee
{
public:
	Adaptee()
	{
		std::cout << "Adaptee \n";
	}
	void oldPrint()
	{
		std::cout << "oldPrint \n";
	}
};

class Adapter : public Adapt, private Adaptee
{
public:
	Adapter() : Adaptee()
	{
		std::cout << "Adapter \n";
	}
	void print() override
	{
		std::cout << "print \n";
		oldPrint();
	}
};