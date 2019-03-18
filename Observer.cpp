// Observer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class Listener
{
public:
   virtual void update() = 0;
};

class FirstListener : public Listener
{
public:
   virtual void update() override
   {
      std::cout << "FiRsT" << std::endl;
   }
};

class SecondListener : public Listener
{
   virtual void update() override
   {
      std::cout << "sEcOnD" << std::endl;
   }
};

class SuperObserver
{
public:
   void attach(Listener *listener)
   {
      mListeners.push_back(listener);
      std::cout << "AtTaChEd" << std::endl;
   }

   void detach(Listener *listener)
   {
      for (auto &lis : mListeners)
      {
         if (lis == listener)
         {
            mListeners.erase(remove(mListeners.begin(), mListeners.end(), lis), mListeners.end());
            std::cout << "dEtAcHeD" << std::endl;
            return;
         }
      }
   }

   void notify()
   {
      for (auto& lis : mListeners)
      {
         lis->update();
      }
   }

private:

   std::vector<Listener*> mListeners;
};

int main()
{
    std::cout << "Hello World!\n";

    SuperObserver observer;
    auto first = new FirstListener;
    auto second = new SecondListener;

    observer.attach(first);
    observer.attach(second);
    observer.notify();

    observer.detach(second);
    observer.notify();

    return 0;
}


