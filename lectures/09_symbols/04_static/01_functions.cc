#include <iostream>

void dwim() {
  static int i = 0;
  ++i;
  std::cout << i << std::endl;
}

int main() {
  dwim();
  dwim();
  dwim();
  dwim();
  dwim();
  return 0;
}
