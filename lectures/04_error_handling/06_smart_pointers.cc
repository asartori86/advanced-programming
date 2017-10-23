#include <iostream>
#include <vector>
#include <memory>

#include "ap_error.h"

class Vector {
  std::unique_ptr<double[]> elem;

 public:
  Vector(const unsigned int l) : elem{new double[l]} {}
};

class ManyResources {
  std::unique_ptr<double[]> ptr;
  Vector v;

 public:
  ManyResources() : ptr{new double[5]}, v{3} {
    AP_error("I am simulating something wrong\n");
  }
};

int main() {
  try {
    std::unique_ptr<int[]>{new int[7]};
    ManyResources mr;

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;

  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n" << std::endl;
    return 2;
  }

  return 0;
}
