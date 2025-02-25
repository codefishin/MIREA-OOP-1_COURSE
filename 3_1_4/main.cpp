#include <stdlib.h>
#include <stdio.h>
#include "MyClass.hpp"
MyClass func(int size)
{
  MyClass obj(size);
  return obj;
}
int main()
{
  int size;
  std::cin >> size;
  if ((size <=2) || (size % 2 != 0))
  {
    std::cout << size << "?";
    return 0;
  }
  std::cout << size << "\n";
  MyClass obj1;
  obj1 = func(size);
  obj1.createArray();
  obj1.input();
  obj1.method2();
  MyClass obj2 = obj1;
  obj2.method1();
  obj1.printArray();
  std::cout << obj1.getSum() << "\n";
  obj2.printArray();
  std::cout << obj2.getSum() << "\n";
}
