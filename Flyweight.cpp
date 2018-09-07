/*FLYWEIGHT
A fine-grained instance used for efficient sharing.*/

#include "stdafx.h"

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 
#include <functional> 
#include <unordered_map>
#include <map>

class Flyweight
{
public:
	virtual ~Flyweight() { }
	virtual void operation() = 0;
};

class AFlyweight : public Flyweight
{
public:
	AFlyweight(int i) : state(i) {}
	void operation() override
	{
		std::cout << "flyweight B " << state << std::endl;
	}
private:
	int state;
};

class FlyweightFactory {
public:
	virtual ~FlyweightFactory()
	{
		for (auto i : flies)
		{
			delete i.second;
		}
		flies.clear();
	}
	Flyweight *getFlyweight(int i)
	{
		if (flies.find(i) != flies.end())
		{
			return flies[i];
		}
		Flyweight *fly = new AFlyweight(i);
		flies.insert(std::pair<int, Flyweight*>(i, fly));
		return fly;
	}
private:
	std::map<int, Flyweight*> flies;
};
