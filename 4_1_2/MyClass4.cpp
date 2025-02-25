#include "MyClass4.hpp"
MyClass4::MyClass4(std::string _name, int _data) : MyClass3(_name, _data),
name(_name+"_4"),data(pow(_data,4))
{
}
void MyClass4::get()
{
std::cout << this->name << " " << this->data << "\n";
}
