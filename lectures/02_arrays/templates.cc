#include <iostream>

template <typename num> class Matrix {
  num *elem;
  const size_t n;

public:
  Matrix(const size_t &row_size, const size_t &col_size)
      : elem{new num[row_size * col_size]}, n{row_size} {}
  ~Matrix() { delete[] elem; }
  num &operator()(const unsigned int i, const unsigned int j) {
    return elem[i * n + j];
  }
};

int main() {
  auto c = 0.0;
  Matrix<double> m_int(3, 3);
  for (auto i = 0; i < 3; ++i)
    for (auto j = 0; j < 3; ++j, ++c)
      m_int(i, j) = c;

  for (auto i = 0; i < 3; ++i) {
    for (auto j = 0; j < 3; ++j, ++c)
      std::cout << m_int(i, j) << " ";
    std::cout << '\n';
  }
  return 0;
}
