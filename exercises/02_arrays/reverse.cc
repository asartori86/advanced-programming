#include <iostream>
#include <string>

int main()
{
  unsigned int length;
  int* pp;
//  void array_init;

  /* take array length */
  std::cout << "Write the array length: ";
  //cycle until an integer is given in input
  while( !(std::cin >> length) ) {
	std::cout << "Please write a positive integer: ";
	std::cin.clear();
	std::cin.ignore(1000, '\n'); }

  /* initialize the array */
  pp = array_init<double>(length);

//  int* pp = new int[length];

  /* read and store data */

  /* print in reverse order */


/*
  int* pp = new int[length];
  *pp = 9;
  pp[0] = 8;
  pp[1] = 7;
  std::cout << pp << std::endl << *(pp+1) << std::endl << &pp;
*/

  delete[] pp;


return 0;
}

template <typename datatype>
void array_init<datatype>(int n)
{
  int* vec = new datatype[n]{0};

  return vec;
}
