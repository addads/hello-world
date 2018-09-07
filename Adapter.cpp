/*
ADAPTER
Convert the interface of a class into another interface clients expects. Adapter lets classes work together that couldn't otherwise because of incompatible interfaces.*/#include "stdafx.h"

#include <iostream>
class Adapt
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
