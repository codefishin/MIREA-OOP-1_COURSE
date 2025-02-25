#ifndef __MYCLASS__H
#define __MYCLASS__H
#include <iostream>
class MyClass
{
private:
  int * myarray;
  int size;
public:
  MyClass();
  MyClass(int size);
  MyClass(const MyClass & obj);
  ~MyClass();
  void input();
  int getSum();
  int method1();
  int method2();
};
#endif
