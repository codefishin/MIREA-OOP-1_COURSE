#include <stdlib.h>
#include <stdio.h>
#include "MyClass.hpp"
void func(MyClass obj)
{
  obj.method2();
  std::cout << obj.getSum() << "\n";
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
  MyClass obj(size);
  obj.input();
  func(obj);
  std::cout << "\n";
  obj.method1();
  std::cout << obj.getSum() << "\n";
}
