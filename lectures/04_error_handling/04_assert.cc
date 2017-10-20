#include <iostream>
#include <math.h>
#include <assert.h>

// implment a square root function that "deals with" negative
// numbers. Moreover according to the logic of the program, d should
// never be greater than 50
double square_root(const double d);

int main() {
  std::cout << "please insert a number\n";
  double number;
  std::cin >> number;
  double d = square_root(number);
  std::cout << "square root of " << number << " is " << d << '\n';
  return 0;
}

double square_root(const double d) {
  // test the pre-conditions
  assert(d >= 0 && d <= 50);
  // assert(d>=50 && d<=50 "d should be in the range [0,50]");
  return sqrt(d);
}
