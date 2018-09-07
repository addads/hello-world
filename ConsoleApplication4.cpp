// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Builder.cpp"
#include "AbstractFactory.cpp"
#include "Adapter.cpp"
#include "Composite.cpp"
#include "Bridge.cpp"
#include "Facade.cpp"
#include "Proxy.cpp"
#include "Prototype.cpp"
#include "Memento.cpp"
#include "Decorator.cpp"
#include "Flyweight.cpp"
#include "Iterator.cpp"

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 
#include <functional> 
#include <unordered_map>
#include <map>



Iterator *ConcreteAggregate::createIterator()
{
	return new ConcreteIterator(this);
}

int main()
{
	Do doo;
	OneBuilderBuilder oneBuilder;
	TwoBuilderBuilder twoBuilder;
	doo.makeBuilder(&oneBuilder);
	doo.print();
	doo.makeBuilder(&twoBuilder);
	doo.print();

	std::cout << "\n";
	Factory ff;
	ff.NewBig("one")->Run();
	ff.NewBig("one")->Stop();
	ff.NewBig("two")->Run();
	ff.NewBig("two")->Stop();

	std::cout << "\n";
	Adapt *a = new Adapter();
	a->print();

	std::cout << "\n";
	OneC onec;
	onec.print();
	TwoC twoc;
	twoc.print();
	ThreeC threec;
	threec.print();
	AllC allc;
	allc.add(&onec);
	allc.add(&twoc);
	allc.add(&threec);
	allc.print();

	std::cout << "\n";
	ImplementorA implementorA;
	ImplementorB implementorB;
	Refined aa(1, implementorA);
	Refined bb(2, implementorB);
	Abstract* vect[2];
	vect[0] = &aa;
	vect[1] = &bb;
	vect[0]->resize(10);
	vect[0]->printa();
	vect[1]->resize(10);
	vect[1]->printa();

	std::cout << "\n";
	Facade *facade = new Facade();
	facade->MethodA();
	facade->MethodB();

	std::cout << "\n";
	Proxy p;
	p.request();

	std::cout << "\n";
	RecordFactory recfac;
	auto rec = recfac.createRecord(A);
	rec->print();
	rec = recfac.createRecord(B);
	rec->print();
	rec = recfac.createRecord(C);
	rec->print();

	std::cout << "\n";
	Originator *originator = new Originator;
	Care *caretaker = new Care(originator);
	originator->setState(1);
	caretaker->save();
	originator->setState(2);
	caretaker->save();
	originator->setState(3);
	caretaker->undo();
	std::cout << "State " << originator->getState() << std::endl;
	delete originator;
	delete caretaker;

	std::cout << "\n";
	Component *component = new DecoratorA(new DecoratorB(new ConcreteComponent));
	component->dostuff();
	
	std::cout << "\n";
	FlyweightFactory *factory = new FlyweightFactory;
	factory->getFlyweight(1)->operation();
	factory->getFlyweight(2)->operation();
	
	std::cout << "\n";
	ConcreteAggregate list = ConcreteAggregate(5);
	Iterator *it = list.createIterator();
	for (it; !it->isDone(); it->next()) 
	{
		std::cout << it->currentItem() << std::endl;
	}
	delete it;
	 

	return 0;
}

