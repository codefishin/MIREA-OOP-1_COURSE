#include "class2.hpp"
class2::class2(cl_base * headptr, std::string name) : cl_base(headptr,name,2)
{
// Добавился параметр, обозначающий тип объекта.
}
void class2::f_signal(std::string & msg)
{
  std::cout << "Signal from " << get_abs() << '\n';
  msg += " (class: 2)";
}
void class2::f_handler(std::string msg)
{
  std::cout << "Signal to " << get_abs() << " Text: " + msg << '\n';
}
