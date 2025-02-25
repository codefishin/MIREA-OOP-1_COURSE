#include "MyClass.hpp"
MyClass::MyClass(int size)
{
  array = new int[size];
  for (int i = 0; i < size; i++) array[i] = size;
}
void MyClass::get()
{
  for (int i = 0; i < array[0]; i++)
  {
    if (i + 1 == array[0])
    {
      std::cout << array[i] << "\n";
    }
    else
    {
      std::cout << array[i] << " ";
    }
  }
}
int * MyClass::return_array()
{
  return array;
}
void MyClass::set_array(int * new_array)
{
  array = new_array;
}
