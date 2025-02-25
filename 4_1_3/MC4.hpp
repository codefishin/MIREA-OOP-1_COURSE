#ifndef __MC4__H
#define __MC4__H
#include "MC1.hpp"
class MC4 : virtual public MC1
{
private:
std::string id;
public:
MC4(std::string _id);
std::string get();
};
#endif
