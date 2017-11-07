#include <iostream>

template <typename num>
class Vector {
  std::size_t _size;
  num* elem;

 public:
  explicit Vector(const std::size_t length)
      : _size{length}, elem{new num[length]{}} {}

  ~Vector() { delete[] elem; }

  const num& operator[](const std::size_t& i) const noexcept { return elem[i]; }
  num& operator[](const std::size_t& i) noexcept { return elem[i]; }

  std::size_t size() const noexcept { return _size; }

  // range-for
  const num* begin() const noexcept { return elem; }
  num* begin() noexcept { return elem; }

  const num* end() const noexcept { return elem + _size; }
  num* end() noexcept { return elem + _size; }
};

int main() {
  Vector<double> v1{7};
  Vector<double> v2{v1};  // default copy constructor
  return 0;
}
