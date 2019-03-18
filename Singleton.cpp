// Singleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

class Singleton
{
private:

   Singleton() {}

   std::string mStr;

public:

   Singleton(const Singleton &old) = delete;

   const Singleton &operator=(const Singleton &old) = delete;

   Singleton(Singleton &&old) = delete;

   Singleton &operator=(Singleton &&old) = delete;

   static Singleton& getInstance()
   {
      static Singleton instance;
      return instance;
   }

   std::string getString()
   {
      return mStr;
   }

   void setString(const std::string &newStr)
   {
      mStr = newStr;
   }
};

int main()
{
    Singleton &s = Singleton::getInstance();

    Singleton &ss = Singleton::getInstance();
    s.setString("Afara ploua");
    std::cout << s.getString() << '\n' << ss.getString() << std::endl;
    ss.setString("Afara ninge");
    if (&s == &ss)
    {
       std::cout << &s << "\n" << &ss << std::endl;
    }

    std::cout << s.getString() << '\n' << ss.getString() << std::endl;
    

    return 0;
}

