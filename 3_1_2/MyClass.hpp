#ifndef __MYCLASS__H
#define __MYCLASS__H
#include <iostream>
class MyClass
{
private:
  int * array;
public:
  MyClass(int size);
  void get();
  int * return_array();
  void set_array(int * new_array);
};
#endif
