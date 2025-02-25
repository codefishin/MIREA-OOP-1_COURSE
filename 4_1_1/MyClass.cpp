#include "MyClass.hpp"
MyClass::MyClass(int publicPr, int privatePr) : cl_parent(publicPr,
privatePr), publicData(publicPr), privateData(privatePr)
{
// Hi
}
void MyClass::publicMethod(int publicPr, int privatePr)
{
publicData = publicPr;
privateData = privatePr;
}
void MyClass::get()
{
std::cout << privateData << " " << publicData;
}
