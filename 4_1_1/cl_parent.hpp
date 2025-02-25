#ifndef __CL_PARENT__H
#define __CL_PARENT__H
#include <iostream>
class cl_parent
{
private:
int privateData;
void privateMethod(int Pr);
public:
int publicData;
cl_parent(int publicPr, int privatePr);
void publicMethod(int publicPr, int Pr);
void get();
};
#endif
