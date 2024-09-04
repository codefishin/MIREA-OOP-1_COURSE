#ifndef __CLASS2__H
#define __CLASS2__H
#include "cl_base.hpp"
class class2 : public cl_base
{
  public:
    class2(cl_base * headptr, std::string name);
    // кв4
    void f_signal(std::string& msg);
    void f_handler(std::string msg);
};
#endif
