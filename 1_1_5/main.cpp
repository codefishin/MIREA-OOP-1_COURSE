#include <stdlib.h>
#include <stdio.h>
#include <iostream>
int main()
{
  int N{};
  std::cin >> N;
  if(N < 1 || N > 9)
  {
    std::cout << "N is wrong: " << N;
    return 0;
  }
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      std::cout << j;
      if (j != i)
      {
        std::cout << " ";
      }
    }
    if (i != N)
    {
      std::cout << "\n";
    }
  }
}
