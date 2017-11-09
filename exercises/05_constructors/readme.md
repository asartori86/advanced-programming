# Exercises - session 05

## A simple matrix design

Write a `class Matrix` that should be template on the element type. Implement the followings:
- copy and move semantics
- `operator[](const std::size_t i)` that throws no exceptions
- `at(const std::size_t i, const std::size_t j)` function that checks the validity of the element
- `operator()(const std::size_t i, const std::size_t j)` that uses `at` when **not** compiled with `-DNDEBUG` and uses `operator[]` when compiled with `-DNDEBUG`
- `operator<<`
- binary `operator+` to sum two matrices
- binary `operator*` to multiply two matrices