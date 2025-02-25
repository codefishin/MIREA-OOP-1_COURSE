#include "cl_parent.hpp"
cl_parent::cl_parent(int publicPr, int privatePr) : publicData(publicPr)
{
this->privateMethod(privatePr);
}
void cl_parent::publicMethod(int publicPr, int Pr)
{
publicData = publicPr;
privateMethod(Pr);
}
void cl_parent::privateMethod(int privatePr)
{
this->privateData = 2 * privatePr;
}
void cl_parent::get()
{
std::cout << privateData << " " << publicData;
}
