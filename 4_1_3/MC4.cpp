#include "MC4.hpp"
MC4::MC4(std::string _id) : MC1(_id + "_4")
{
id = _id + "_4";
}
std::string MC4::get()
{
return this->id;
}
