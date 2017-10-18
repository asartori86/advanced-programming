#include <iostream>

class Trial {
 public:
  struct My_test : public std::exception {};
  void test() noexcept { throw My_test{}; }

 private:
  int a = 0;
};

int main(int argc, char* argv[]) {
  try {
    // std::terminate();
    // throw;
    Trial t;
    t.test();
    return 0;
  } catch (std::exception& e) {
    std::cout << e.what() << __LINE__ << " ciao\n";
  }
}
