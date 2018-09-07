/*PROXY
An object representing another object.*/

#include "stdafx.h"

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 
#include <functional> 
#include <unordered_map>
#include <map>

class Subj
{
public:
	virtual void request() = 0;
	virtual ~Subj() {}
};

class RealSubj : public Subj
{
public:
	void request() override
	{
		std::cout << "RealSubj\n";
	}
};

class Proxy : public Subj
{
private:
	Subj * realsubj;
public:
	Proxy() : realsubj(new RealSubj()) {}
	~Proxy()
	{
		delete realsubj;
	}
	void request() override
	{
		realsubj->request();
	}
};

