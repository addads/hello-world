/*BRIDGE
Separates an object's abstraction from its implementation.*/


#include "stdafx.h"

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 
#include <functional> 
#include <unordered_map>
#include <map>


class Implementor
{
public:
	virtual void print(int) = 0;
	virtual ~Implementor() {}
};

class ImplementorA : public Implementor
{
public:
	ImplementorA() {}
	virtual ~ImplementorA() {}
	void print(int side) override
	{
		std::cout << "One " << side << std::endl;
	}
};

class ImplementorB : public Implementor
{
public:
	ImplementorB() {}
	virtual ~ImplementorB() {}
	void print(int side) override
	{
		std::cout << "Two " << side << std::endl;
	}
};

class Abstract
{
public:
	virtual void printa() = 0;
	virtual void resize(int pct) = 0;
	virtual ~Abstract() {}
};

class Refined : public Abstract
{
public:
	Refined(int s, Implementor& Implementor) :
		side(s), implementor(Implementor) {}
	virtual ~Refined() {}
	void printa() override
	{
		implementor.print(side);
	}
	void resize(int pct) override
	{
		side *= pct;
	}
private:
	int side;
	Implementor& implementor;
};


