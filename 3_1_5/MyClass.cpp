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
  std::cout << "\nDestructor\nDestructor";
  if(myarray != nullptr) delete[] myarray;
}
void MyClass::input()
{
  for(int i = 0; i < size; i++) std::cin >> myarray[i];
}
void MyClass::createArray()
{
  myarray = new int[size];
}
void MyClass::printArray()
{
  for (int i = 0; i < size; i++)
  {
    std::cout << myarray[i];
    if (i < size - 1) std::cout << " ";
  }
  std::cout << "\n";
}
void MyClass::method1()
{
  for(int i = 0; i < size; i = i+2)
  {
    myarray[i] = myarray[i] + myarray[i+1];
  }
}
void MyClass::method2()
{
  for(int i = 0; i < size; i = i+2)
  {
  myarray[i] = myarray[i] * myarray[i+1];
  }
}
int MyClass::getSum()
{
  int temp = 0;
  for(int i = 0; i < size; i++) temp = temp + myarray[i];
  return temp;
}
int * MyClass::returnpointer()
{
  return myarray;
}
void MyClass::assignpointer(int * ptr)
{
  myarray = ptr;
}
