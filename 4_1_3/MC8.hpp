#ifndef __MC8__H
#define __MC8__H
#include "MC6.hpp"
#include "MC7.hpp"
class MC8 : public MC6, public MC7
{
private:
std::string id;
public:
MC8(std::string _id);
std::string get();
};
#endif
