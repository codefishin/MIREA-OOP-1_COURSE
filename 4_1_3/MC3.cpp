#include "MC3.hpp"
MC3::MC3(std::string _id) : MC1(_id + "_3")
{
id = _id + "_3";
}
std::string MC3::get()
{
return this->id;
}
