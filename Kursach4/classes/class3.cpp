#include "class3.hpp"
class3::class3(cl_base * headptr, std::string name) : cl_base(headptr,name,3)
{
// Добавился параметр, обозначающий тип объекта.
}
void class3::f_signal(std::string & msg)
{
  std::cout << "Signal from " << get_abs() << '\n';
  msg += " (class: 3)";
}
void class3::f_handler(std::string msg)
{
  std::cout << "Signal to " << get_abs() << " Text: " + msg << '\n';
}
