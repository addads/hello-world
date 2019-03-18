// Composite.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <vector>
#include <iostream>

class Base
{
public:
   Base(int data) : mData(data) {}

   virtual void display() = 0;

protected:
   int mData;
};

class Composite : public Base
{
public:
   Composite(int data) : Base(data) {}

   void add(Base* obj)
   {
      mObj.push_back(obj);
   }

   void display() override
   {
      std::cout << mData << std::endl;

      for (auto &elem : mObj)
      {
         elem->display();
      }

   }

private:
   std::vector<Base*> mObj;
};

class Leaf : public Base
{
public:
   Leaf(int data) : Base(data) {}

   void display() override
   {
      std::cout << mData << std::endl;
   }
};

int main()
{
    std::cout << "Hello World!\n";

    auto root = new Composite(0);

    auto container1 = new Composite(7);
    container1->add(new Leaf(10));
    container1->add(new Leaf(12));
    root->add(container1);

    auto container2 = new Composite(20);
    container2->add(new Leaf(21));
    root->add(container2);

    root->add(new Leaf(31));
    root->add(new Leaf(32));
    root->add(new Leaf(33));

    root->display();

    return 0;

}

