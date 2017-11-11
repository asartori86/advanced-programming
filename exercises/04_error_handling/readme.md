# Exercises - session 04

## Getters

Change the behavior of the getters function implemented in session 01
such that they throw an exception if an invalid argument is
passed. Remember to properly catch the exception.

## Date

Improve the class Date that you developed in the previous exercise
session such that it throws an exception whenever an invalid date is
provided.

## Vector

Define the class Vector declared in file `simple_vector.cc`


## Linked list
Implement a linked list with the following design

```
enum class Insertion_method { push_back, push_front };

template <typename value_type>
class List {
 public:
  // insert a new node with the value v according to the method m
  // this method should be used to fill the list
  void insert(const value_type& v, const Insertion_method m);

  // print the values of the nodes
  void print();

  // return the size of the list
  unsigned int size();

  // delete all the nodes of the list
  void reset();

  // prune node storing the value v
  void prune_node(const value_type& v);

  // implement suitable constructor(s) for List


 private:
 
  // private struct node with the proper value_type
  struct node {
    value_type val;
    std::unique_ptr<node> next;

    // implement suitable constructor(s) for node
  };

  // append the newly created node at the end of the list
  void push_back(const value_type& v);

  // insert the newly created node in front of the list
  void push_front(const value_type& v);

  std::unique_ptr<node> head;
  unsigned int size;
};

```
