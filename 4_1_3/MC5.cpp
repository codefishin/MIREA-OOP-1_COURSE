#include "MC5.hpp"
MC5::MC5(std::string _id) : MC1(_id + "_5")
{
id = _id + "_5";
}
std::string MC5::get()
{
return this->id;
}
