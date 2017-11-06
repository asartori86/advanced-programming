#include <iostream>
#include <memory>
#include <ap_error.h>

template <typename num>
class Vector {
  unsigned int _size;
  std::unique_ptr<num[]> elems;

 public:
  explicit Vector(const unsigned int s) : _size{s}, elems{new num[s]{}} {
    std::cout << "Vector ctor\n";
  }

  // Vector(std::initializer_list<num> lst);
  unsigned int size() const noexcept { return _size; }

  num& operator[](const unsigned int i) noexcept { return elems[i]; }
  const num& operator[](const unsigned int i) const noexcept {
    return elems[i];
  }

  num& at(const unsigned int i);
  const num& at(const unsigned int i) const;

  num* begin() noexcept { return elems.get(); }
  num* end() noexcept { return elems.get() + _size; }

  const num* begin() const noexcept { return elems.get(); }
  const num* end() const noexcept { return elems.get() + _size; }

  void resize(const Vector& v);
  void resize(const unsigned int s);
};

template <typename num>
num& Vector<num>::at(const unsigned int i) {
  if (i >= _size)
    AP_error("Out of bound:", i, "is not smaller than", _size);
  return elems[i];
}

template <typename num>
const num& Vector<num>::at(const unsigned int i) const {
  if (i < _size)
    return elems[i];
  AP_error("Out of bound:", i, "is not smaller than", _size);
}

template <typename num>
void Vector<num>::resize(const unsigned int s) {
  _size = s;
  elems.reset(new num[s]{});  // equivalent to the following lines
  // num* ptr = elems.release();
  // delete[] ptr;
  // elems = std::unique_ptr<num[]>(new num[s]);
}

template <typename num>
void Vector<num>::resize(const Vector<num>& v) {
  resize(v.size());
}

template <class num>
std::ostream& operator<<(std::ostream& os, const Vector<num>& v) {
  for (const auto x : v)
    os << x << " ";
  os << std::endl;
  return os;
}

template <typename num>
void print_vector(const char* s, const Vector<num>& v) {
  std::cout << "-----------------------------------\n"
            << s << "\n"
            << " size : " << v.size() << "\n"
            << "elems : " << v << "-----------------------------------\n";
}

int main() {
  try {
    Vector<int> v1{6};  // the same as Vector<int> v1(6);
    print_vector("v1", v1);

    {
      int c = 0;
      for (auto& x : v1)
        x = c++;
    }

    print_vector("v1", v1);
    std::cout << v1.at(0) << " " << v1[11] << std::endl;

    print_vector<int>("vtest", Vector<int>(7));
  }

  catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
