#include <iostream>

void print_array(double a[])
{
  *a=99.9;
}

int main()
{
  int ai[4];
  float af[9];
  ai[0] = 9; // first element
  af[8] = 3; // last element
  ai[88] = 7; // undefined behavior, no range checking

  for(size_t k=0; k<4; ++k)
    std::cout << "ai["<<k<<"] = "<<ai[k] <<'\n';
  
  std::cout << "------------------------------\n";

  for(auto x : af)
    std::cout << x << "\n";

  std::cout << "------------------------------\n";

  double ad[] {1.1,2.2,3.3};

  for(auto x : ad)
    std::cout << x << "\n";

  std::cout << "------------------------------\n";
  double ad2[7] {1.1,2.2,3.3};
  *ad2 = 9.9;			// an array is implicitly converted to a pointer to its first element;
  for(auto x : ad2)
    std::cout << x << "\n";

  // double ad3[2] {1,2,3,4}; // error
  
  return 0;
}
