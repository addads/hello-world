#include "pch.h"
#include "LoginServer.hpp"


bool LoginServer::found()
{
   std::string us = sec.get();

   if (us.substr(0, 5) == "crypt")
   {
      std::cout << "Success" << std::endl;
      return true;
   }

   std::cout << "ERRor" << std::endl;
   return false;
}
