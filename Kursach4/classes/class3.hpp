#ifndef __CLASS3__H
#define __CLASS3__H
#include "cl_base.hpp"
class class3 : public cl_base
{
  public:
    class3(cl_base * headptr, std::string name);
    // кв4
    void f_signal(std::string& msg);
    void f_handler(std::string msg);
};
#endif
