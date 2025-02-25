#include "MC7.hpp"
MC7::MC7(std::string _id) : MC4(_id + "_7"),MC5(_id + "_7"), MC1(_id + "_7")
{
id = _id + "_7";
}
std::string MC7::get()
{
return this->id;
}
