// TemplateMethod.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


class Base
{
public:
   void execute()
   {
      start();
      play();
      say();
      sing();
      boat();
      end();
   }

private:
   void start()
   {
      std::cout << "sTaRtInG..." << std::endl;
   }

   virtual void play() = 0;
   virtual void say() = 0;
   virtual void sing() = 0;

   void boat()
   {
      std::cout << "BoAt" << std::endl;
   }

   void end()
   {
      std::cout << "bYe..." << std::endl;
   }

};

class First : public Base
{
   virtual void play() override
   {
      std::cout << "PlAy MiNeSwEePeR" << std::endl;
   }

   virtual void say() override
   {
      std::cout << "sAy YeS" << std::endl;
   }

   virtual void sing() override
   {
      std::cout << "dO yOu WaNnA bUiLd A sNoWmAn?" << std::endl;
   }
};

class Second : public Base
{
   virtual void play() override
   {
      std::cout << "PlAy SoLiTaRe" << std::endl;
   }

   virtual void say() override
   {
      std::cout << "sAy No" << std::endl;
   }

   virtual void sing() override
   {
      std::cout << "WeLcOmE tO mIsTeRy" << std::endl;
   }
};

class Third : public Base
{
   virtual void play() override
   {
      std::cout << "pLaY hEaRtS" << std::endl;
   }

   virtual void say() override
   {
      std::cout << "SaY mAyBe" << std::endl;
   }

   virtual void sing() override
   {
      std::cout << "sIx DeGrEeS" << std::endl;
   }
};

int main()
{
    std::cout << "Hello World!\n";

    First first;
    first.execute();

    Second second;
    second.execute();

    Third third;
    third.execute();

    return 0;
}

