#include "pch.h"
#include "App.hpp"

void App::app()
{
   LoginServer x;
   bool er = x.found();
   if (er == false)
   {
      PopUp pop;
      pop.popUp("Login Bad", 1);
   }

   Communication c;
   bool err = c.serv();
   if (err == false)
   {
      PopUp pop;
      pop.popUp("Service Bad", 2);
   }
}
