/*MEMENTO
Capture and restore an object's internal state.*/

#include "stdafx.h"

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 
#include <functional> 
#include <unordered_map>
#include <map>

class Memento
{
private:
	friend class Originator;
	Memento(int s) : state(s) {}
	void setState(int s)
	{
		state = s;
	}
	int getState()
	{
		return state;
	}
	int state;
};

class Originator
{
public:
	void setState(int s)
	{
		std::cout << "Set state to " << s << std::endl;
		state = s;
	}
	int getState()
	{
		return state;
	}
	void setMemento(Memento *m)
	{
		state = m->getState();
	}
	Memento *createMemento()
	{
		return new Memento(state);
	}
private:
	int state;
};

class Care
{
public:
	Care(Originator *o) : originator(o) {}
	~Care()
	{
		for (unsigned int i = 0; i < history.size(); i++)
		{
			delete history.at(i);
		}
		history.clear();
	}
	void save()
	{
		std::cout << "Save state" << std::endl;;
		history.push_back(originator->createMemento());
	}
	void undo()
	{
		std::cout << "Undo state" << std::endl;;
		originator->setMemento(history.back());
		history.pop_back();
	}
private:
	Originator * originator;
	std::vector<Memento *> history;
};