#include <stdlib.h>
#include <stdio.h>
#include "MyClass.hpp"
MyClass * func(int size)
{
  MyClass * obj = new MyClass(size);
  obj->createArray();
  obj->input();
  obj->method2();
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
  MyClass * obj1;
  obj1 = func(size);
  obj1->method1();
  MyClass * obj2 = new MyClass(*obj1);
  obj2->method2();
  obj1->printArray();
  std::cout << obj1->getSum() << "\n";
  obj2->printArray();
  std::cout << obj2->getSum() << "\n";
  int * temp_array = obj2->returnpointer(); // Чтобы не потерять данные
  obj2 = obj1;
  obj1->method1();
  obj2->assignpointer(temp_array); // вернули старые данные
  obj2->printArray();
  std::cout << obj2->getSum();
  delete obj2;
}
