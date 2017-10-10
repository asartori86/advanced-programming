#include <iostream>

template <typename num>
void print_vector(const num* vec, const int n);  // print_vector is
                                                 // parametrized
                                                 // w.r.t. the type
                                                 // num. If you will
                                                 // you can read it as
                                                 // "for all types
                                                 // num"

// reads from command line the size of an array
int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "I need exactly one argument\n";
    return 7;
  }

  const int len = atoi(argv[1]);

  int* v{new int[len]};
  double* vd{new double[len]};

  for (int i = 0; i < len; ++i) {
    v[i] = i * 1.1;
    vd[i] = i * 1.1;
  }

  print_vector<int>(v, len);
  std::cout << std::endl;

  print_vector(vd, len);

  delete[] v;
  delete[] vd;

  return 0;
}

template <typename num>
void print_vector(const num* vec, const int n) {
  const num* const vEnd = vec + n;  // sentinel. range-for loops rely on this
  for (; vec < vEnd; ++vec)
    std::cout << *vec << std::endl;
}
