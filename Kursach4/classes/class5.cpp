#include "class5.hpp"
class5::class5(cl_base * headptr, std::string name) : cl_base(headptr,name,5)
{
// Добавился параметр, обозначающий тип объекта.
}
void class5::f_signal(std::string & msg)
{
  std::cout << "Signal from " << get_abs() << '\n';
  msg += " (class: 5)";
}
void class5::f_handler(std::string msg)
{
  std::cout << "Signal to " << get_abs() << " Text: " + msg << '\n';
}
