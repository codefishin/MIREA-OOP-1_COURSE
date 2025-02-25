#ifndef __MC2__H
#define __MC2__H
#include "MC1.hpp"
class MC2 : public MC1
{
private:
std::string id;
public:
MC2(std::string _id);
std::string get();
};
#endif
