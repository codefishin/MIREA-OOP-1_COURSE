#include "MyClass1.hpp"
MyClass1::MyClass1(std::string _name, int _data) : name(_name+"_1"),
data(pow(_data,1))
{
}
void MyClass1::get()
{
std::cout << this->name << " " << this->data << "\n";
}
