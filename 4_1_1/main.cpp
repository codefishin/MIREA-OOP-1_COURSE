#include <stdlib.h>
#include <stdio.h>
#include "MyClass.hpp"
int main()
{
  int publicData, privateData;
  std::cin >> privateData >> publicData;
  MyClass object(publicData, privateData);
  object.cl_parent::get();
  std::cout << "\n";
  object.get();
  std::cout << "\n";
  if(privateData > 0)
  {
    object.cl_parent::publicMethod(publicData - 1, privateData - 1);
    object.publicMethod(publicData + 1, privateData + 1);
    object.get();
    std::cout << "\n";
    object.cl_parent::get();
  }
  else
  {
    object.cl_parent::publicMethod(publicData + 1, privateData + 1);
    object.publicMethod(publicData - 1, privateData - 1);
    object.cl_parent::get();
    std::cout << "\n";
    object.get();
  }
  return(0);
}
