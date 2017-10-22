# Exercises - session 04

## Getters

Change the behavior of the getters function implemented in session 01
such that they throw an exception if an invalid argument is
passed. Remember to properly catch the exception.

## Vector

Implement a new member function `at(const unsigned int i)` in the
class Vector presented in lecture 03 (if you will, use the template
version `07_template_class.cc`). This function is used to access the
element at position `i`, just like `operator[]`, but it checks if `i`
is a valid argument (i.e., `0<=i<size`). If `i` is out of bound, throw
an exception.

## Date

Improve the class Date that you developed in the previous exercise
session such that it throws an exception whenever an invalid date is
provide.