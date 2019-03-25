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

   void add(std::shared_ptr<Base> obj)
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
   std::vector<std::shared_ptr<Base> > mObj;
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

    auto root = std::make_shared<Composite>(0);

    auto container1 = std::make_shared<Composite>(7);
    container1->add(std::make_shared<Leaf>(10));
    container1->add(std::make_shared<Leaf>(12));
    root->add(container1);

    auto container2 = std::make_shared<Composite>(20);
    container2->add(std::make_shared<Leaf>(21));
    root->add(container2);

    root->add(std::make_shared<Leaf>(31));
    root->add(std::make_shared<Leaf>(32));
    root->add(std::make_shared<Leaf>(33));

    root->display();

    return 0;

}
