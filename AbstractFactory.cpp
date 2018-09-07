/*ABSTRACT FACTORY
Provide an interface for creating families of related or dependent objects without specifying their concrete classes.
Factories and products are the key elements to Abstract Factory pattern. Also the word families used in the definition distinguishes Abstract Factory pattern from other creational patterns, which involve only one kind of object.*/

#include "stdafx.h"

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 
#include <functional> 
#include <unordered_map>
#include <map>

class Big
{
public:
	virtual void Run() = 0;
	virtual void Stop() = 0;

	virtual ~Big() {};
};

class One : public Big
{
public:
	void Run() override
	{
		std::cout << "One run \n";
	};
	void Stop() override
	{
		std::cout << "One stop \n";
	};
	virtual ~One() {};
};
class Two : public Big
{
public:
	void Run() override
	{
		std::cout << "Two run \n";
	};
	void Stop() override
	{
		std::cout << "Two stop \n";
	};
	virtual ~Two() {};
};

class Factory
{
public:
	static Big *NewBig(const std::string &description)
	{
		if (description == "one")
			return new One;
		if (description == "two")
			return new Two;
		return nullptr;
	}
};
