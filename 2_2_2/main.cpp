#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "MyClass.hpp"
int main()
{
  int i_data{};
  std::cin >> i_data;
  MyClass* MyObj = new MyClass(i_data);
  MyObj->print();
  MyObj->changevalue();
  MyObj->print();
  std::cin >> i_data;
  if(i_data > MyObj->i_public)
  {
    MyObj->i_public = 8*i_data;
  }
  MyObj->print();
  MyObj->summon();
  MyObj->print();
  return(0);
}
