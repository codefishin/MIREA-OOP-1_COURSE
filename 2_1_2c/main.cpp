#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Tr_class.h"
int main()
{
  int A,B,C;
  std::cin >> A >> B >> C;
  Tr_class Tr_Obj(A,B,C);
  std::cout << "P = " << Tr_Obj.m_CalcPr() << "\n";
  std::cout << "S = " << Tr_Obj.m_CalcVol();
  return(0);
}
