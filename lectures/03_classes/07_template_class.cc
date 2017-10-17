#include <iostream>
#include <string>

template <typename num>
class Vector {
  num* elem;
  unsigned int _size;

 public:
  Vector(const unsigned int size) : _size{size}, elem{new num[size]} {}

  ~Vector() { delete[] elem; }

  unsigned int size() const { return _size; }

  num& operator[](const unsigned int i) { return elem[i]; }

  const num& operator[](const unsigned int i) const { return elem[i]; }

  void pretty_print() const;
};

int main() {
  Vector<double> v{10};

  for (auto i = 0; i < v.size(); ++i)
    v[i] = i;

  v.pretty_print();

  Vector<double>* pv = &v;

  pv->pretty_print();

  return 0;
}

template <typename num>
void Vector<num>::pretty_print() const {
  std::cout << "Vector allocated at " << elem << std::endl;
  for (auto i = 0; i < _size; ++i)
    std::cout << "elem[" << i << "] = " << elem[i] << std::endl;
}
