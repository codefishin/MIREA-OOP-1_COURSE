#include "Tr_class.h"
#include <math.h>
Tr_class::Tr_class(int A, int B, int C)
{
  this->A=A;
  this->B=B;
  this->C=C;
}
int Tr_class::m_CalcPr()
{
  return A+B+C;
}
float Tr_class::m_CalcVol()
{
  float Pr_half = m_CalcPr()/2.0;
  return sqrt(Pr_half*(Pr_half-A)*(Pr_half-B)*(Pr_half-C));
}
