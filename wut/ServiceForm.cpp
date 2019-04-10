#include "pch.h"
#include "ServiceForm.hpp"


int ServiceForm::get()
{
   hello();
   return i;
}

void ServiceForm::text()
{
   std::cout << "1. Fuel?" << std::endl;
   std::cout << "2. Weather?" << std::endl;
   std::cout << "3. Parking?" << std::endl;
}

void ServiceForm::in()
{
   i = 0;
   std::cin >> i;
   std::cin.clear();
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   std::cout << std::endl;

   if (i > 3 || i < 1)
      i = 0;
}

void ServiceForm::display()
{
   if (i == 0)
   {
      std::cout << "die" << std::endl;
      return;
   }

   if (i == 1)
   {
      std::cout << "You want fuel" << std::endl;
      return;
   }

   if (i == 2)
   {
      std::cout << "You want weather" << std::endl;
      return;
   }

   if (i == 3)
   {
      std::cout << "You want parking" << std::endl;
      return;
   }
}


