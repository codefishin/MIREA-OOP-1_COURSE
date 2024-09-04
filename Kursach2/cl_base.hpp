#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <string>
#include <vector>
#include <iostream>
#include <queue>
class cl_base
{
  private:
    std::string s_object_name;
    cl_base * p_head_object;
    std::vector <cl_base*> subordinate_objects;
    int state = 0; // state check
  public:
    cl_base(cl_base* headptr, std::string name = "Base_object"); // V
    bool s_set_object_name(std::string name); // V
    std::string s_get_object_name(); // V
    cl_base * p_get_head_object();
    cl_base * p_get_object_by_name(std::string name);
    cl_base * p_get_branch(std::string target);
    cl_base * p_get_tree(std::string target);
    void print_branch();
    void print_branch_state();
    void set_obj_state(int new_state);
};
#endif
