#include "pch.h"
#include "Communication.hpp"
#include "Fuel.hpp"
#include "Weather.hpp"
#include "Parking.hpp"
#include "Parser.hpp"


bool Communication::serv()
{
   ServiceForm y;
   int i = y.get();

   std::string m;
   if (i == 0)
   {
      return false;
   }

   if (i == 1)
   {
      Fuel f;
      m = f.fuel();
   }

   if (i == 2)
   {
      Weather w;
      m = w.weather();
   }

   if (i == 3)
   {
      Parking p;
      m = p.parking();
   }

   Parser p;
   m = p.hello(m);
   std::cout << m << std::endl;

   return true;
}