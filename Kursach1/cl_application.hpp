#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H
#include "cl_nod.hpp"
class cl_application : public cl_base
{
  public:
    cl_application(cl_base* headptr);
    void build_tree_objects();
    int exec_app();
};
#endif
