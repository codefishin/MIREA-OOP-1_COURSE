#include "MC8.hpp"
MC8::MC8(std::string _id) : MC6(_id + "_8"), MC7(_id + "_8"), MC1(_id +
"_8")
{
id = _id + "_8";
}
std::string MC8::get()
{
return this->id;
}
