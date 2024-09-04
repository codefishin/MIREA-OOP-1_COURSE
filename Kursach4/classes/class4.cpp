#include "class4.hpp"
class4::class4(cl_base * headptr, std::string name) : cl_base(headptr,name,4)
{
// Добавился параметр, обозначающий тип объекта.
}
void class4::f_signal(std::string & msg)
{
  std::cout << "Signal from " << get_abs() << '\n';
  msg += " (class: 4)";
}
void class4::f_handler(std::string msg)
{
  std::cout << "Signal to " << get_abs() << " Text: " + msg << '\n';
}
