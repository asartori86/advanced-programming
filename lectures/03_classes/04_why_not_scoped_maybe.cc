#include <iostream>

enum multiple_flags : unsigned int {
  flag1 = 1,
  flag2 = 2,
  flag3 = 4,
  // flag4 = 8 | flag1 | flag2, // imply flag1 and flag2 easy to implement, but
  // difficult to compare..
  flag4 = 8,   // additional functions needed
  flag5 = 16,  // imply flag3

  // useful combinations
  comb1 = flag1 | flag2,
  comb2 = flag1 | flag3,
  comb3 = comb1 | flag3,
};

void do_complicated_stuff(multiple_flags flags);

multiple_flags operator|(const multiple_flags f1, const multiple_flags f2) {
  return static_cast<multiple_flags>(static_cast<unsigned int>(f1) |
                                     static_cast<unsigned int>(f2));
}

int main() {
  std::cout << "testing flag1 and flag3\n"
            << "expected  flag1 and flag3 \n\n";
  do_complicated_stuff(flag1 | flag3 | flag1 | flag1);

  std::cout << "--------------\n\n"
            << "testing comb3\n"
            << "expected  flag1, flag2 and flag3 \n\n";
  do_complicated_stuff(comb3);

  std::cout << "--------------\n\n"
            << "testing flag4\n"
            << "expected  flag1, flag2 and flag4 \n\n";
  do_complicated_stuff(flag4);

  std::cout << "--------------\n\n"
            << "testing flag5\n"
            << "expected flag3 and flag5 \n\n";
  do_complicated_stuff(flag5);

  return 0;
}

multiple_flags& operator|=(multiple_flags& f1, const multiple_flags f2) {
  f1 = f1 | f2;
  return f1;
}

void compute_multiple_flags(multiple_flags& f) {
  if (f & flag4)
    f |= (flag1 | flag2);
  if (f & flag5)
    f |= flag3;
}

void do_complicated_stuff(multiple_flags flags) {
  // update flags correctly
  compute_multiple_flags(flags);

  if (flags & flag1)
    std::cout << "flag 1 selected\n";
  if (flags & flag2)
    std::cout << "flag 2 selected\n";
  if (flags & flag3)
    std::cout << "flag 3 selected\n";
  if (flags & flag4)
    std::cout << "flag 4 selected\n";
  if (flags & flag5)
    std::cout << "flag 5 selected\n";
}
