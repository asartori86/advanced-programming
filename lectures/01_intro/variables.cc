#include <iostream>
#include <string>

int main() {
  // built-in types
  int a{-1}; // long long int, unsigned int
  // int a = -1; //  is fine
  std::cout << a << std::endl;

  double b{2.2}; // long double, float
  std::cout << b << std::endl;

  char c{'r'}; // unsigned char, signed char, wchar_t
  std::cout << c << std::endl;

  bool t{true}; // false,0,1,...
  std::cout << t << std::endl;

  // check the size of a variable type
  std::cout << "on my machine the size of an int is " << sizeof(int)
            << " bytes\n";
  std::cout << "on my machine the size of an double is " << sizeof(double)
            << " bytes\n";
  std::cout << "on my machine the size of a char is " << sizeof(char)
            << " bytes\n";
  std::cout << "on my machine the size of a bool is " << sizeof(bool)
            << " bytes\n";

  // if you want to make sure an int is e.g. 2 bytes use special
  // variables names
  int16_t small_int{};
  std::cout << "on every machine the size of variable small_int is "
            << sizeof(small_int) << " bytes\n";

  // not built-in but useful :)
  std::string s{"Hello, World!\n"};
  std::cout << s;

  // narrowing effect
  int var = 6.9; // try to initialize var with the universal and
                 // uniform initialization

  std::cout << var << "\n";

  var += 7;
  var -= 7;
  var *= 7;
  var /= 7;
  var %= 7;
  var++;
  ++var;

  var = a + b; // works also for strings
  var = a - b;
  var = a * b;
  var = a % var; // modulus operator just between integers

  bool test; 			
  test = a == b;
  test = a < b;
  test = a > b;
  test = a <= b;
  test = a >= b;
  test = a != b;

  if (test) {
    std::cout << "test is true\n";
  } else {
    std::cout << "test is false\n";
  }

  return 0;
}
