#include "MyClass3.hpp"
MyClass3::MyClass3(std::string _name, int _data) : MyClass2(_name, _data),
name(_name+"_3"),data(pow(_data,3))
{
}
void MyClass3::get()
{
std::cout << this->name << " " << this->data << "\n";
}
