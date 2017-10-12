#include <iostream>


template <typename OP>
struct MatrixExpr{
  auto operator[] (const unsigned int i) const {return static_cast<OP const &>(*this)[i];}
  operator OP&(){return static_cast<OP&>(*this);}
  operator const OP&() const {return static_cast<const OP&>(*this);}
  size_t size() const {return static_cast<OP const &>(*this).size();}
  auto get_row() const noexcept { return static_cast<const OP&>(*this).get_row(); }
  auto get_col() const noexcept { return static_cast<const OP&>(*this).get_col(); }
};

template <typename num>
class Matrix : MatrixExpr<Matrix<num>>{
 private:
  const size_t n;
  const size_t cols;
  num* elem;

 public:
  explicit Matrix(const size_t l) : n{l}, cols{l}, elem{new num[l*l]{}} { std::cout << "\n\ndefault-square\n\n";}

  Matrix(const size_t& row_size, const size_t& col_size)
    : n{row_size}, cols{col_size}, elem{new num[n*cols]{}} { std::cout << "\n\ndefault\n\n";}

  // Matrix(const Matrix&) = delete;
  Matrix(const Matrix& m): n{m.n}, cols{m.cols}, elem{new num[n*cols]{}} { std::cout << "\n\nCOPY\n\n";
    for (auto i  =0; i<n*cols; ++i)
      elem[i] = m[i];
  }

  Matrix(Matrix&& m)
    : n{std::move(m.n)}, cols{std::move(m.cols)}, elem{std::move(m.elem)} {std::cout << "\n\nMOVE\n\n";
    m.elem = nullptr;
  }

  template <typename OP>
  Matrix(MatrixExpr<OP> const & me): n{me.get_row()}, cols{me.get_col()}, elem{new num[n*cols]}{std::cout << "\n\nEXPR\n\n";
   for (auto i  =0; i<n*cols; ++i)
      elem[i] = me[i]; 
  }
  
  ~Matrix() { delete[] elem; }

  num& operator()(const unsigned int i, const unsigned int j) noexcept {
    return elem[i * cols + j];
  }

  const num& operator()(const unsigned int i, const unsigned int j) const
      noexcept {
    return elem[i * cols + j];
  }

  const num& operator[](const unsigned int i) const
      noexcept {
    return elem[i];
  }

  size_t size() const {return n*cols;}
  auto begin() noexcept { return elem; }

  auto end() noexcept { return elem + n * cols; }

  const auto begin() const noexcept { return elem; }

  const auto end() const noexcept { return elem + n * cols; }

  auto get_row() const noexcept { return n; }

  auto get_col() const noexcept { return cols; }
};

template <typename num>
std::ostream& operator<<(std::ostream& os, const Matrix<num>& m) {
  for (auto i = 0; i < m.get_row(); ++i) {
    for (auto j = 0; j < m.get_col(); ++j)
      os << m(i, j) << " ";
    os << '\n';
  }
  return os;
}

template <typename LHS, typename RHS>
class MatrixSum: public MatrixExpr<MatrixSum<LHS,RHS>>{
  LHS const & _lhs;
  RHS const & _rhs;
public:
  MatrixSum(LHS const & l, RHS const & r): _lhs{l}, _rhs{r}{}

  auto operator[](const unsigned int i) const {return _lhs[i]+_rhs[i];}
  auto get_row() const noexcept { return _lhs.get_row(); }
  auto get_col() const noexcept { return _rhs.get_col(); }
};


template <typename L,typename R>
MatrixSum<L,R> const operator+(L const & l, R const & r)
{
  return MatrixSum<L,R>{l,r};
}

// template <typename num>
// Matrix<num> operator+(const Matrix<num> &lhs, const Matrix<num>&rhs)
// {
//   Matrix<num> res{lhs};
//   const std::size_t rows = lhs.get_row();
//   const std::size_t cols = lhs.get_col();
//   if(rows != rhs.get_row() || cols != rhs.get_col())
//     {
//       std::cerr << "Bad\n";
//       return res;
//     }
//   for(auto i=0;i<rows;++i)
//     for(auto j=0; j<cols; ++j)
//       res(i,j)+=rhs(i,j);
//   return std::move(res);
// }

template <typename num>
void dwim(const Matrix<num>& m) {
  std::cout << "dwim\n";
  std::cout << m << std::endl;
}

int main() {
  auto c = 0.1;
  Matrix<double> m1(2000, 9000);
  for (auto& x : m1) {
    x = c++;
  }

  Matrix<double> rhs {m1+m1+m1+m1+m1+m1+m1+m1+m1} ;

  std::cout << "done\n";
  // std::cout << "\n" << m1 << "------\n";
  // std::cout << "\n" << rhs << "------\n";
  // dwim<int>(5); 		// wtf???

  {
    Matrix<double> m2{Matrix<double>{2, 2}};
    std::cout << m2;
  }
  {
    Matrix<double> m2{std::move(m1)};
    m2(0, 0) = 9;
    // std::cout << m2;
  }

  return 0;
}
