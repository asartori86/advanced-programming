#include <cstring>
#include <iostream>

int main() {
  int ai[4];
  float af[9];
  ai[0] = 9;    // first element
  af[8] = 3.3;  // last element
  ai[88] = 7;   // undefined behavior, no range checking

  for (size_t k = 0; k < 4; ++k)
    std::cout << "ai[" << k << "] = " << ai[k] << '\n';

  std::cout << "\n-------------------------------\n\n";

  for (size_t k = 0; k < 9; ++k)
    std::cout << "af[" << k << "] = " << af[k] << '\n';

  std::cout << "\n how is an array in memory?\n\n";

  for (size_t k = 0; k < 9; ++k)
    std::cout << "&af[" << k << "] = " << &af[k] << '\n';

  std::cout << "\n-------------------------------\n\n";

  double ad[7]{1.1, 2.2, 3.3};  // the rest is set to 0
  *ad = 9.9;                    // an array is implicitly converted to
                                // a pointer to its first element;
  for (size_t k = 0; k < 7; ++k)
    std::cout << ad[k] << "\n";

  // double ad2[2] {1,2,3,4}; // error

  std::cout << "\n-------------------------------\n\n";

  char word[]{"Hello"};
  char word2[]{'H', 'e', 'l', 'l', 'o', 0};
  if (strcmp(word, word2) == 0)  // word == word2 is
                                 // implementation-dependent (it might
                                 // compare the two pointers, i.e. the
                                 // two addresses of word and word2)
    std::cout << "same\n";
  else
    std::cout << "different\n";

  std::cout << "\n-------------------------------\n\n";

  std::string s{"Hello"};
  std::string s2{"hello"};
  if (s == s2)
    std::cout << "same\n";
  else
    std::cout << "different\n";

  return 0;
}
