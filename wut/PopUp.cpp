#include "pch.h"
#include "PopUp.hpp"


void PopUp::popUp(std::string m, int rr)
{
   std::cout << m << std::endl;

   if (rr == 1)
   {
      LoginServer x;
      bool er = x.found();
      if (er == true)
         return;
      popUp("BadLogin", 1);
   }

   Communication c;
   bool err = c.serv();
   if (err == true)
      return;
   popUp("BadService", 2);

}
