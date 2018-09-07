/*BUILDER
Separates object construction of a complex object from its representation 

#include "stdafx.h"

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 
#include <functional> 
#include <unordered_map>
#include <map>

class Builder
{
public:
	void setOne(const std::string& d)
	{
		one = d;
	}
	void setTwo(const std::string& s)
	{
		two = s;
	}
	void print() const
	{
		std::cout << one << ", " << two << std::endl;
	}
private:
	std::string one;
	std::string two;
};

class BuilderBuilder
{
public:
	virtual ~BuilderBuilder() {};

	Builder* getBuilder()
	{
		return builder.release();
	}
	void createNewProduct()
	{
		builder = std::make_unique<Builder>();
	}
	virtual void buildOne() = 0;
	virtual void buildTwo() = 0;
protected:
	std::unique_ptr<Builder> builder;
};

class OneBuilderBuilder : public BuilderBuilder
{
public:
	virtual ~OneBuilderBuilder() {};

	virtual void buildOne() override
	{
		builder->setOne("mere");
	}
	virtual void buildTwo() override
	{
		builder->setTwo("pere");
	}
};

class TwoBuilderBuilder : public BuilderBuilder
{
public:
	virtual ~TwoBuilderBuilder() {};

	virtual void buildOne() override
	{
		builder->setOne("ciocolata");
	}
	virtual void buildTwo()	override
	{
		builder->setTwo("vanilie");
	}
};

class Do
{
public:
	void print()
	{
		builderBuilder->getBuilder()->print();
	}
	void makeBuilder(BuilderBuilder* pb)
	{
		builderBuilder = pb;
		builderBuilder->createNewProduct();
		builderBuilder->buildOne();
		builderBuilder->buildTwo();
	}
private:
	BuilderBuilder * builderBuilder;
};
