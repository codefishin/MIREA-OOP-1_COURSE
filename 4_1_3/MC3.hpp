#ifndef __MC3__H
#define __MC3__H
#include "MC1.hpp"
class MC3 : public MC1
{
private:
std::string id;
public:
MC3(std::string _id);
std::string get();
};
#endif
