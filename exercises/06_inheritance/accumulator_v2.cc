#include <iostream>
#include <memory>  //smart pointers
#include <ap_error.h>
#include <chrono>

template <typename num>
class Matrix {
 public:
  Matrix& operator+=(const Matrix<num>& r) {
    // check size
    for (int i = 0; i < _size; ++i)
      elem[i] += r[i];
    return *this;
  }

  Matrix(const int r, const int c)
      : rows{r}, cols{c}, _size{r * c}, elem{new num[_size]} {}

  num& operator[](const int i) noexcept { return elem[i]; }
  const num& operator[](const int i) const noexcept { return elem[i]; }

  // template <typename other_num>
  // friend class Matrix<other_num>;

  Matrix(const Matrix& m)
      : rows{m.rows}, cols{m.cols}, _size{m._size}, elem{new num[_size]} {
    std::cout << "copy ctor\n";
    if (m.moved)
      AP_error("cannot construct a Matrix from a moved one\n");
    for (int i = 0; i < _size; ++i)
      new (&elem[i]) num{m.elem[i]};
  }

  Matrix& operator=(const Matrix& m) {
    if (&m != this) {
      if (m.moved)
        AP_error("better not to copy from an already moved matrix\n");

      if (moved) {
        rows = m.rows;
        cols = m.cols;
        _size = m._size;
        elem.reset(new num[_size]);
        moved = false;
      }
      // check sizes
      for (int i = 0; i < _size; ++i)
        elem[i] = m.elem[i];
    }
    return *this;
  }

  Matrix(Matrix&& m)
      : rows{std::move(m.rows)},
        cols{std::move(m.cols)},
        _size{std::move(m._size)},
        elem{std::move(m.elem)} {
    std::cout << "move ctor\n";
    m.moved = true;
    m.rows = m.cols = m._size = 0;
  }

  Matrix& operator=(Matrix&& m) {
    std::cout << "move ass\n";
    if (m.moved)
      AP_error("better not to copy from an already moved matrix\n");
    rows = std::move(m.rows);
    cols = std::move(m.cols);
    _size = std::move(m._size);
    elem = std::move(m.elem);
    m.moved = true;
    m.rows = m.cols = m._size = 0;
    m.elem.reset();
    return *this;
  }

  int row() const noexcept { return rows; }
  int col() const noexcept { return cols; }
  int size() const noexcept { return _size; }

 private:
  int rows;
  int cols;
  int _size;
  std::unique_ptr<num[]> elem;

  // this boolean is set to true when another Maxtrix calls a move
  // ctor or assignment from this Matrix.
  bool moved = false;
};

template <typename num>
std::ostream& operator<<(std::ostream& os, const Matrix<num>& m) {
  for (auto i = 0; i < m.row(); ++i) {
    for (auto j = 0; j < m.col(); ++j)
      os << m(i, j) << " ";
    os << std::endl;
  }
  return os;
}

template <typename num>
Matrix<num> operator+(const Matrix<num>& l, const Matrix<num>& r) {
  // check dimensions
  Matrix<num> res{l.row(), l.col()};
  for (int i = 0; i < res.size(); ++i)
    res[i] = l[i] + r[i];
  return res;
}

template <typename num>
Matrix<num> operator+(Matrix<num>&& l, const Matrix<num>& r) {
  // check dimensions
  return std::forward<Matrix<num>>(l += r);
}

int main() {
  try {
    constexpr std::size_t N = 20000;
    Matrix<double> m0(N, 10000);
    Matrix<double> m1(N, 10000);
    Matrix<double> m2(N, 10000);
    Matrix<double> m3(N, 10000);
    Matrix<double> m4(N, 10000);
    Matrix<double> m5(N, 10000);
    Matrix<double> m6(N, 10000);
    Matrix<double> m7(N, 10000);
    Matrix<double> m8(N, 10000);
    Matrix<double> m9(N, 10000);

    // const auto mm = m1 + m1 + m1 + m1 + m1 + m1 + m1 + m1 + m1;
    auto t1 = std::chrono::high_resolution_clock::now();
    Matrix<double> rh{m0 + m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9};
    // Matrix<double> rh {m0 + m0 + m0 + m0 + m0 + m0 + m0 + m0 + m0 + m0};

    auto t2 = std::chrono::high_resolution_clock::now();

    auto t_f = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << t_f.count() << " milliseconds\n";

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
