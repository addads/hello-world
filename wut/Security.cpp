#include "pch.h"
#include "Security.hpp"


std::string Security::secure()
{
   LoginForm login;
   std::string usern = login.get();

   if (usern.length() == 0)
   {
      return "";
   }

   std::cout << "crypt" << usern << std::endl;
   return "crypt" + usern;
}


std::string Security::get()
{
   return secure();
}