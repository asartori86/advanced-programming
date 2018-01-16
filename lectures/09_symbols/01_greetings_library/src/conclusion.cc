#include <iostream>
#include <conclusion.h>

void print_conclusion() {
#ifdef ITALIANO
  std::cout << "Ci vediamo giovedì\n";
#endif

#ifdef ENGLISH
  std::cout << "See you on Thursday\n";
#endif
}
