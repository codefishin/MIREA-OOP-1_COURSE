#include <stdlib.h>
#include <stdio.h>
#include "MyClass.hpp"
int main()
{
  int size;
  int size2;
  std::cin >> size;
  if (size <= 4)
  {
    std::cout << size << "?";
    return(0);
  }
  std::cin >> size2;
  if (size2 <= 4)
  {
    std::cout << size2 << "?";
    return(0);
  }
  MyClass Obj1(size);
  MyClass Obj2(size2);
  int * temp_array = Obj1.array;
  Obj1 = Obj2;
  Obj1.array = temp_array;
  Obj1.get();
  Obj2.get();
}
