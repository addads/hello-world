#pragma once
#include "pch.h"
#include "Form.hpp"

class LoginForm : public Form
{
public:

   LoginForm();

   std::string get();

private:

   void text();

   void in();

   void display();

   std::string nickname;

};