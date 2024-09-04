#include "cl_base.hpp"
cl_base::cl_base(cl_base* headptr, std::string name)
{
  p_head_object = headptr; // Указатель на головной объект
  s_object_name = name; // Наименование объекта
  if ( p_head_object )
  {
    p_head_object -> subordinate_objects.push_back ( this ); // добавление в состав подчиненных головного объекта
  }
}
bool cl_base::s_set_object_name(std::string name)
{
  if(p_head_object == nullptr)
  {
    s_object_name = name;
    return true;
  }
  if(p_head_object->p_get_object_by_name(name) == nullptr)
  {
    s_object_name = name;
    return true;
  }
  return false;
}
std::string cl_base::s_get_object_name()
{
  return s_object_name;
}
cl_base * cl_base::p_get_head_object()
{
  return p_head_object;
}
void cl_base::s_print_subordinate_objects()
{
  if(subordinate_objects.size() > 0)
  {
    std::cout << "\n" << s_object_name;
    for(int i = 0; i < subordinate_objects.size();i++)
    {
      std::cout << " " << subordinate_objects[i]->s_get_object_name();
    }
    for(int i = 0; i < subordinate_objects.size();i++)
    {
      subordinate_objects[i]->s_print_subordinate_objects();
    }
  }
}
cl_base * cl_base::p_get_object_by_name(std::string name)
{
  for(int i = 0; i < subordinate_objects.size();i++)
  {
    if (subordinate_objects[i]->s_get_object_name() == name)
    {
      return subordinate_objects[i];
    }
  }
return nullptr;
}
