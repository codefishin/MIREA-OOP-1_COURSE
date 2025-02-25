#include "MyClass.hpp"
MyClass::MyClass()
{
  std::cout << "Default constructor\n";
}
MyClass::MyClass(int size)
{
  myarray = new int[size];
  std::cout << "Constructor set\n";
  this->size = size;
}
MyClass::MyClass(const MyClass& obj)
{
  std::cout << "Copy constructor\n";
  size = obj.size;
  myarray = new int[size];
  for(int i = 0; i < size; i++) myarray[i] = obj.myarray[i];
}
MyClass::~MyClass()
{
  std::cout << "Destructor";
  if(myarray != nullptr) delete[] myarray;
}
void MyClass::input()
{
  for(int i = 0; i < size; i++) std::cin >> myarray[i];
}
int MyClass::method1()
{
  int temp = 0;
  for(int i = 0; i < size; i = i+2)
  {
    myarray[i] = myarray[i] + myarray[i+1];
    temp = temp + myarray[i];
  }
  return temp;
}
int MyClass::method2()
{
  int temp = 0;
  for(int i = 0; i < size; i = i+2)
  {
    myarray[i] = myarray[i] * myarray[i+1];
    temp = temp + myarray[i];
  }
  return temp;
}
int MyClass::getSum()
{
  int temp = 0;
  for(int i = 0; i < size; i++) temp = temp + myarray[i];
  return temp;
}
