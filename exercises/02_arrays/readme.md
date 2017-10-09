# Exercises - session 02

## Reverse order
- Write a program that reads from stdin the length of an array and then store in it the numbers given from stdin. The program should then prints the number in **reverse order**. Remember to properly free the used memory. You should divide the problem in two parts:
  1. Write one **templated** function that creates the array and returns the pointer to the first element of the newly created, and initialized, array.
  2. Write a **templated** function that prints the elements of an array in the reverse order.
  

## Prime numbers
- Populate an array named `primes` containing the first prime numbers up to 100. Consider 2 as the first prime (i.e. `primes[0] == 2`).

## Sieve of Eratosthenes
- Write a code that prints on screen the first prime numbers up to N (included), where N is passed from command line argument, e.g.
```
$ ./a.out 5
2
3
5

$ ./a.out 10
2
3
5
7
```
Implement the Sieve of Eratosthenes algorithm. The first prime number that should be printed is `2`

*Hints*:
- https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes :)

- the square root of a number can be found in `<math.h>`
```
#include <math.h>
...
std::cout << std::sqrt(4) <<std::endl;
```