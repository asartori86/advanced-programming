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
  Vector(const unsigned int l) : elem{new double[l]} {
    std::cout << "Vector\n";
  }
  ~Vector() noexcept {
    delete[] elem;
    std::cout << "~Vector\n";
  }
};

class ManyResources {
  double* ptr;
  Vector v;

 public:
  ManyResources() : ptr{nullptr}, v{3} {
    std::cout << "Manyresources\n";
    try {
      // AP_error("Error in ManyResources ctor\n"); // what happens here?
      ptr = new double[5];  // new(std::nothrow) double[5] could be better
      AP_error("Error in ManyResources ctor\n");
    } catch (...) {
      delete[] ptr;  // <----
      throw;
    }
  }

  ~ManyResources() noexcept {
    std::cout << "Manyresources\n";
    delete[] ptr;  // <----
  }
};

int main() {
  Foo f;
  int* raw_ptr = new int[7];
  try {
    // int * raw_ptr=new int[7]; // wrong because raw_ptr would not be visible
    // inside the catch-clause
    ManyResources mr;
    Bar b;

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;

    delete[] raw_ptr;  // <---
    return 1;

  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n" << std::endl;

    delete[] raw_ptr;  // <---
    return 2;
  }

  delete[] raw_ptr;  // <---
  return 0;
}
