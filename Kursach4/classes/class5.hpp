#ifndef __CLASS5__H
#define __CLASS5__H
#include "cl_base.hpp"
class class5 : public cl_base
{
  public:
    class5(cl_base * headptr, std::string name);
    // кв4
    void f_signal(std::string& msg);
    void f_handler(std::string msg);
};
#endif
