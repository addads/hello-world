/*FACADE
A single class that represents an entire subsystem.*/

#include "stdafx.h"

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 
#include <functional> 
#include <unordered_map>
#include <map>

class SubOne
{
public:
	void MethodOne()
	{
		std::cout << "SubSystem 1\n";
	};
};

class SubTwo
{
public:
	void MethodTwo()
	{
		std::cout << "SubSystem 2\n";
	};
};

class SubThree
{
public:
	void MethodThree()
	{
		std::cout << "SubSystem 3\n";
	}
};

class Facade
{
public:
	Facade()
	{
		pOne = new SubOne();
		pTwo = new SubTwo();
		pThree = new SubThree();
	}
	void MethodA()
	{
		std::cout << "Facade::MethodA\n";
		pOne->MethodOne();
		pTwo->MethodTwo();
	}
	void MethodB()
	{
		std::cout << "Facade::MethodB\n";
		pTwo->MethodTwo();
		pThree->MethodThree();
	}
private:
	SubOne * pOne;
	SubTwo *pTwo;
	SubThree *pThree;
};

