#include <iostream>

struct S_built_in {
  int a;
  double b;
  char c;
  // S_built_in() = default;
};

struct S_custom_type {
  std::string s;
  // S_custom_type() = default;
};

int main() {
  S_built_in s1;    // calls default constructor
  S_built_in s2{};  // calls {} on each member
  std::cout << s1.a << "--" << s1.b << "--" << s1.c << "\n";
  std::cout << s2.a << "--" << s2.b << "--" << s2.c << "\n";

  S_custom_type sc;  // calls default constructor
  std::cout << sc.s << std::endl;

  return 0;
}
