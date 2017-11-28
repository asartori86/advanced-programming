#include <iostream>
#include <memory>

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
};

template <typename T>
class List<T>::Iterator {
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

  auto it{this->begin()};
  auto it_end{this->end()};
  for (; it != it_end; ++it)
    std::cout << *it << std::endl;
}

int main() {
  List<double> list{};
  list.insert(1.1);
  list.insert(2.2);
  list.insert(3.3);
  list.print();

  double sum{0};

  auto my_sum = [&sum](double& d) { sum += d; };

  list.custom_function = my_sum;

  list.call_custom_function();

  std::cout << " the sum is " << sum << std::endl;

  sum = 0;
  List<double>::Iterator last = list.end();
  for (List<double>::Iterator it = list.begin(); it != last; ++it) {
    sum += *it;
  }

  for (auto& x : list) {
    sum += x++;
  }

  return 0;
}
