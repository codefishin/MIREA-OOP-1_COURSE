#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H
#include "class2.hpp"
#include "class3.hpp"
#include "class4.hpp"
#include "class5.hpp"
#include "class6.hpp"
class cl_application : public cl_base 
{
  public:
    cl_application(cl_base* headptr);
    void build_tree_objects();
    int exec_app();
};
#endif
