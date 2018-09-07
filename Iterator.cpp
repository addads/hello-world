/*ITERATOR
Sequentially access the elements of a collection.*/

#include "stdafx.h"

#include <iostream>
#include <vector>



class Iterator;
class Aggregate
{
public:
	virtual Iterator *createIterator() = 0;
};

class ConcreteAggregate : public Aggregate
{
public:
	ConcreteAggregate(const unsigned int i)
	{
		list = new int[i];
		for (auto a = 0; a != i; a++)
			list[a] = a + 1;
		count = i;
	}
	Iterator *createIterator();
	~ConcreteAggregate()
	{
		delete[] list;
	}
	unsigned int size() const
	{
		return count;
	}
	int at(unsigned int i)
	{
		return list[i];
	}
private:
	int *list;
	unsigned int count;
};

class Iterator
{
public:
	virtual ~Iterator() {}
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() const = 0;
	virtual int currentItem() const = 0;
};

class ConcreteIterator : public Iterator
{
public:
	ConcreteIterator(ConcreteAggregate *l) : list(l), i(0) {}
	void first() override
	{
		i = 0;
	}
	void next() override
	{
		i++;
	}
	bool isDone() const override
	{
		return (i >= list->size());
	}
	int currentItem() const override
	{
		if (isDone())
		{
			return -1;
		}
		return list->at(i);
	}
private:
	ConcreteAggregate * list;
	unsigned int i;
};
