# Exercises - session 05

## A simple matrix design

Write a `class Matrix` that should be template on the element type. Implement the following:
- copy and move semantics
- `operator[]` that throws no exceptions
- `at()` function that checks the validity of the element
- `operator()(const std::size_t i, const std::size_t j)` that uses `at` when **not** compiled with `-DNDEBUG` and uses `operator[]` when compiled with `-DNDEBUG`
- `operator+`
- `operator<<`