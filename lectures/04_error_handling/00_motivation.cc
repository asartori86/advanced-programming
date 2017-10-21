#include <cmath>
#include <iostream>

double complicated_function(const double& num) {
  return num / 8.9;
}

int main() {
  double d = sqrt(-9);
  std::cout << complicated_function(d) << std::endl;
  return 0;
}
