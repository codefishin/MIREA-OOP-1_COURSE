#include "MyClass.hpp"
#include <iostream>
MyClass::MyClass(int i_data)
{
  i_public = i_data;
  i_private = 2*i_data;
};
void MyClass::print()
{
  std::cout << "Value of the available property " << i_public << "; ";
  std::cout << "Value of a hidden property " << i_private << "\n";
};
void MyClass::changevalue()
{
  i_public += 1;
  i_private += 4;
};
void MyClass::changevalueprivate()
{
  i_public += 5;
  i_private += 7;
};
void MyClass::summon()
{
  changevalueprivate();
};
