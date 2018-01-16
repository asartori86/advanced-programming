#include <iostream>

struct Foo {
  static int s;
  // static int s = 0; // error
  static const int sc = 9;  // ok
  int i;
  Foo() { Foo::s += 1; }
};

int Foo::s = 0;

// int Foo::i = 2; // error, only static members can be defined out of class

int main() {
  Foo f1;
  Foo f2;
  std::cout << f1.s << '\n' << f2.s << '\n' << Foo::s << std::endl;
  return 0;
}
