#include <iostream>
#include <memory>
#include "../04_error_handling/ap_error.h"

template <typename num>
class Vector {
  std::size_t _size;
  std::unique_ptr<num[]> elem;

 public:
  // custom ctor
  explicit Vector(const std::size_t length)
      : _size{length}, elem{new num[length]{}} {
    std::cout << "custom ctor\n";
  }

  // Vector(const std::initializer_list<num> args)
  //     : _size{args.size()}, elem{new num[_size]} {
  //   std::cout << "list ctor\n";
  //   std::uninitialized_copy(args.begin(), args.end(), begin());
  // }

  // default ctor
  Vector() { std::cout << "default ctor\n"; }
  // Vector() = default;
  // Vector() : _size{}, elem{} { std::cout << "default ctor\n"; }

  // copy semantics
  // copy ctor -- deep copy
  Vector(const Vector& v);
  // copy assignment -- deep copy
  Vector& operator=(const Vector& v);

  // move semantics
  // move ctor
  Vector(Vector&& v) noexcept
      : _size{std::move(v._size)}, elem{std::move(v.elem)} {
    std::cout << "move ctor\n";
  }

  Vector& operator=(Vector&& v) noexcept {
    std::cout << "move assignment\n";
    _size = std::move(v._size);
    elem = std::move(v.elem);
    return *this;
  }

  const num& operator[](const std::size_t& i) const noexcept { return elem[i]; }
  num& operator[](const std::size_t& i) noexcept { return elem[i]; }

  std::size_t size() const noexcept { return _size; }

  // range-for
  const num* begin() const noexcept { return &elem[0]; }
  num* begin() noexcept { return &elem[0]; }

  const num* end() const noexcept { return &elem[0] + _size; }
  num* end() noexcept { return &elem[0] + _size; }

  Vector<num>& operator+=(const Vector<num>& rhs);
};

// copy ctor
template <typename num>
Vector<num>::Vector(const Vector& v) : _size{v._size}, elem{new num[_size]} {
  std::cout << "copy ctor\n";
  for (std::size_t i = 0; i < _size; ++i)
    elem[i] = v[i];
  // std::uninitialized_copy(v.begin(),v.end(),this->begin()); //use placement
  // new
}

// copy assignment
template <typename num>
Vector<num>& Vector<num>::operator=(const Vector& v) {
  std::cout << "copy assignment\n";

  // we could decide that this operation is allowed if and only if
  // _size == v._size
  //
  // AP_assert(_size == v._size, "Vector lenght mismatch");
  // probably the just mentioned approach is safier..

  _size = v._size;
  elem.reset(new num[_size]);

  // for (std::size_t i = 0; i < _size; ++i)
  //   elem[i] = v[i];

  std::copy(v.begin(), v.end(), this->begin());
  return *this;

  // is this approach consistent with self-assignment vx=vx?
}

template <typename num>
Vector<num>& Vector<num>::operator+=(const Vector<num>& rhs) {
  AP_assert(_size == rhs._size, "Vector lenght mismatch:", _size, "!=",
            rhs._size, "\nlhs:", *this, "\nrhs:", rhs);

  for (std::size_t i = 0; i < _size; ++i)
    elem[i] += rhs[i];
  return *this;
}

template <typename num>
Vector<num> operator+(const Vector<num>& lhs, const Vector<num>& rhs) {
  const auto size = lhs.size();

  AP_assert(size == rhs.size(), "Vector lenght mismatch:", size, "!=",
            rhs.size(), "\nlhs:", lhs, "\nrhs:", rhs);
  std::cout << "const\n";
  Vector<num> res(size);
  for (std::size_t i = 0; i < size; ++i)
    res[i] = lhs[i] + rhs[i];
  return res;
}

template <typename num>
Vector<num> operator+(Vector<num>&& lhs, const Vector<num>& rhs) {
  const auto size = lhs.size();
  std::cout << "&&\n";

  AP_assert(size == rhs.size(), "Vector lenght mismatch:", size, "!=",
            rhs.size(), "\nlhs:", lhs, "\nrhs:", rhs);

  return std::move(lhs += rhs);
}

template <typename num>
std::ostream& operator<<(std::ostream& os, const Vector<num>& v) {
  if (v.size() < 30) {
    for (const auto& x : v)
      os << x << " ";
    os << std::endl;
  }
  return os;
}

int main() {
  try {
    std::cout << "Vector<int> v0; calls\n";
    Vector<int> v0;
    std::cout << v0.size() << "\n";
    std::cout << "Vector<int> v00{}; calls\n";
    Vector<int> v00{};
    std::cout << v00.size() << "\n";

    std::cout << "\nVector<double> v1{5}; calls\n";
    Vector<double> v1{5};

    std::cout << "\nVector<double> v2 = v1; calls\n";
    Vector<double> v2 = v1;
    std::cout << "\nv2 = Vector<double>{7}; calls\n";
    v2 = Vector<double>{7};
    std::cout << "\nVector<double> v3{std::move(v1)}; calls\n";
    Vector<double> v3{std::move(v1)};  // now v1 should not be used
    std::cout << "\nv3 = v2; calls\n";
    v3 = v2;
    std::cout << "\nv2 = " << v2;
    std::cout << "v3 = " << v3;

    std::cout << "\nassign some values to v3\n";
    {
      // auto i = v3.size();
      // while (i--)
      //   v3[i] = i;

      int c = 0;
      for (auto& x : v3)
        x = c++;
    }
    // v3=v3;
    std::cout << "\nv2 = " << v2;
    std::cout << "v3 = " << v3;

    std::cout << "\nVector<double> v4{v3 + v3}; calls\n";
    Vector<double> v4{v3 + v3};

    std::cout << "v4 = " << v4;

    std::cout << "\nNRVO: Named Return Value Optimization\n";

    std::cout << "\nv4 = v3 + v3 + v2 + v3; calls\n";
    v4 = v3 + v3 + v2 + v3;
    std::cout << v4;

    std::cout << "\nLet's test our assert in operator+\n";
    std::cout << "Vector<int> a{5};\n"
              << "Vector<int> b{7};\n"
              << "Vector<int> c{a + b}\n";
    Vector<int> a{5};
    Vector<int> b{7};
    Vector<int> c{a + b};
    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
