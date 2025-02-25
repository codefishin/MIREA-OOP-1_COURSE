#ifndef __MYCLASS1__H
#define __MYCLASS1__H
#include <iostream>
#include <string>
#include <math.h>
class MyClass1
{
private:
int data;
std::string name;
public:
MyClass1(std::string _name, int _data);
void get();
};
#endif
