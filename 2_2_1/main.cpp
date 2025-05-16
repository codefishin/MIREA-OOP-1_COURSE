#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "MyClass.hpp"
int main()
{
  int i_data{};
  std::cin >> i_data;
  MyClass MyObj(i_data);
  MyObj.print();
  MyObj.changevalue();
  MyObj.print();
  std::cin >> i_data;
  MyObj.i_public = MyObj.i_public*i_data;
  MyObj.print();
  MyObj.summon();
  MyObj.print();
  return(0);
}
