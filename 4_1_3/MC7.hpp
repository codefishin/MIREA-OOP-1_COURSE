#ifndef __MC7__H
#define __MC7__H
#include "MC4.hpp"
#include "MC5.hpp"
class MC7 : public MC4, public MC5
{
private:
std::string id;
public:
MC7(std::string _id);
std::string get();
};
#endif
