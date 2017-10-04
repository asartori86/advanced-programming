# Exercises - session 01

## Understanding compiler messages
- Take a simple program (e.g., the hello world one) and put one at a time the following errors. Compile it and try to understand the error messages. If you have both `g++` and `clang++` compare the messages from the two compilers.
  - typos in function name (e.g., c0ut)
  - typos in variable name
  - forget to put `;`
  - forget to `#include <iostream>`
  - declare a variable with illegal name like 'int double = 0;'
  - pass wrong type of argument to a fuction
  

## uniq
- Write a simple version of the Unix program `uniq`, which, when fed with a text, outputs the same text with adjacent identical lines collapsed to one.
- Modify the above program to reproduce the behavior of `uniq -c`

*Hint*: you can scan the stdin as follows
```
std::string line;
while(std::getline(std::cin,line))
{...}
```

## Getters
- write a function `get_int` that reads from stdin until a valid number is fed
- write a function `get_double` that reads from stdin until a valid number is fed
*Hints*: to clear the error flag from `std::cin` by calling
```
std::cin.clear();
```
and you can ignore what just read
```
std::cin.ignore();
```

## Units of measure

- Write a code that reads a number with its proper unit of measure, and prints back that number according to the SI units, e.g.

```
1 inch
0.0254 m
```

## Text formatter
- Write a simple text formatter that breaks the lines longer than a given number of characters. This formatter does not break words.

*Hint* to know the size of a string you can call the member function `length`
```
std::string word;
std::cin >> word;
std::cout << word.length();
```