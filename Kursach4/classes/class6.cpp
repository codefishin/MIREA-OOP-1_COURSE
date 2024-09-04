#include "class6.hpp"
class6::class6(cl_base * headptr, std::string name) : cl_base(headptr,name,6)
{
// Добавился параметр, обозначающий тип объекта.
}
void class6::f_signal(std::string & msg)
{
  std::cout << "Signal from " << get_abs() << '\n';
  msg += " (class: 6)";
}
void class6::f_handler(std::string msg)
{
  std::cout << "Signal to " << get_abs() << " Text: " + msg << '\n';
}
