#ifndef __MYCLASS__H
#define __MYCLASS__H
#include "cl_parent.hpp"
class MyClass : public cl_parent
{
private:
int privateData;
public:
int publicData;
MyClass(int publicPr, int privatePr);
void publicMethod(int publicPr, int privatePr);
void get();
};
#endif
