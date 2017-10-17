#include <iostream>

enum color { red, yellow, green };
// enum color{red=0, yellow=1, green=2}; // equivalent

void dwim(const color c) {
  switch (c) {
    case red:
      std::cout << "option 1: red\n";
      break;
    case yellow:
      std::cout << "option 2: yellow\n";
      break;
    case green:
      std::cout << "option 3: green\n";
      break;
    default:
      std::cout << "unknown option\n";
      break;
  }
}

int main(int argc, char* argv[]) {
  color opt = red;
  // opt = 3; // cannot assign int to enum
  int a = opt;  // but they implicitly converts to integers

  dwim(opt);

  dwim(color(2));

  dwim(color(6));  // ???

  return 0;
}
