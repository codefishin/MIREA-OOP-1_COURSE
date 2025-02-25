#include "MC6.hpp"
MC6::MC6(std::string _id) : MC2(_id + "_6"),MC3(_id + "_6")
{
id = _id + "_6";
}
std::string MC6::get()
{
return this->id;
}
