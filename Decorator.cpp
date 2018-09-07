/*
DECORATOR
Add responsibilities to objects dynamically. Decorators provide a flexible alternative to subclassing for extending functionality. */#include "stdafx.h"


#include <iostream>
class Component
{
public:
	virtual void dostuff() = 0;
};

class ConcreteComponent : public Component
{
public:
	void dostuff() override
	{
		std::cout << "do stuff " << std::endl;
	}
};

class Decorator : public Component
{
public:
	Decorator(Component *c) : component(c) {}
	virtual void dostuff() override
	{
		component->dostuff();
	}
private:
	Component * component;
};

class DecoratorA : public Decorator
{
public:
	DecoratorA(Component *c) : Decorator(c) {}
	void operation()
	{
		Decorator::dostuff();
		std::cout << "A\n";
	}
};

class DecoratorB : public Decorator
{
public:
	DecoratorB(Component *c) : Decorator(c) {}
	void dostuff() override
	{
		Decorator::dostuff();
		std::cout << "B\n";
	}
};