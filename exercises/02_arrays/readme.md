# Exercises - session 02

## Reverse order

- Write a program that reads from stdin the length of an array and
  then store in it the numbers given from stdin. The program should
  then prints the number in **reverse order**. Remember to properly
  free the used memory. You should divide the problem in two parts:

  1. Write one **template** function that allocate on the *heap* one
  array of a given size, initialize its elements and returns the
  pointer to the first element.

  2. Write a **template** function that prints the elements of an
  array in the reverse order.

  3. Test with intgers and doubles.
  
*Hints*: remember that you should check you code with valgrind. If you
 have a MAC you might have bad surprises. Run valgrind on a **Linux**
 system.

## Prime numbers

- Populate an array named `primes` containing the first prime numbers
  up to 100. Consider 2 as the first prime (i.e. `primes[0] == 2`).
  
  - you are free to choose the design and the implementation.

  - please comment and motivate your choices (e.g., allocate a one big
    array, every time I find a new prime number I increase the size of
    the previous `primes` array, etc.)
    

## Sieve of Eratosthenes

- Implement the Sieve of Eratosthenes algorithm. Write a code that
  prints on screen the first prime numbers up to N (included), where N
  is passed from command line argument. The first prime number that
  should be printed is `2`

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

*Hints*:
- https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes :)

- the square root of a number can be found in `<math.h>`
```
#include <math.h>
...
std::cout << std::sqrt(4) <<std::endl;
```