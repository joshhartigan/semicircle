#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::endl;
using std::cout;

// remove all instances of `target` from `container`, returning
// a new vector of all the extracted `target`s.
vector<int> extract_ints( vector<int> &container, int target );

int main() {

  vector<int> v = {4, 76, 4, 3, 78, 19, 8, 4};
  auto e = extract_ints(v, 4);

  for (auto iv : v) {
    cout << iv << ", ";  // => 76, 3, 78, 19, 8,
  }

  cout << endl;

  for (auto ev : e) {
    cout << ev << ", "; // => 4, 4, 4,
  }

  cout << endl;

  return 0;

}

vector<int> extract_ints( vector<int> &container, int target ) {
  vector<int> extractions;

  for ( int i = 0; i < container.size(); ++i ) {
    if ( container[i] == target ) {
      extractions.push_back( container[i] );
      container.erase( container.begin() + i );
    }
  }

  return extractions;

}

