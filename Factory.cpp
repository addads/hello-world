// Factory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

class Base
{
public:
   virtual void make() = 0;
};

class One : public Base
{
public:
   void make() override
   {
      std::cout << "SuPeR mAkE oNe OmG" << std::endl;
   }
};

class Two : public Base
{
public:
   void make() override
   {
      std::cout << "sUpEr MaKe TwO" << std::endl;
   }
};

class Three : public Base
{
public:
   void make() override
   {
      std::cout << "DuPeR mAkE tHrEe Me" << std::endl;
   }
};

class Die : public Base
{
public:
   void make() override
   {
      std::cout << "dIeEeEeEeEe. . .." << std::endl;
   }
};

class Factory
{
public:
   static Base* create(std::string obj)
   {
      if (obj == "One")
      {
         return new One();
      }

      if (obj == "Two")
      {
         return new Two();
      }

      if (obj == "Three")
      {
         return new Three();
      }

      return new Die();
   }
};

int main()
{
   Base* one = Factory::create("One");
   Base* two = Factory::create("Two");
   Base* three = Factory::create("Three");
   Base* four = Factory::create("Four");

   one->make();
   two->make();
   three->make();
   four->make();

   delete one, two, three, four;

   std::cout << "Hello World!\n";

   return 0;
}

