#ifndef __MYCLASS2__H
#define __MYCLASS2__H
#include "MyClass1.hpp"
class MyClass2 : private MyClass1
{
private:
int data;
std::string name;
public:
MyClass2(std::string _name, int _data);
void get();
};
#endif
