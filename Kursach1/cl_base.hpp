#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <string>
#include <vector>
#include <iostream>
class cl_base
{
  private:
    std::string s_object_name;
    cl_base * p_head_object;
    std::vector <cl_base*> subordinate_objects;
  public:
    cl_base(cl_base* headptr, std::string name = "Base_object");
    bool s_set_object_name(std::string name);
    std::string s_get_object_name();
    cl_base * p_get_head_object();
    void s_print_subordinate_objects();
    cl_base * p_get_object_by_name(std::string name);
};
#endif
