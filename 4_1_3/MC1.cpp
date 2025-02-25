#include "MC1.hpp"
MC1::MC1(std::string _id)
{
id = _id + "_1";
}
std::string MC1::get()
{
return id;
}
