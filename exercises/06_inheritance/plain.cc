#include <iostream>
#include <memory>  //smart pointers
#include <ap_error.h>
#include <chrono>

template <typename ET>
struct MatrixExpression {
  auto operator[](const int i) const noexcept {
    return static_cast<const ET&>(*this)[i];
  }
  auto row() const noexcept { return static_cast<const ET&>(*this).row(); }
  auto col() const noexcept { return static_cast<const ET&>(*this).col(); }
};

template <typename num>
class Matrix {
 public:
  template <typename ET>
  Matrix(const MatrixExpression<ET>& e)
      : rows{e.row()}, cols{e.col()}, _size{rows * cols}, elem{new num[_size]} {
    // std::cout << "expr ctor\n";
    for (int i = 0; i < _size; ++i)
      elem[i] = e[i];
  }

  template <typename ET>
  Matrix& operator=(const MatrixExpression<ET>& e) {
    std::cout << "expr assignment\n";
    // check sizes
    for (int i = 0; i < _size; ++i)
      elem[i] = e[i];
    return *this;
  }

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

template <typename LT, typename RT>
class MatrixSum : public MatrixExpression<MatrixSum<LT, RT>> {
  const LT& lhs;
  const RT& rhs;

 public:
  MatrixSum(const LT& l, const RT& r) : lhs{l}, rhs{r} {}

  auto operator[](const int i) const { return lhs[i] + rhs[i]; }
  auto row() const noexcept { return lhs.row(); }
  auto col() const noexcept { return lhs.col(); }
};

template <typename LT, typename RT>
const MatrixSum<LT, RT> operator+(const LT& l, const RT& r) {
  return MatrixSum<LT, RT>{l, r};
}
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
Matrix<num> sumten(const Matrix<num>& m0,
                   const Matrix<num>& m1,
                   const Matrix<num>& m2,
                   const Matrix<num>& m3,
                   const Matrix<num>& m4,
                   const Matrix<num>& m5,
                   const Matrix<num>& m6,
                   const Matrix<num>& m7,
                   const Matrix<num>& m8,
                   const Matrix<num>& m9) {
  const int size = m0.size();
  Matrix<num> res{m0.row(), m0.col()};
  for (int i = 0; i < size; ++i)
    res[i] = m0[i] + m1[i] + m2[i] + m3[i] + m4[i] + m5[i] + m6[i] + m7[i] +
             m8[i] + m9[i];
  return res;
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
    // Matrix<double> rh(N, 10000);

    // const auto mm = m1 + m1 + m1 + m1 + m1 + m1 + m1 + m1 + m1;
    auto t1 = std::chrono::high_resolution_clock::now();
    // rh = m0 + m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9;
    // Matrix<double> rh {m0 + m0 + m0 + m0 + m0 + m0 + m0 + m0 + m0 + m0};
    Matrix<double> rh{sumten(m0, m1, m2, m3, m4, m5, m6, m7, m8, m9)};
    auto t2 = std::chrono::high_resolution_clock::now();

    auto t_f = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << t_f.count() << " milliseconds\n";

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
