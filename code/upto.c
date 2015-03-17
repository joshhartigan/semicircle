#include <stdio.h>

#define upto(x, y) for (int x = 0; x < y; ++x)

int main() {
  int numbers[] = { 3, 6, 2, 9, 8, 1, 0, 4, 5 };
  int length = sizeof(numbers) / sizeof(int);

  upto(i, length) {
    printf("%d ", numbers[i]);
  }
}
