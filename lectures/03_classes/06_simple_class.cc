#include <iostream>
#include <string>

class Vector {
  double* elem;
  unsigned int _size;

 public:
  Vector(const unsigned int size) : _size{size}, elem{new double[size]} {}

  ~Vector() { delete[] elem; }

  unsigned int size() const { return _size; }

  double& operator[](const unsigned int i) { return elem[i]; }

  const double& operator[](const unsigned int i) const { return elem[i]; }

  void pretty_print() const;
};

int main() {
  Vector v{10};

  for (auto i = 0; i < v.size(); ++i)
    v[i] = i;

  v.pretty_print();

  Vector* pv = &v;

  pv->pretty_print();

  return 0;
}

void Vector::pretty_print() const {
  std::cout << "Vector allocated at " << elem << std::endl;
  for (auto i = 0; i < _size; ++i)
    std::cout << "elem[" << i << "] = " << elem[i] << std::endl;
}
