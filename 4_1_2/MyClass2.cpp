#include "MyClass2.hpp"
MyClass2::MyClass2(std::string _name, int _data) : MyClass1(_name, _data),
name(_name+"_2"), data(pow(_data,2))
{
}
void MyClass2::get()
{
std::cout << this->name << " " << this->data << "\n";
}
