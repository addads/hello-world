#pragma once

#include <iostream>
#include <string>

class Form
{
public:

   void hello();

private:

   virtual void text() = 0;
   virtual void in() = 0;
   virtual void display() = 0;
};