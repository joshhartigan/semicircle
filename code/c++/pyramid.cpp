#include <iostream>

using namespace std;

void PrintPyramid(int height) {
  int const kMargin = 10;

  cout << "\n";

  for (int line = 1; line <= height; line++) {
    int number_of_spaces = kMargin + height - line;
    for (int space = 1; space <= number_of_spaces; space++) {
      cout << " ";
    }
    for (int star = 0; star <= line * 2; star++) {
      cout << "*";
    }
    cout << "\n";
  }

  cout << "\n";
}

int main() {
  int pyramid_height;
  cout << "Height of pyramid? (1 -> 25) - ";
  cin >> pyramid_height;
  while (pyramid_height > 25 || pyramid_height < 1) {
    cout << "Height of pyramid? (1 -> 25) - ";
    cin >> pyramid_height;
  }

  PrintPyramid(pyramid_height);

  return 0;
}
