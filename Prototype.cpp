/*PROTOTYPE
Specify the kind of objects to create using a prototypical instance, and create new object by copying this prototype.*/#include "stdafx.h"

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 
#include <functional> 
#include <unordered_map>
#include <map>

class Record
{
public:
	virtual ~Record() {}
	virtual void print() = 0;
	virtual std::unique_ptr<Record> clone() = 0;
};

class ARecord : public Record
{
private:
	std::string name;
public:
	ARecord(std::string n) : name(n) {}
	void print() override
	{
		std::cout << "Record A " << name << std::endl;
	}
	std::unique_ptr<Record> clone() override
	{
		return std::make_unique<ARecord>(*this);
	}
};

class BRecord : public Record
{
private:
	std::string name;
public:
	BRecord(std::string n) : name(n) {}
	void print() override
	{
		std::cout << "Record B " << name << std::endl;
	}
	std::unique_ptr<Record> clone() override
	{
		return std::make_unique<BRecord>(*this);
	}
};

class CRecord : public Record
{
private:
	std::string name;
public:
	CRecord(std::string n) : name(n) {}
	void print() override
	{
		std::cout << "Record C " << name << std::endl;
	}
	std::unique_ptr<Record> clone() override
	{
		return std::make_unique<CRecord>(*this);
	}
};

enum RecordType
{
	A,
	B,
	C
};

class RecordFactory
{
private:
	std::unordered_map<RecordType, std::unique_ptr<Record>, std::hash<int> > records;

public:
	RecordFactory()
	{
		records[A] = std::make_unique<ARecord>("mere");
		records[B] = std::make_unique<BRecord>("pere");
		records[C] = std::make_unique<CRecord>("capsuni");
	}
	std::unique_ptr<Record> createRecord(RecordType recordType)
	{
		return records[recordType]->clone();
	}
};

