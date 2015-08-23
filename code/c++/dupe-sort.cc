/**
 * dupe-sort: 'Sort' a vectors of numbers by creating a new vector.
 */

#include <iostream>
#include <vector>
using std::vector;

vector<int> dupe_sort( vector<int> v ) {
  vector<int> sorted( v.size() );
  for (auto i : v) {
    sorted[i - 1] = i;
  }

  return sorted;
}

void print_ints( vector<int> v ) {
  for (auto i : v) {
    std::cout << i << ", ";
  }
}

int main() {

  vector<int> v = { 3, 9, 2, 7, 4, 1, 6, 5, 8, 10 };
  auto sorted_v = dupe_sort(v);
  print_ints(v);
  std::cout << "-> ";
  print_ints(sorted_v);
  std::cout << std::endl;

  vector<int> w = { 3, 9, 1, 8, 4, 5, 2, 6, 10, 7 };
  auto sorted_w = dupe_sort(w);
  print_ints(w);
  std::cout << "-> ";
  print_ints(sorted_w);
  std::cout << std::endl;

}

