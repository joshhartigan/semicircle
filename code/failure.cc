#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;   using std::endl;
using std::vector; using std::map;
using std::string;

/*  A* - 90
    A  - 80
    B  - 65
    C  - 40
    D  - 20  */

map<float, string> determine_grades(vector<float> scores) {
  map<float, string> grades;

  for (float score : scores) {
    if (score >= 90) {
      grades[score] = "A*";
    } else if (score >= 80) {
      grades[score] = "A";
    } else if (score >= 65) {
      grades[score] = "B";
    } else if (score >= 40) {
      grades[score] = "C";
    } else if (score >= 20) {
      grades[score] = "D";
    } else {
      grades[score] = "F";
    }
  }

  return grades;
}

void print_floatstring_map(map<float, string> m) {
  typedef map<float, string>::const_iterator MapIterator;

  for (MapIterator iter = m.begin(); iter != m.end(); iter++) {
    cout << iter->first << " -> " << iter->second << endl;
  }
}

int main() {
  vector<float> scores = {
    45.6, 90.8, 63.8, 32.1, 19.6, 100, 24.8
  };

  map<float, string> grades = determine_grades(scores);

  print_floatstring_map(grades);
}
