#include <iostream>

enum class color { red, yellow, green };
// enum color{red=0, yellow=1, green=2}; // equivalent

void dwim(const color c) {
  switch (c) {
    case color::red:
      std::cout << "option 1: red\n";
      break;
    case color::yellow:
      std::cout << "option 2: yellow\n";
      break;
    case color::green:
      std::cout << "option 3: green\n";
      break;
    default:
      std::cout << "unknown option\n";
      break;
  }
}

int main() {
  color opt = color::red;
  // opt = 3;     // cannot assign int to enum
  // int a = opt; // and they don't implicitly convert to integers
  int a = int(opt);

  dwim(opt);

  dwim(color(2));

  dwim(color(6));  // ???

  return 0;
}
