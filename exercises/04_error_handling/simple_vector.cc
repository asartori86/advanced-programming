#include <iostream>
#include <memory>

template <typename num>
class Vector{
  std::unique_ptr<num[]> elems;
  unsigned int _size;
public:
  explicit Vector(const unsigned int s);

  unsigned int size() const noexcept;

  num& operator[](const unsigned int i) noexcept;
  const num& operator[](const unsigned int i) const noexcept;

  num& at(const unsigned int i);
  const num& at(const unsigned int i) const;

  num* begin() noexcept;
  num* end() noexcept;
  
  const num* begin() const noexcept;
  const num* end() const noexcept;

  void resize(const Vector& v);
  void resize(const unsigned int s);
};


template <class num>
std::ostream& operator<<(std::ostream& os, const Vector<num>& v)
{
  for (const auto x : v)
    os << x << " ";
  os << std::endl;
  return os;
}

template <typename num>
void print_vector(const char* s,const Vector<num>& v)
{
  std::cout <<"-----------------------------------\n"
	    << s << "\n"
	    << "size  : "<< v.size() << "\n"
	    << "elems : " << v
	    <<"-----------------------------------\n";
}


int main()
{}
