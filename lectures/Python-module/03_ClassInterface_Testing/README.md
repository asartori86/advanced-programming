## P1.3 - Python module

## Curators
- Jacopo Rigosa (<jrigosa@sissa.it>)
- Alberto Sartori (<asartori@sissa.it>)

## Contents

#### Lecture 1
- jupyter notebook and its magics
- identifiers, keywords, operators
- literals, compund data structures (i.e., tuple, list, set, dict)
- control flow tools (i.e., conditional, loops, reminder, context, exceptions)
  - special looping functions (i.e., reversed,zip,enumerate,sorted)
- definition of a function
  - keyword arguments
  - positional arguments  
  - lambda expressions
  - function annotations

- exercises/lecture_1_exercises.py:
  - is_palindrome(string)
  - histogram_letters(string)
  - get_most_frequent(list)
  - which_duplicates(list)
  - compute_factorial(a)
  - is_prime(a)
  - is_divisor(a,b)

#### Lecture 2:
- standard library overview: "batteries are included"
  - simple string processing
  - simple path navigation
  - parsing inputs from command line to a script
- modules and packages
  - structure of a module
  - run module as a script
  - importing a module
    - \__all\__
    - intra-package refs
    - PYTHONPATH
- functional programming paradigm
  - filter, map, reduce
- comprehensions
  - list, nested, set, dictionaries comprehensions
  - generator comprehension
- generators
  - next, yield keywords
- scopes and namespaces
- classes
  - definition, special attributes
  - class/instance's methods/variables
  - operator overloads (and other special attributes)
  - inheritance, multiple inheritance and method resolution order
  - super() built-in function

- excercises/lecture_2_exercises.py:
  - define classes Point(),Shape(),Circle(),Segment(),Triangle()

#### Lecture 3:
- decorators
- name conventions 
- data encapsulation
  - getter,setter,deleter
  - property and property decorations
- polymorhphism 
  - subtyping
  - duck typing 
  - abstract base classes
- context manager and contextlib
- iterable, sequence, iterator
- unittest TestCase

## References and Text Books:

- https://docs.python.org/3/tutorial/  introduces many Python’s features by example
- https://docs.python.org/3/library/ standard library that is distributed with python
- https://docs.python.org/3/extending/ how to write Python modules in C or C++
- https://docs.python.org/3/reference/ for syntax and “core semantics”

## Attribution

Part of the material was taken from this collection of  [![jupiter-logo](https://jupyter.org/assets/main-logo.svg) notebooks](https://github.com/jupyter/jupyter/wiki/A-gallery-of-interesting-Jupyter-Notebooks)
