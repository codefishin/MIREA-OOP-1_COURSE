#ifndef __MC6__H
#define __MC6__H
#include "MC2.hpp"
#include "MC3.hpp"
class MC6 : public MC2, public MC3
{
private:
std::string id;
public:
MC6(std::string _id);
std::string get();
};
#endif
