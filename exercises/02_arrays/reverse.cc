#include <iostream>
#include <string>

int main()
{
  unsigned int length;

  std::cout << "Write the array length: ";
  //cycle until an integer is given in input
  while( !(std::cin >> length) ) {
	std::cout << "Please write a positive integer: ";
	std::cin.clear();
	std::cin.ignore(1000, '\n'); }

  array_init(pp, length);

  int* pp = new int[length];

/*
  int* pp = new int[length];
  *pp = 9;
  pp[0] = 8;
  pp[1] = 7;
  std::cout << pp << std::endl << *(pp+1) << std::endl << &pp;


  delete[] pp;
*/

return 0;
}

template <typename datatype>
void array_init(datatype* vec, const int n)
{
  int* vec = new datatype[n]{0};

  return vec;
}

