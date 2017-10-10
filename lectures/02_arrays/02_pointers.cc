#include <iostream>

int main() {
  int a{5};
  int* pi{&a};
  *pi = 9;
  std::cout << "a is now " << a << std::endl;

  char** ppc;

  int* ap[7];

  int (*fp)(char*);

  int* f(char*);

  void* pv{pi};
  // *pv; // we cannot dereference void*
  // ++pv; // we cannot increment. Why?
  int* pi2 = static_cast<int*>(pv);

  pi = nullptr;
  ppc = nullptr;
  // ap = nullptr;			// error, why?
  fp = nullptr;
  pv = nullptr;
  pi2 = 0;  // older codes. gets the nullptr

  const int* pc = &a;
  // *pc = 7; 			// error
  a = 15;  // I can obviously change a

  int* const cp = &a;
  int b = 8;
  a = b;
  // cp = &b			// error

  const int* const cpc = &a;  // points to a fixed memory location
  // and cannot change it
  a = 99;

  return 0;
}
