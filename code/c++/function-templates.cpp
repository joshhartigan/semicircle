// this is a useless program.
// it's sole purpose is to help me get to grips with
// templates and generic programming (or at least the basics)

#include <iostream>

// Returns which object x or y is bigger,
// according to C++'s `>` operator.
template <typename T>
bool bigger(T x, T y) {
  return x > y ? true : false;
}

// a stupid function:
//   @param object
//   @return object
template <typename T>
auto give(T object) -> T {
  return object;
}

int main() {

  std::cout << give( bigger(5, 2) ) << std::endl;
  std::cout << give( bigger("josh", "bob") ) << std::endl;

}

