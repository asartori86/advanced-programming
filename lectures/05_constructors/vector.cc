#include <iostream>
#include <memory>


template <typename num>
class Vector{
  using size_t = std::size_t;
  size_t _size;
  std::unique_ptr<num[]> elem;
public:

  // custom ctor
  explicit Vector(const size_t length): _size{length}, elem{new num[length]{}}{}

  // default ctor
  Vector():_size{},elem{}{}

  // copy semantics
  
  // copy ctor -- deep copy
  Vector(const Vector& v);
  // copy assignment -- deep copy
  Vector& operator=(const Vector& v);


  // move semantics
  // move ctor
  Vector(Vector&& v):_size{v._size}, elem{v.elem}{}
  Vector& operator=(Vector&& v){_size=std::move(v._size); elem=v.elem;}

  const num& operator[](const size_t& i) const noexcept {return elem[i];}
  num& operator[](const size_t& i) noexcept {return elem[i];}

  size_t size() const noexcept {return _size;}

  // range-for
  const num* begin() const noexcept {return &elem[0];}
  num* begin() noexcept {return &elem[0];}

  const num* end() const noexcept {return &elem[0] + _size;}
  num* end() noexcept {return &elem[0] + _size;}
};

template <typename num>
Vector<num>::Vector(const Vector& v): _size{v._size}, elem{new num[_size]}{
  for (std::size_t i=0; i<_size; ++i)
    elem[i] = v[i];
}

template <typename num>
Vector<num>& Vector<num>::operator=(const Vector& v){
  _size=v._size;
  elem.reset(new num[_size]);
  for (std::size_t i=0; i<_size; ++i)
    elem[i] = v[i];
  return *this;
}


int main()
{
  Vector<double> v1{5};
  for (const auto& x : v1)
    std::cout << x << std::endl;

  return 0;
}
