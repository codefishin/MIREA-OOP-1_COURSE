#include <stdlib.h>
#include <stdio.h>
#include "MyClass4.hpp"
int main()
{
  std::string name;
  int data;
  std::cin >> name >> data;
  if (data < 2 || data > 10) return 0;
  MyClass1 * object = (MyClass1 *)(new MyClass4(name,data));
  object->get();
  ((MyClass2 *)object)->get();
  ((MyClass3 *)object)->get();
  ((MyClass4 *)object)->get();
  return 1;
}
