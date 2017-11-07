#include <iostream>
#include <memory>

template <typename num>
class Vector {
  std::size_t _size;
  std::unique_ptr<num[]> elem;

 public:
  explicit Vector(const std::size_t length)
      : _size{length}, elem{new num[length]{}} {}

  const num& operator[](const std::size_t& i) const noexcept { return elem[i]; }
  num& operator[](const std::size_t& i) noexcept { return elem[i]; }

  std::size_t size() const noexcept { return _size; }

  // range-for
  const num* begin() const noexcept { return elem.get(); }
  num* begin() noexcept { return elem.get(); }

  const num* end() const noexcept { return elem.get() + _size; }
  num* end() noexcept { return elem.get() + _size; }
};

int main() {
  Vector<double> v1{7};
  // Vector<double> v2{v1}; // default copy ctor
  return 0;
}
