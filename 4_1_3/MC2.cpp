#include "MC2.hpp"
MC2::MC2(std::string _id) : MC1(_id + "_2")
{
id = _id + "_2";
}
std::string MC2::get()
{
return this->id;
}
