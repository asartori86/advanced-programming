#include <iostream>
#include <memory>
#include <algorithm>
#include <iterator>  // need to derive from std::iterator
#include <algorithm>
#include <numeric>
#include <vector>

enum class IM { push_back, push_front };

template <typename T>
class List {
  struct Node {
    T val;
    std::unique_ptr<Node> next;
    Node(const T& v, Node* n = nullptr) : val{v}, next{n} {}
  };

  std::unique_ptr<Node> head;

  void push_back(const T& v);
  void push_front(const T& v);

 public:
  List() : head{nullptr} {}
  void insert(const T& v, const IM method = IM::push_front);
  void print() const;

  void call_custom_function() {
    Node* tmp{head.get()};
    while (tmp != nullptr) {
      custom_function(tmp->val);
      tmp = tmp->next.get();
    }
  }
  std::function<void(T&)> custom_function;

  class Iterator;
  Iterator begin() { return Iterator{head.get()}; }
  Iterator end() { return Iterator{nullptr}; }

  class ConstIterator;
  ConstIterator begin() const { return ConstIterator{head.get()}; }
  ConstIterator end() const { return ConstIterator{nullptr}; }

  ConstIterator cbegin() const { return ConstIterator{head.get()}; }
  ConstIterator cend() const { return ConstIterator{nullptr}; }

  using iterator = Iterator; // needed for boost.python
  							 // needs change in the code...
};

template <typename T>
class List<T>::Iterator : public std::iterator<std::forward_iterator_tag, T> {
  using Node = List<T>::Node;
  Node* current;

 public:
  Iterator(Node* n) : current{n} {}
  T& operator*() const { return current->val; }

  // ++it
  Iterator& operator++() {
    current = current->next.get();
    return *this;
  }

  // it++
  Iterator operator++(int) {
    Iterator it{current};
    ++(*this);
    return it;
  }

  bool operator==(const Iterator& other) {
    return this->current == other.current;
  }

  bool operator!=(const Iterator& other) { return !(*this == other); }
};

template <typename T>
class List<T>::ConstIterator : public List<T>::Iterator {
  using parent = List<T>::Iterator;

 public:
  using parent::Iterator;
  const T& operator*() const { return parent::operator*(); }
};

template <typename T>
void List<T>::insert(const T& v, const IM method) {
  if (head.get() == nullptr)
    // head.reset(new Node{v,nullptr});
    head.reset(new Node{v});
  else {
    switch (method) {
      case IM::push_back:
        push_back(v);
        break;

      case IM::push_front:
        push_front(v);
        break;

      default:
        std::cerr << "error\n";
        break;
    }
  }
}

template <typename T>
void List<T>::push_front(const T& v) {
  head.reset(new Node{v, head.release()});
}

template <typename T>
void List<T>::push_back(const T& v) {
  Node* tmp{head.get()};
  while (tmp->next.get() != nullptr)
    tmp = tmp->next.get();
  tmp->next.reset(new Node{v});
}

template <typename T>
void List<T>::print() const {
  // Node* tmp { head.get() };
  // while (tmp != nullptr){
  //   std::cout << tmp->val << std::endl;
  //   tmp = tmp->next.get();
  // }

  // for (const auto& x: *this)
  //   std::cout << x << std::endl;

  auto it = this->begin();
  auto it_end = this->end();
  for (; it != it_end; ++it)
    std::cout << *it << std::endl;
}

template <typename num>
struct my_comparison {
  bool operator()(const num& a, const num& b) { return a < b; }
};



#include <boost/python.hpp>
using namespace boost::python;


template <typename T>
struct _List: public List<T> {
	using iterator = typename List<T>::Iterator; 
	using List<T>::List;
	void _insert(const T& v, const IM method = IM::push_front){
		this->insert(v,method);
	}
	using List<T>::print;
}; 


BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(insert_overloads, _insert, 1, 2); 

BOOST_PYTHON_MODULE(_EXTRA_2_interface_as_linked_list_compliant) {
	class_<_List <int>, boost::noncopyable >("List")
	.def("__iter__" , iterator<_List<int>>())
	.def("insert"   , &_List<int>::_insert,insert_overloads())
	.def("print"    , &_List<int>::print)
	;

	class_<_List <float>, boost::noncopyable >("List")
	.def("__iter__" , iterator<_List<float>>())
	.def("insert"   , &_List<float>::_insert,insert_overloads())
	.def("print"    , &_List<float>::print)
	;

}

/*

int main() {
  List<double> list{};
  list.insert(1.1);
  list.insert(2.2, IM::push_back);
  list.insert(3.3);
  list.print();

  auto first = list.cbegin();
  auto last = list.cend();

  double sum{0.0};

  sum = std::accumulate(first, last, sum);

  auto my_f = [](const decltype(*first)& a,
                 const decltype(*first)& b) -> decltype(a + b) {
    double res = 0;
    (b == 2.2 ? res = a : res = a + b);
    return res;
  };

  sum = std::accumulate(first, last, 0.0, my_f);

  std::cout << "sum is " << sum << std::endl;

  auto it = std::find(first, last, 2.2);

  if (it != last) {
    std::cout << "found " << *it << std::endl;
  } else
    std::cout << "not found\n";

  std::vector<double> v(3);

  std::copy(first, last, v.begin());
  std::sort(v.begin(), v.end(), my_comparison<double>{});
  for (const auto& x : v)
    std::cout << x << std::endl;

  return 0;
}
*/
