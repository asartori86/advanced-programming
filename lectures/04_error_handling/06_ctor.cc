#include <iostream>
#include "ap_error.h"
#include <vector>

class Vector {
  double* elem;

 public:
  Vector(const unsigned int l) : elem{new double[l]} {}
  ~Vector() noexcept { delete[] elem; }
};

class ManyResources {
  Vector v;
  double* second;

 public:
  ManyResources() : v{3} {
    try {
      second = new double[5];
      AP_error("AP_error in ManyResources ctor\n");
    } catch (...) {
      delete[] second;
      throw;
    }
  }
  ~ManyResources() noexcept { delete[] second; }
};

int main() {
  try {
    ManyResources mr;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
