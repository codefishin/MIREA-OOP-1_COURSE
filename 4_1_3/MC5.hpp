#ifndef __MC5__H
#define __MC5__H
#include "MC1.hpp"
class MC5 : virtual public MC1
{
private:
std::string id;
public:
MC5(std::string _id);
std::string get();
};
#endif
