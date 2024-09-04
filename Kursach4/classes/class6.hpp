#ifndef __CLASS6__H
#define __CLASS6__H
#include "cl_base.hpp"
class class6 : public cl_base
{
  public:
    class6(cl_base * headptr, std::string name);
    // кв4
    void f_signal(std::string& msg);
    void f_handler(std::string msg);
};
#endif
