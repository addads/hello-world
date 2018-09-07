/*COMPOSITE
Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual object and compositions of object uniformly.*/#include "stdafx.h"

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 
#include <functional> 
#include <unordered_map>
#include <map>

class Composite
{
public:
	virtual void print() const = 0;
	virtual void remove(Composite *g) {}
	virtual void add(Composite *g) {}
	virtual void getChild(int) {}
	virtual ~Composite() {}
};

class OneC : public Composite
{
public:
	void print() const override
	{
		std::cout << "One\n";
	}
};

class TwoC : public Composite
{
public:
	void print() const override
	{
		std::cout << "Two \n";
	}
};

class ThreeC : public Composite
{
public:
	void print() const override
	{
		std::cout << "Three \n";
	}
};

class AllC : public Composite
{
public:
	void print() const override
	{
		std::for_each(list.begin(), list.end(), std::mem_fun(&Composite::print));
	}

	void add(Composite *a) override
	{
		list.push_back(a);
	}

private:
	std::vector<Composite*> list;
};

