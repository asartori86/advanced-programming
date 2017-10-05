#include <iostream>

int main()
{
  int ai[4];
  float af[9];
  ai[0] = 9; // first element
  af[8] = 3; // last element
  ai[88] = 7; // undefined behavior, no range checking
  int i {3};

  int na[i];
  
  return 0;
}
