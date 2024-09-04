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
    int state = 0;
  public:
  // кв1
    cl_base(cl_base* headptr, std::string name = "Base_object");
    bool s_set_object_name(std::string name);
    std::string s_get_object_name();
    cl_base * p_get_head_object();
    cl_base * p_get_object_by_name(std::string name);
  // кв2
    cl_base * p_get_branch(std::string target);
    cl_base * p_get_tree(std::string target);
    void set_obj_state(int new_state);
    void print();
    void print_state();
  //кв3
    bool change_head_pointer(cl_base * newptr);
    void delete_sub_obj(std::string s_name);
    cl_base * read_coords(std::string coords); // find obj by coordinates/coords
    ~cl_base();
};
#endif
