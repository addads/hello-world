#include "pch.h"
#include "LoginForm.hpp"


LoginForm::LoginForm() 
{ 
   nickname = ""; 
}

std::string LoginForm::get()
{
   hello();

   return nickname;
}

void LoginForm::text()
{
   std::cout << "What's your nickname?" << std::endl;
}

void LoginForm::in()
{
   std::cin >> nickname;

   while (nickname.length() == 0)
   {
      std::cin >> nickname;
   }

   std::cout << std::endl;
}

void LoginForm::display()
{
   std::cout << nickname << std::endl;
}

