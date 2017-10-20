#include <iostream>
#include <math.h>
#include "error.h"

// implment a square root function that "deals with" negative
// numbers. Moreover according to the logic of the program, d should
// never be greater than 50
double square_root(const double d);

struct Square_root_invalid {
  std::string message;
};

int main() {
  try {
    std::cout << "please insert a number\n";
    double number;
    std::cin >> number;
    double d = square_root(number);
    std::cout << "square root of " << number << " is " << d << '\n';
    return 0;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n";
    return 3;
  }
}

double square_root(const double d) {
  // test the pre-conditions
  if (d < 0)
    errorspace::error("Cannot handle negative numbers. You gave me", d,
                      __FILE__, __LINE__);
  if (d > 50)
    errorspace::error(
        "The argument of square_root must be lower than 50. You gave me", d,
        __FILE__, __LINE__);
  return sqrt(d);
}
