#ifndef __CLASS4__H
#define __CLASS4__H
#include "cl_base.hpp"
class class4 : public cl_base
{
  public:
    class4(cl_base * headptr, std::string name);
    // кв4
    void f_signal(std::string& msg);
    void f_handler(std::string msg);
};
#endif
