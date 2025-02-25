#include <stdlib.h>
#include <stdio.h>
#include "MC8.hpp"
int main()
{
  std::string id;
  std::cin >> id;
  MC8 * obj = new MC8(id);
  std::cout << ((MC1 *)((MC2 *)((MC6 *)(obj))))->get() << "\n";
  std::cout << ((MC1 *)((MC3 *)((MC6 *)(obj))))->get() << "\n";
  std::cout << ((MC1 *)((MC4 *)((MC7 *)(obj))))->get() << "\n"; 
  std::cout << ((MC1 *)((MC5 *)((MC7 *)(obj))))->get() << "\n"; 
  std::cout << ((MC2 *)((MC6 *)(obj)))->get() << "\n"; // вывод 8_6_2
  std::cout << ((MC3 *)((MC6 *)(obj)))->get() << "\n"; // вывод 8_6_3
  std::cout << ((MC4 *)((MC7 *)(obj)))->get() << "\n"; // вывод 8_7_4
  std::cout << ((MC5 *)((MC7 *)(obj)))->get() << "\n"; // вывод 8_7_5
  std::cout << ((MC6 *)(obj))->get() << "\n"; // вывод 8_6
  std::cout << ((MC7 *)(obj))->get() << "\n"; // вывод 8_7
  std::cout << obj->get(); // вывод 8
  delete obj;
}
