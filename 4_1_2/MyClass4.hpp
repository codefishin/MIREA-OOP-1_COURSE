#ifndef __MYCLASS4__H
#define __MYCLASS4__H
#include "MyClass3.hpp"
class MyClass4 : private MyClass3
{
private:
int data;
std::string name;
public:
MyClass4(std::string _name, int _data);
void get();
};
#endif
