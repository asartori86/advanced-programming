#include <iostream>

int main() {
  int a{5};
  int *pi{&a};
  *pi = 9;
  std::cout << "a is now " << a << std::endl;

  char **ppc;
  int *ap[7];
  int (*fp)(char *);
  int *f(char *);
  void *pv{pi};
  // *pv; // we cannot dereference void*
  // ++pv; // we cannot increment. Why?
  int *pi2 = static_cast<int *>(pv);

  pi = nullptr;
  ppc = nullptr;
  // ap = nullptr;			// error, why?
  fp = nullptr;
  pv = nullptr;
  pi2 = 0; // older codes. gets the nullptr

  const int * cp = &a;
  // *cp = 7; 			// error
  int * const pc = &a;
  int b = 8;
  a = b; 			// I can obviously change a
  // pc = &b			// error
return 0;
}
