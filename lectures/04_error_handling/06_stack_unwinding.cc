#include <iostream>
#include <vector>

#include "ap_error.h"

class Foo {
 public:
  Foo() { std::cout << "Foo\n"; }
  ~Foo() { std::cout << "~Foo\n"; }
};

class Bar {
 public:
  Bar() { std::cout << "Bar\n"; }
  ~Bar() { std::cout << "~Bar\n"; }
};

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
      AP_error("Error in ManyResources ctor\n");
    } catch (...) {
      delete[] second;
      throw;
    }
  }

  ~ManyResources() noexcept { delete[] second; }
};

int main() {
  Foo f;
  int* raw_ptr = new int[7];
  try {
    // int * raw_ptr=new int[7]; // wrong because raw_ptr would not be visible
    // inside the catch-clause
    ManyResources mr;
    Bar b;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    delete[] raw_ptr;  // house clening
    return 1;
  }
  return 0;
}
