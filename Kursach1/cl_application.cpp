#include "cl_application.hpp"
cl_application::cl_application(cl_base * headptr) : cl_base(headptr)
{
}
void cl_application::build_tree_objects()
{
  cl_base * Ptr_head = this;
  cl_base * Ptr_Last_Add_Item = nullptr;
  cl_base * Find_Item = nullptr;
  std::string Head_Name;
  std::string Item_Name;
  std::cin >> Head_Name;
  s_set_object_name(Head_Name);
  std::cin >> Head_Name >> Item_Name;
  while (Head_Name != Item_Name)
  {
    if (Ptr_head->s_get_object_name() != Head_Name)
    {
      if (Ptr_Last_Add_Item != nullptr)
      {
        if (Ptr_Last_Add_Item->s_get_object_name() == Head_Name)
        {
          Ptr_head = Ptr_Last_Add_Item;
        }
      }
  }
  if (Ptr_head->s_get_object_name() == Head_Name)
  {
    Find_Item = Ptr_head->p_get_object_by_name(Item_Name);
    if (Find_Item == nullptr)
    {
      Ptr_Last_Add_Item = new cl_nod(Ptr_head,Item_Name);
    }
  }
  std::cin >> Head_Name >> Item_Name;
  }
}
int cl_application::exec_app()
{
  std::cout << s_get_object_name();
  s_print_subordinate_objects();
  return 1;
}
