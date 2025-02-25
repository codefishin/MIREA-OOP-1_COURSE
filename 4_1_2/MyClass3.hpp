#ifndef __MYCLASS3__H
#define __MYCLASS3__H
#include "MyClass2.hpp"
class MyClass3 : private MyClass2
{
private:
int data;
std::string name;
public:
MyClass3(std::string _name, int _data);
void get();
};
#endif
